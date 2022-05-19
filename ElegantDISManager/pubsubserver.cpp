#include "pubsubserver.h"
using namespace pubsub;

PubSubServer::PubSubServer(){
    qRegisterMetaType<QVariant>("QVariant");
}

void PubSubServer::start() {
    loop_ = new EventLoop;
    server_ = new TcpServer(loop_, InetAddress(9999), "PubSubServer");

    server_->setConnectionCallback(std::bind(&PubSubServer::onConnection, this, _1));
    server_->setMessageCallback(std::bind(&PubSubServer::onMessage, this, _1, _2, _3));
    loop_->runEvery(5.0, std::bind(&PubSubServer::timePublish, this));

    server_->start();
    loop_->loop();
}

void PubSubServer::onConnection(const TcpConnectionPtr& conn) {
    if (conn->connected()) {
        conn->setContext(ConnectionSubscription());
    }
    else {
        const ConnectionSubscription& connSub = boost::any_cast<const ConnectionSubscription&>(conn->getContext());
        // subtle: doUnsubscribe will erase *it, so increase before calling.
        for (ConnectionSubscription::const_iterator it = connSub.begin(); it != connSub.end();) {
            doUnsubscribe(conn, *it++);
        }
    }
}

void PubSubServer::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime) {
    ParseResult result = kSuccess;
    while (result == kSuccess) { 
        string cmd;
        string topic;
        string content;
        result = parseMessage(buf, &cmd, &topic, &content); // 对buf中收到的字节流进行处理
        if (result == kSuccess) { // 处理到一个满足格式要求的指令
            if (cmd == "pub") {  // 如果指令是客户节点的发布指令
                doPublish(conn->name(), topic, content, receiveTime);
            }
            else if (cmd == "sub") { // 如果指令是客户节点的订阅指令
                doSubscribe(conn, topic);
            }
            else if (cmd == "unsub") { // 如果指令是客户节点的退订指令
                doUnsubscribe(conn, topic);
            }
            else if (cmd == "stepover") { // 如果指令是客户节点完成一步仿真指令
                emit step_over_sig(); // 发送信号使主线程采取相应动作
            }
            else if (cmd == "initover") {
                // todo
                // emit init_over_sig();
            }
            else if (cmd == "synpubover") {
                emit synpub_over_sig();
            }
            else {
                conn->shutdown(); // 否则关闭连接
                result = kError;
            }
        }
        else if (result == kError) {
            conn->shutdown();
        }
    }
}

void PubSubServer::timePublish() {
    Timestamp now = Timestamp::now();
    doPublish("internal", "utc_time", now.toFormattedString(), now);
}

void PubSubServer::doSubscribe(const TcpConnectionPtr& conn, const string& topic) {
    ConnectionSubscription* connSub = boost::any_cast<ConnectionSubscription>(conn->getMutableContext());
    connSub->insert(topic);
    getTopic(topic).add(conn);
    emit log_msg(QString::fromStdString("[Sub]:" + conn->name() + "->" + topic));
}

void PubSubServer::doUnsubscribe(const TcpConnectionPtr& conn, const string& topic) {
    LOG_INFO << conn->name() << " unsubscribes " << topic;
    getTopic(topic).remove(conn);
    // topic could be the one to be destroyed, so don't use it after erasing.
    ConnectionSubscription* connSub = boost::any_cast<ConnectionSubscription>(conn->getMutableContext());
    connSub->erase(topic);
    emit log_msg(QString::fromStdString("[Unsub]:" + topic)); // mark: in this time, the conn is removed! Do not use conn->name!!
}

void PubSubServer::doPublish(const string& source, const string& topic, const string& content,Timestamp time) {
    getTopic(topic).publish(content, time);
    emit log_msg(QString::fromStdString("[Pub]:" + source + "->" + topic + ":" + content));
    emit update_topic_sig();
}

Topic &PubSubServer::getTopic(const string& topic) {
    std::map<string, Topic>::iterator it = topics_.find(topic);
    if (it == topics_.end()) {
        it = topics_.insert(make_pair(topic, Topic(topic))).first;
    }
    return it->second;
}
