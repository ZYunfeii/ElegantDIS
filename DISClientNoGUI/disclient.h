#ifndef DISCLIENT_H
#define DISCLIENT_H

#include "pubsub.h"
#include "worker.h"
#include <string>

class DisClient {
public:
    DisClient();
    ~DisClient();
    void connect();

private:
    pubsub::PubSubClient* psclient_;
    Worker* worker_;
    void topic_init();
    void init_func(std::string init_setting);
    void step_func(double sim_time);
};

#endif