#include "disclient.h"

DisClient::DisClient() :
psclient_(new pubsub::PubSubClient("testnode", "127.0.0.1", 9999)),
worker_(new Worker) {
    worker_->set_dir_path("save_res");
    worker_->set_save_name("Topic1", "data");
    topic_init();
    psclient_->setStepCallback(std::bind(&DisClient::step_func, this, std::placeholders::_1));
    psclient_->setInitCallback(std::bind(&DisClient::init_func, this, std::placeholders::_1)); // set the init callback for simnode    
}

void DisClient::connect() {
    this->psclient_->start(); 
}

// 用户只需实现下面这三个函数
void DisClient::topic_init() {
    Json::Value val1, val2;
    val1["data"] = 2.0;
    val1["str"] = "zyf";

    val2["data"] = 3.3;
    val2["str"] = "zyf";

    psclient_->setPubTopic("Topic1", val1);
    psclient_->setSubTopic("Topic1", val2);
}

void DisClient::init_func(std::string init_setting) {
    worker_->setting_init(init_setting);
    psclient_->getSubTopic("Topic1", "data") = 0; // 对订阅的数据初始化（第一次step使用的是初始值而非更新值）
}

void DisClient::step_func(double sim_time) {
    psclient_->getPubTopic("Topic1", "data") = psclient_->getSubTopic("Topic1", "data").asDouble() + 1;

    worker_->save(psclient_->getSubTopic(worker_->get_topic_save_name(), worker_->get_data_save_name()));
    worker_->add_steps();
}