#include "codec.h"
#include "pubsub.h"

using namespace pubsub;

void PubSubClient::subscription(const string& topic, const string& content, Timestamp) {
    emit log_msg(QString::fromStdString("[Topic Update] " + topic + "->" + content));
    emit update_topic_data(QString::fromStdString(topic), QString::fromStdString(content));
}

void PubSubClient::connection(PubSubClient *client) {
    if (client->connected()) {
        if (subscribe_topics_.empty()) {
            emit log_msg(QString("[Warning]: There is no subscribed topics initialized!"));
        }
        for (std::vector<string>::iterator it = subscribe_topics_.begin(); it != subscribe_topics_.end(); ++it) {
            client->subscribe(*it, std::bind(&PubSubClient::subscription,this, _1, _2, _3));
        }
    }
}

PubSubClient::PubSubClient() {
    qRegisterMetaType<QVariant>("QVariant");
    ip_ = "127.0.0.1"; 
    port_ = 9999;     
}

void PubSubClient::start() {
    loop_ = new EventLoop;
    client_ = new TcpClient(loop_, InetAddress(ip_, port_), "SimNode");
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
    string message = "sub " + topic + "\r\n";
    subscribeCallback_ = cb;
    return send(message);
}

void PubSubClient::unsubscribe(const string& topic)
{
    string message = "unsub " + topic + "\r\n";
    send(message);
}


bool PubSubClient::publish(const string& topic, const string& content) {
    string message = "pub " + topic + "\r\n" + content + "\r\n";
    return send(message);
}

void PubSubClient::onConnection(const TcpConnectionPtr& conn) {
    if (conn->connected()) {
        conn_ = conn;
        // FIXME: re-sub
        emit log_msg(QString("[Info] Connected!"));
    }
    else {
        conn_.reset();
    }
    if (connectionCallback_) {
        connectionCallback_(this);
    }
}

void PubSubClient::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime) {
    ParseResult result = kSuccess;
    while (result == kSuccess) {
        string cmd;
        string topic;
        string content;
        result = parseMessage(buf, &cmd, &topic, &content);
        if (result == kSuccess) {
            if (cmd == "pub" && subscribeCallback_) {
                subscribeCallback_(topic, content, receiveTime);
            }
            if (cmd == "step") {
                emit log_msg(QString("[Info] Step cmd received!"));
                stepCallback_();
                send("stepover\r\n");
                emit update_pubsub_data_sig();
            }
            if (cmd == "init") {
                emit log_msg(QString("[Info] Init cmd received!"));
                initCallback_();
                send("initover\r\n");
                emit update_pubsub_data_sig();
            }
            if (cmd == "synpub") {
                emit synpub_sig();
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
