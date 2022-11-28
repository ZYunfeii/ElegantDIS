#include "../ElegantDISClient/codec.h"
#include "pubsub.h"


using namespace pubsub;

void PubSubClient::subscription(const string& topic, const string& content, Timestamp) {
    log(INFO, "topic update " + topic + "->" + content); 
    LOG_INFO("topic update %s -> %s", topic.data(), content.data());
    handle_topic_update(topic, content);
}

void PubSubClient::connection(PubSubClient *client) {
    if (client->connected()) {
        if (subscribe_topic_json_map_.empty()) {
            log(WARN, "There is no subscribed topics initialized!");
            LOG_WARN("There is no subscribed topics initialized!");
        }
        send(makeSendCmd(NODE_NAME, this->client_->name()));
        for (auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); ++it) {
            client->subscribe(it->first, std::bind(&PubSubClient::subscription,this, _1, _2, _3));
        }
    }
}

PubSubClient::PubSubClient(std::string node_name, std::string ip, uint16_t port) {
    ip_ = ip; 
    port_ = port;     
    node_name_ = node_name;
    syn_topic_count_ = 0;
    Log::Instance()->init(1, "./log", ".log", 1024);
}

void PubSubClient::start() {
    loop_ = new EventLoop;
    client_ = new TcpClient(loop_, InetAddress(ip_, port_), node_name_);
    client_->setConnectionCallback(std::bind(&PubSubClient::onConnection, this, _1));
    client_->setMessageCallback(std::bind(&PubSubClient::onMessage, this, _1, _2, _3));

    setConnectionCallback(std::bind(&PubSubClient::connection, this, _1));

    client_->connect();
    loop_->loop();
}

void PubSubClient::stop() {
    client_->disconnect();
}

bool PubSubClient::connected() const {
    return conn_ && conn_->connected();
}

bool PubSubClient::subscribe(const string& topic, const SubscribeCallback& cb) {
    subscribeCallback_ = cb;
    return send(makeSendCmd(SUB, topic));
}

void PubSubClient::unsubscribe(const string& topic) {  
    send(makeSendCmd(UNSUB, topic));
}


bool PubSubClient::publish(const string& topic, const string& content) {
    return send(makeSendCmd(PUB, topic, content));
}

void PubSubClient::onConnection(const TcpConnectionPtr& conn) {
    if (conn->connected()) {
        conn_ = conn;
        // FIXME: re-sub
        log(INFO, "connected!");
        LOG_INFO("connented successfully to admin.")
    }
    else {
        conn_.reset();
    }
    if (connectionCallback_) {
        connectionCallback_(this);
    }
}

void PubSubClient::onMessage(const TcpConnectionPtr& conn, muduo::net::Buffer* buf, Timestamp receiveTime) {
    ParseResult result = kSuccess;
    while (result == kSuccess) {
        string cmd;
        string topic;
        string content;
        result = parseMessage(buf, &cmd, &topic, &content);
        if (result == kSuccess) {
            if (cmd == getCmdStr(PUB) && subscribeCallback_) {
                // pub + " " + topic + "\r\n" + content + "\r\n"
                subscribeCallback_(topic, content, receiveTime);
            }
            if (cmd == getCmdStr(STEP)) {
                // step + " " + sim_time + "\r\n"
                step(content);
            }
            if (cmd == getCmdStr(INIT)) {
                init(content);
            }
            if (cmd == getCmdStr(SYN_PUB)) {
                handle_synpub();
            }
        }
        else if (result == kError) {
            conn->shutdown();
        }
    }
}

bool PubSubClient::send(const string& message) {
    bool succeed = false;
    if (conn_ && conn_->connected()) {
        conn_->send(message);
        succeed = true;
    }
    return succeed;
}

void PubSubClient::step(std::string& content) {
    log(INFO, "step cmd received!");
    static Json::Reader rd;
    Json::Value sim_time_json;
    rd.parse(content, sim_time_json);
    stepCallback_(sim_time_json["sim_time"].asDouble());
    send(makeSendCmd(STEP_OVER));
}

void PubSubClient::init(std::string& content) {
    log(INFO, "init cmd received!");
    log(INFO, content);
    LOG_INFO("init cmd received: %s", content.data());
    initCallback_(content);
    send(makeSendCmd(INIT_OVER));
}

void PubSubClient::handle_topic_update(const std::string& topic_name, const std::string& topic_data) {
    Json::Reader rd;
    Json::Value val_sub;
    rd.parse(topic_data, val_sub);
    subscribe_topic_json_map_[topic_name] = val_sub;
    if (++syn_topic_count_ == subscribe_topic_json_map_.size()) {  // 当所有订阅的话题都被更新后向管理节点发布同步完成指令
        syn_topic_count_ = 0;
        send(makeSendCmd(SYN_PUB_OVER));
    }
}

void PubSubClient::handle_synpub() {
    Json::FastWriter w;
    for(auto it = publish_topic_json_map_.begin(); it != publish_topic_json_map_.end(); ++it) {
        std::string json = w.write(it->second);
        publish(it->first, json);
    }
}

void PubSubClient::setPubTopic(const std::string& topic, Json::Value& val) {
    publish_topic_json_map_[topic] = val;
}

void PubSubClient::setSubTopic(const std::string& topic, Json::Value& val) {
    subscribe_topic_json_map_[topic] = val;
}

Json::Value& PubSubClient::getPubTopic(const std::string& topic, const std::string& data) {
    return publish_topic_json_map_[topic][data];
}

Json::Value& PubSubClient::getSubTopic(const std::string& topic, const std::string& data) {
    return subscribe_topic_json_map_[topic][data];
}
