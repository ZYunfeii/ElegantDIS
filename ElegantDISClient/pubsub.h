#ifndef PUBSUB_H
#define PUBSUB_H
#include <QObject>
#include <QVariant>
#include "muduo/net/TcpClient.h"
#include "muduo/net/EventLoop.h"

namespace pubsub {
using muduo::string;
using namespace muduo;
using namespace muduo::net;
// FIXME: dtor is not thread safe
class PubSubClient : public QObject{
    Q_OBJECT
public:
    typedef std::function<void (PubSubClient*)> ConnectionCallback;
    typedef std::function<void (const string& topic,
                                const string& content,
                                muduo::Timestamp)> SubscribeCallback;

    typedef std::function<void(void)> StepCallback; // step callback func

    PubSubClient();
signals:
    void log_msg(QVariant);
    void update_topic_data(QVariant topic_name, QVariant topic_data); // the signal which let interface update the subscribed data

public slots:
    void start();
    void stop();

public:
    bool connected() const;

    void setConnectionCallback(const ConnectionCallback& cb) {connectionCallback_ = cb;}
    void setStepCallback(const StepCallback& cb) {stepCallback_ = cb;}
    void setSubscribeTopics(std::vector<string> &topics) {subscribe_topics_ = topics;}

    bool subscribe(const string& topic, const SubscribeCallback& cb);
    void unsubscribe(const string& topic);
    bool publish(const string& topic, const string& content);

    std::string ip_;
    uint16_t port_;

private:
    void onConnection(const muduo::net::TcpConnectionPtr& conn);
    void onMessage(const muduo::net::TcpConnectionPtr& conn,
                   muduo::net::Buffer* buf,
                   muduo::Timestamp receiveTime);
    bool send(const string& message);

    void subscription(const string& topic, const string& content, Timestamp);
    void connection(PubSubClient *client);

    muduo::net::TcpClient *client_;
    muduo::net::TcpConnectionPtr conn_;
    ConnectionCallback connectionCallback_;
    SubscribeCallback subscribeCallback_;
    StepCallback stepCallback_;
    EventLoop *loop_;
    std::vector<std::string> subscribe_topics_;

};
}  // namespace pubsub

#endif // PUBSUB_H
