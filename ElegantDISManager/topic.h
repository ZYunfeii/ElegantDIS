#ifndef TOPIC_H
#define TOPIC_H
#include <map>
#include <set>
#include <stdio.h>
#include "muduo/base/Logging.h"
#include "muduo/net/EventLoop.h"
#include "muduo/net/TcpServer.h"
#include "codec.h"
using namespace muduo;
using namespace muduo::net;

namespace pubsub {

class Topic : public muduo::copyable
{
public:
    Topic(const string& topic)
        : topic_(topic)
    {
    }

    void add(const TcpConnectionPtr& conn)
    {
        audiences_.insert(conn);
        if (lastPubTime_.valid())
        {
            conn->send(makeMessage());
        }
    }

    void remove(const TcpConnectionPtr& conn)
    {
        audiences_.erase(conn);
    }

    void publish(const string& content, Timestamp time)
    {
        content_ = content;
        lastPubTime_ = time;
        string message = makeMessage();
        for (std::set<TcpConnectionPtr>::iterator it = audiences_.begin();
             it != audiences_.end();
             ++it)
        {
            (*it)->send(message);
        }
    }

private:

    string makeMessage()
    {
        return "pub " + topic_ + "\r\n" + content_ + "\r\n";
    }

public:
    string topic_;
    string content_;
    Timestamp lastPubTime_;
    std::set<TcpConnectionPtr> audiences_;
    
};

}


#endif // TOPIC_H
