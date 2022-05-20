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
  , syn_topic_count_(0)
{
    ui->setupUi(this);
    connect(ui->connect_button, &QPushButton::clicked, this, &interface::connect_hub);
    connect(this, &interface::start_client_sig, pubsubclient_, &pubsub::PubSubClient::start);
    connect(pubsubclient_, &pubsub::PubSubClient::log_msg, this, &interface::handle_log_msg);
    connect(pubsubclient_, &pubsub::PubSubClient::update_topic_data, this, &interface::handle_topic_update);
    connect(pubsubclient_, &pubsub::PubSubClient::synpub_sig, this, &interface::handle_synpub);

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
    subscribe_topic_map_[tmp_topic_name] = tmp_topic_data;
    if (++syn_topic_count_ == subscribe_topic_map_.size()) {  // 当所有订阅的话题都被更新后向管理节点发布同步完成指令
        std::string cmd = "synpubover\r\n";
        syn_topic_count_ = 0;
        pubsubclient_->send(cmd);
    }
}

void interface::step_func() {
    publish_topic_map_["Data1"] = subscribe_topic_map_["Data3"]+ 2;
    publish_topic_map_["Data2"] = subscribe_topic_map_["Data4"] + 3;

    update_pubsub_data_browser();
}

void interface::update_pubsub_data_browser() {
    ui->topic_pub_data_browser->clear();
    ui->topic_sub_data_browser->clear();
    ui->topic_pub_data_browser->append(QString("Topics Published"));
    ui->topic_sub_data_browser->append(QString("Topics Subscribed"));
    for(auto it = publish_topic_map_.begin(); it != publish_topic_map_.end(); ++it) {
        ui->topic_pub_data_browser->append(QString::fromStdString(it->first) + ":" + QString::number(it->second));
    }
    for (auto it = subscribe_topic_map_.begin(); it != subscribe_topic_map_.end(); it++) {
        ui->topic_sub_data_browser->append(QString::fromStdString(it->first) + ":" + QString::number(it->second));
    }
}

void interface::handle_synpub() {
    for(auto it = publish_topic_map_.begin(); it != publish_topic_map_.end(); ++it) {
        this->pubsubclient_->publish(it->first, num_to_string(it->second));
    }
}

void interface::init_func() {
    for (auto it = subscribe_topic_map_.begin(); it != subscribe_topic_map_.end(); it++) {
        it->second = 0;
    }
}

void interface::topic_init() {
    this->subscribe_topic_name_ = std::vector<std::string>{"Data3", "Data4"}; // 仿真输入
    this->publish_topic_name_ = std::vector<std::string>{"Data1", "Data2"};   // 仿真输出

    ui->topic_pub_data_browser->append(QString("Topics Published"));
    ui->topic_sub_data_browser->append(QString("Topics Subscribed"));
    for(auto &topic : subscribe_topic_name_) {
        this->subscribe_topic_map_.insert(std::make_pair(topic, 0));
        ui->topic_sub_data_browser->append(QString::fromStdString(topic) + ":");
    }
    for(auto &topic : publish_topic_name_) {
        this->publish_topic_map_.insert(std::make_pair(topic, 0));
        ui->topic_pub_data_browser->append(QString::fromStdString(topic) + ":");
    }

}

interface::~interface()
{
    delete ui;
}
