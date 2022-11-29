#ifndef DISCLIENT_H
#define DISCLIENT_H

#include "pubsub.h"
#include "worker.h"
#include "gflags/gflags.h"
#include <string>
#include <unordered_map>

class DisClient {
public:
    DisClient();
    ~DisClient();
    void connect();

private:
    pubsub::PubSubClient* psclient_;
    Worker* worker_;
    void init_func(std::string init_setting);
    void step_func(double sim_time);
    void topic_init();
};

#endif