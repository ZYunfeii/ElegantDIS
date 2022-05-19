#include "interface.h"
#include "ui_interface.h"

#include <sstream>
template <class T>
static T string_to_num(const std::string& str)
{
    std::istringstream iss(str);
    T num;
    iss >> num;
    return num;
}
template <class T>
static std::string num_to_string(const T& num)
{
    std::stringstream ss;
    std::string str;
    ss << num;
    ss >> str;
    return str;
}

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
  , thread_(new QThread())
  , pubsubclient_(new pubsub::PubSubClient)
{
    ui->setupUi(this);
    connect(ui->connect_button, &QPushButton::clicked, this, &interface::connect_hub);
    connect(this, &interface::start_client_sig, pubsubclient_, &pubsub::PubSubClient::start);
    connect(pubsubclient_, &pubsub::PubSubClient::log_msg, this, &interface::handle_log_msg);
    connect(pubsubclient_, &pubsub::PubSubClient::update_topic_data, this, &interface::handle_topic_update);

    pubsubclient_->setStepCallback(std::bind(&interface::step_func, this)); // set the step callback for simnode
    pubsubclient_->setInitCallback(std::bind(&interface::init_func, this)); // set the init callback for simnode
    topic_init(); // init topic
    pubsubclient_->setSubscribeTopics(subscribe_topic_name_); // set topics subscribed
}

void interface::connect_hub() {
    this->pubsubclient_->ip_ = ui->ip_edit->text().toStdString();
    this->pubsubclient_->port_ = ui->port_edit->text().toUInt();
    pubsubclient_->moveToThread(thread_);
    thread_->start();
    emit start_client_sig();
}

void interface::handle_log_msg(QVariant msg){
    QString msg_rev = msg.value<QString>();
    ui->info_browser->append(msg_rev);
}

void interface::handle_topic_update(QVariant topic_name, QVariant topic_data) {
    std::string tmp_topic_name = topic_name.value<QString>().toStdString();
    double tmp_topic_data = string_to_num<double>(topic_data.value<QString>().toStdString());
    subscribe_topic_map_[tmp_topic_name].topic_data_ = tmp_topic_data;
}

void interface::step_func() {
    publish_topic_map_["Data3"].topic_data_ = subscribe_topic_map_["Data1"].topic_data_ + 2;
    publish_topic_map_["Data4"].topic_data_ = subscribe_topic_map_["Data2"].topic_data_ + 3;

    this->pubsubclient_->publish("Data3", num_to_string(publish_topic_map_["Data3"].topic_data_));
    this->pubsubclient_->publish("Data4", num_to_string(publish_topic_map_["Data4"].topic_data_));
}

void interface::init_func() {
    for (auto it = subscribe_topic_map_.begin(); it != subscribe_topic_map_.end(); it++) {
        it->second.topic_data_ = 0;
    }
}

void interface::topic_init() {
    this->subscribe_topic_name_ = std::vector<std::string>{"Data1", "Data2"};
    this->publish_topic_name_ = std::vector<std::string>{"Data3", "Data4"};
    for(auto &topic : subscribe_topic_name_) {
        this->subscribe_topic_map_.insert(std::make_pair(topic, ClientTopic(topic, 0)));
    }
    for(auto &topic : publish_topic_name_) {
        this->publish_topic_map_.insert(std::make_pair(topic, ClientTopic(topic, 0)));
    }
}

interface::~interface()
{
    delete ui;
}
