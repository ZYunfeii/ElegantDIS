#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
  , thread_(new QThread())
  , pubsubclient_(new pubsub::PubSubClient)
  , syn_topic_count_(0)
{
    ui->setupUi(this);
    connect(ui->connect_button, &QPushButton::clicked, this, &interface::connect_hub); // 连接管理节点
    connect(this, &interface::start_client_sig, pubsubclient_, &pubsub::PubSubClient::start); // 开始仿真
    connect(pubsubclient_, &pubsub::PubSubClient::log_msg, this, &interface::handle_log_msg); // 显示日志信息
    connect(pubsubclient_, &pubsub::PubSubClient::update_topic_data, this, &interface::handle_topic_update); // topic有新值需要更新
    connect(pubsubclient_, &pubsub::PubSubClient::synpub_sig, this, &interface::handle_synpub); // 发布topic新值
    connect(pubsubclient_, &pubsub::PubSubClient::update_pubsub_data_sig, this, &interface::update_pubsub_data_browser); // 更新topic显示栏

    pubsubclient_->setStepCallback(std::bind(&interface::step_func, this, std::placeholders::_1)); // set the step callback for simnode
    pubsubclient_->setInitCallback(std::bind(&interface::init_func, this)); // set the init callback for simnode
    topic_init(); // init topic
    std::vector<std::string> sub_topics_name;
    for (auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); it++) {
        sub_topics_name.push_back(it->first);
    }
    pubsubclient_->setSubscribeTopics(sub_topics_name); // set topics subscribed

    // log text browser init
    ui->info_browser->document()->setMaximumBlockCount(50);
    // time lcd init
    ui->time_lcd->display("00:00:00.000");
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

    Json::Reader rd;
    Json::Value val_sub;
    rd.parse(topic_data.value<QString>().toStdString(), val_sub);
    subscribe_topic_json_map_[tmp_topic_name] = val_sub;

    if (++syn_topic_count_ == subscribe_topic_json_map_.size()) {  // 当所有订阅的话题都被更新后向管理节点发布同步完成指令
        std::string cmd = "synpubover\r\n";
        syn_topic_count_ = 0;
        pubsubclient_->send(cmd);
    }
}

void interface::step_func(double sim_time) {
    publish_topic_json_map_["Topic1"]["data"] = subscribe_topic_json_map_["Topic1"]["data"].asDouble() + 1;

    // 更新时间显示
    int sec = sim_time;
    int sss = (sim_time - sec) * 1000;
    ui->time_lcd->display(QString("%1:%2:%3.%4").arg(sec / 60 / 60, 2, 10, QChar('0'))
                        .arg(sec / 60, 2, 10, QChar('0')).arg(sec % 60, 2, 10, QChar('0'))
                        .arg(sss, 3, 10, QChar('0')));
}

void interface::update_pubsub_data_browser() {
    ui->topic_pub_data_browser->clear();
    ui->topic_sub_data_browser->clear();
    ui->topic_pub_data_browser->append(QString("Topics Published"));
    ui->topic_sub_data_browser->append(QString("Topics Subscribed"));
    for(auto it = publish_topic_json_map_.begin(); it != publish_topic_json_map_.end(); ++it) {
        ui->topic_pub_data_browser->append(QString::fromStdString(it->first));
        std::string json = it->second.toStyledString();
        ui->topic_pub_data_browser->append(QString::fromStdString(json));
    }
    for (auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); it++) {
        ui->topic_sub_data_browser->append(QString::fromStdString(it->first));
        std::string json = it->second.toStyledString();
        ui->topic_sub_data_browser->append(QString::fromStdString(json));
    }
}

void interface::handle_synpub() {
    Json::FastWriter w;
    for(auto it = publish_topic_json_map_.begin(); it != publish_topic_json_map_.end(); ++it) {
        std::string json = w.write(it->second);
        this->pubsubclient_->publish(it->first, json);
    }
}

void interface::init_func() {
    for (auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); it++) {
        it->second["data"] = 0;
    }
}

void interface::topic_init() {

    ui->topic_pub_data_browser->append(QString("Topics Published"));
    ui->topic_sub_data_browser->append(QString("Topics Subscribed"));

    Json::Value val1;
    val1["data"] = 2.0;
    val1["str"] = "zyf";
    publish_topic_json_map_["Topic1"] = val1;

    Json::Value val2;
    val2["data"] = 3.3;
    val2["str"] = "zyf";
    subscribe_topic_json_map_["Topic1"] = val2;

    for(auto it = publish_topic_json_map_.begin(); it != publish_topic_json_map_.end(); ++it) {
        ui->topic_pub_data_browser->append(QString::fromStdString(it->first));
        std::string json = it->second.toStyledString();
        ui->topic_pub_data_browser->append(QString::fromStdString(json));
    }
    for(auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); ++it) {
        ui->topic_sub_data_browser->append(QString::fromStdString(it->first));
        std::string json = it->second.toStyledString();
        ui->topic_sub_data_browser->append(QString::fromStdString(json));
    }
}

interface::~interface()
{
    delete ui;
}
