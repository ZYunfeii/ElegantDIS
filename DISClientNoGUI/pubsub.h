#ifndef PUBSUB_H
#define PUBSUB_H

#include "muduo/net/TcpClient.h"
#include "muduo/net/EventLoop.h"

#include "jsoncpp/json/json.h"
#include "../CMD/command.h"
#include "../logger/log.h"
#include "gflags/gflags.h"
#include <iostream>

namespace pubsub {
using muduo::string;
using namespace muduo;
using namespace muduo::net;
// FIXME: dtor is not thread safe
class PubSubClient {
public:
    typedef std::function<void (PubSubClient*)> ConnectionCallback;
    typedef std::function<void (const string& topic,
                                const string& content,
                                muduo::Timestamp)> SubscribeCallback;

    typedef std::function<void(double)> StepCallback; // step callback func for top layer in DIS
    typedef std::function<void(std::string)> InitCallback; // init callback func for top layer in DIS

    PubSubClient(std::string node_name, std::string ip, uint16_t port);

public:
    bool connected() const;

    void setConnectionCallback(const ConnectionCallback& cb) {connectionCallback_ = cb;}
    void setStepCallback(const StepCallback& cb) {stepCallback_ = cb;}
    void setInitCallback(const InitCallback& cb) {initCallback_ = cb;}

    bool subscribe(const string& topic, const SubscribeCallback& cb);
    void unsubscribe(const string& topic);
    bool publish(const string& topic, const string& content);

    bool send(const string& message);
    void start();
    void stop();
    void setPubTopic(const std::string& topic, Json::Value& val);
    void setSubTopic(const std::string& topic, Json::Value& val);
    Json::Value& getPubTopic(const std::string& topic, const std::string& data);
    Json::Value& getSubTopic(const std::string& topic, const std::string& data);

    std::string ip_;
    uint16_t port_;
    std::string node_name_;

private:
    void onConnection(const muduo::net::TcpConnectionPtr& conn);
    void onMessage(const muduo::net::TcpConnectionPtr& conn,
                   muduo::net::Buffer* buf,
                   muduo::Timestamp receiveTime);

    void subscription(const string& topic, const string& content, Timestamp);
    void connection(PubSubClient *client);

    muduo::net::TcpClient *client_;
    muduo::net::TcpConnectionPtr conn_;
    ConnectionCallback connectionCallback_;
    SubscribeCallback subscribeCallback_;
    StepCallback stepCallback_;
    InitCallback initCallback_;
    EventLoop *loop_;
    std::vector<std::string> subscribe_topics_;

private:
    void step(std::string& content);
    void init(std::string& content);
    void handle_topic_update(const std::string& topic_name, const std::string& topic_data);
    void handle_synpub();
    std::map<std::string, Json::Value> publish_topic_json_map_;
    std::map<std::string, Json::Value> subscribe_topic_json_map_;
    std::size_t syn_topic_count_; // 记录每一步仿真中已经更新的订阅话题数量

};
}  // namespace pubsub

#endif