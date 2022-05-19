#ifndef PUBSUBSERVER_H
#define PUBSUBSERVER_H
#include <QObject>
#include <QVariant>

#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/TcpServer.h"

#include <map>
#include <set>
#include <stdio.h>

#include "codec.h"
#include "topic.h"

using namespace muduo;
using namespace muduo::net;

namespace pubsub {
typedef std::set<string> ConnectionSubscription;
class PubSubServer : public QObject{
    Q_OBJECT
public:
    PubSubServer();

signals:
    void log_msg(QVariant);
    void update_topic_sig();
    void step_over_sig();
    void init_over_sig();

public slots:
    void start();

private:
    void onConnection(const TcpConnectionPtr& conn);
    void onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime);
    void timePublish();
    void doSubscribe(const TcpConnectionPtr& conn, const string& topic);
    void doUnsubscribe(const TcpConnectionPtr& conn, const string& topic);
    void doPublish(const string& source, const string& topic, const string& content, Timestamp time);
    Topic &getTopic(const string& topic);

public:
    // the following paras are public, so we can use them in main thread.
    std::map<string, Topic> topics_;
    TcpServer *server_;
    EventLoop *loop_;
};

}

#endif // PUBSUBSERVER_H
