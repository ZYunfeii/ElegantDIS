#include "interface.h"
#include "ui_interface.h"

interface::interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::interface)
  , thread_(new QThread())
  , pubsubclient_(new pubsub::PubSubClient("SimNode")) // 节点名称
  , syn_topic_count_(0)
  , free_simulation_(0)
  , thread_pool_(new ThreadPool(4))
{
    ui->setupUi(this);
    connect(ui->connect_button, &QPushButton::clicked, this, &interface::connect_hub); // 连接管理节点
    connect(this, &interface::start_client_sig, pubsubclient_, &pubsub::PubSubClient::start); // 开始仿真
    connect(pubsubclient_, &pubsub::PubSubClient::log_msg, this, &interface::handle_log_msg); // 显示日志信息
    connect(pubsubclient_, &pubsub::PubSubClient::update_topic_data, this, &interface::handle_topic_update); // topic有新值需要更新
    connect(pubsubclient_, &pubsub::PubSubClient::synpub_sig, this, &interface::handle_synpub); // 发布topic新值
    connect(pubsubclient_, &pubsub::PubSubClient::update_pubsub_data_sig, this, &interface::update_pubsub_data_browser); // 更新topic显示栏
    connect(pubsubclient_, &pubsub::PubSubClient::init_msg, this, &interface::handle_init_msg); // 更新初始化信息显示栏

    pubsubclient_->setStepCallback(std::bind(&interface::step_func, this, std::placeholders::_1)); // set the step callback for simnode
    pubsubclient_->setInitCallback(std::bind(&interface::init_func, this, std::placeholders::_1)); // set the init callback for simnode
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

    ui->save_path->setText("./save_sim_trace/");
    ui->save_topic->setText("Topic1");
    ui->data_name->setText("data");

}


// 用户仿真步进函数 需要修改
void interface::step_func(double sim_time) {
    publish_topic_json_map_["Topic1"]["data"] = subscribe_topic_json_map_["Topic1"]["data"].asDouble() + 1;

    // 下面的不用改
    int sec = sim_time;
    int sss = (sim_time - sec) * 1000;
    ui->time_lcd->display(QString("%1:%2:%3.%4").arg(sec / 60 / 60, 2, 10, QChar('0'))
                        .arg(sec / 60, 2, 10, QChar('0')).arg(sec % 60, 2, 10, QChar('0'))
                        .arg(sss, 3, 10, QChar('0')));
    save();
    cur_sim_steps_++;
}


// 用户仿真初始化函数 需要修改
void interface::init_func(std::string init_setting) {
    setting_init(init_setting); // 这句是保存设置初始化 不需要用户改

    for (auto it = subscribe_topic_json_map_.begin(); it != subscribe_topic_json_map_.end(); it++) {
        it->second["data"] = 0;
    }
}

// 用户设置Topic 需要修改
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

// 下面的函数可以不修改  

void interface::setting_init(std::string init_setting) {
    // 将管理节点的初始化json指令转为Value
    Json::Reader rd;
    Json::Value init_val;
    rd.parse(init_setting, init_val);
    max_sim_steps_ = init_val["max_sim_steps"].asInt();
    free_simulation_ = init_val["free_simulation"].asBool();
    if (free_simulation_) save_cache_max_size_ = 100;
    else save_cache_max_size_ = max_sim_steps_ / 10; // 设置缓存水位线
    cur_sim_steps_ = 0;

    dir_path_ = ui->save_path->text().toStdString();
    topic_save_name_ = ui->save_topic->text().toStdString();
    data_save_name_ = ui->data_name->text().toStdString();
    std::string file_path = dir_path_ + topic_save_name_ + '-' + data_save_name_;
    pf_ = fopen(file_path.data(), "w+");
}

void interface::save_sim_trace(std::vector<Json::Value> val_save_vec) {
    for (auto &val_save : val_save_vec) {
        if (val_save.isDouble()) {
            char buf[256];
            sprintf(buf, "%.3lf\r\n", val_save.asDouble());
            fputs(buf, pf_);
        } else if (val_save.isString()) {
            fputs((val_save.asString() + "\r\n").data(), pf_);
        }
    }
    fflush(pf_);
}

void interface::save() {
    Json::Value val_save = subscribe_topic_json_map_[topic_save_name_][data_save_name_];
    save_cache_.push_back(val_save);
    if (save_cache_.size() >= save_cache_max_size_ || cur_sim_steps_ >= max_sim_steps_) {
        thread_pool_->AddTask(std::bind(&interface::save_sim_trace, this, save_cache_)); // 将IO任务扔进线程池
        save_cache_.clear();
    }
}

// 用户可以修改
void interface::connect_hub() {
    this->pubsubclient_->ip_ = ui->ip_edit->text().toStdString();
    this->pubsubclient_->port_ = ui->port_edit->text().toUInt();
    pubsubclient_->moveToThread(thread_);
    thread_->start();
    emit start_client_sig();
}

// 用户可以修改
void interface::handle_log_msg(QVariant msg){
    QString msg_rev = msg.value<QString>();
    ui->info_browser->append(msg_rev);
}

// 用户可以修改
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

// 用户不需要修改
void interface::handle_synpub() {
    Json::FastWriter w;
    for(auto it = publish_topic_json_map_.begin(); it != publish_topic_json_map_.end(); ++it) {
        std::string json = w.write(it->second);
        this->pubsubclient_->publish(it->first, json);
    }
}

void interface::handle_init_msg(QVariant init_info) {
    QString msg_rev = init_info.value<QString>();
    std::string init_json_str = msg_rev.toStdString();
    Json::Reader rd;
    Json::Value init_val;
    rd.parse(init_json_str, init_val);
    ui->init_info_browser->setText(QString::fromStdString(init_val.toStyledString()));
}


// 话题更新函数 用户不需要修改
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

interface::~interface()
{
    delete ui;
}
