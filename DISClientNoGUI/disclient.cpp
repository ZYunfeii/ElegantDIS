#include "disclient.h"
DECLARE_string(ip);
DECLARE_int32(port);
DECLARE_string(node_name);

DisClient::DisClient() :
psclient_(new pubsub::PubSubClient(FLAGS_node_name, FLAGS_ip, FLAGS_port)),
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
    auto pub_topic = std::make_shared<transdata::Topic1>();
    auto sub_topic = std::make_shared<transdata::Topic1>();
    psclient_->setPubTopic("Topic1", pub_topic);
    psclient_->setSubTopic("Topic1", sub_topic);
}

void DisClient::init_func(std::string init_setting) {
    worker_->setting_init(init_setting); 
    // 这里设置发布对象初值 (任意指定，起到分配内存作用，其真实值会在step_func中计算得到)
    dynamic_cast<transdata::Topic1*>(psclient_->getPubTopic("Topic1").get())->set_id(0);
    dynamic_cast<transdata::Topic1*>(psclient_->getPubTopic("Topic1").get())->add_data(1.2);
    dynamic_cast<transdata::Topic1*>(psclient_->getPubTopic("Topic1").get())->add_data(2.2);

    // 这里设置订阅对象初值 (分布式仿真中发布对象的值由订阅对象计算而来，在第0步需要指定订阅对象初值)
    dynamic_cast<transdata::Topic1*>(psclient_->getSubTopic("Topic1").get())->set_id(3);
    dynamic_cast<transdata::Topic1*>(psclient_->getSubTopic("Topic1").get())->add_data(4.2);
    dynamic_cast<transdata::Topic1*>(psclient_->getSubTopic("Topic1").get())->add_data(5.2);   
}

void DisClient::step_func(double sim_time) {
    double sub_data_0 = dynamic_cast<transdata::Topic1*>(psclient_->getSubTopic("Topic1").get())->data(0);
    dynamic_cast<transdata::Topic1*>(psclient_->getPubTopic("Topic1").get())->set_data(0, sub_data_0 + 1);

    worker_->save(dynamic_cast<transdata::Topic1*>(psclient_->getSubTopic("Topic1").get())->data(0));
    worker_->add_steps();
}