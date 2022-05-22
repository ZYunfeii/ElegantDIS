#include "hub.h"
#include "ui_hub.h"

Hub::Hub(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hub)
    , thread_(new QThread())
    , pubsubserver_(new pubsub::PubSubServer)
    , node_step_over_count_(0)
    , node_synpub_over_count_(0)
    , total_sim_steps_(0)
    , max_sim_steps_(10)
    , node_init_over_count_(0)
    , setting_widget_(new SettingWidget)
{
    ui->setupUi(this);
    connect(ui->setting_button, &QAction::triggered, this, [&](){this->setting_widget_->show();});

    connect(this, &Hub::start_server_sig, pubsubserver_, &pubsub::PubSubServer::start);
    connect(ui->init_sim_button, &QPushButton::clicked, this, &Hub::init_cmd);
    connect(pubsubserver_, &pubsub::PubSubServer::log_msg, this, &Hub::handle_log_msg);
    pubsubserver_->moveToThread(thread_);
    thread_->start();
    emit start_server_sig();

    connect(this->pubsubserver_, &pubsub::PubSubServer::update_topic_sig, this, &Hub::update_topic_show);
    connect(ui->start_sim_button, &QPushButton::clicked, this, &Hub::step_cmd);
    connect(this->pubsubserver_, &pubsub::PubSubServer::step_over_sig, this, &Hub::handle_step_sig); 
    connect(this->pubsubserver_, &pubsub::PubSubServer::synpub_over_sig, this, &Hub::handle_synpub_sig);
    connect(this->pubsubserver_, &pubsub::PubSubServer::init_over_sig, this, &Hub::handle_initover_sig);

    // tree view init
    tree_model_ = std::make_shared<QStandardItemModel>(this);
    // process bar init
    ui->sim_process_bar->setValue(0);
    // log text browser init
    ui->text_browser->document()->setMaximumBlockCount(50);
    // sim browser init
    ui->sim_text_browser->document()->setMaximumBlockCount(50);
}

void Hub::init_cmd() {
    max_sim_steps_ = this->setting_widget_->get_max_steps(); // 从setting窗口获取仿真参数
    handle_sim_msg(QString("[Info] max sim steps:%1").arg(max_sim_steps_));
    if (pubsubserver_->server_->connections_.empty()) {
        handle_log_msg(QString("No simnode!"));
        return;
    }
    for (auto it = pubsubserver_->server_->connections_.begin(); it != pubsubserver_->server_->connections_.end(); it++){
        std::string cmd = "init\r\n";
        it->second->send(cmd);
    }
}

void Hub::step_cmd(){
    if (pubsubserver_->server_->connections_.empty()) {
        handle_log_msg(QString("No simnode!"));
        return;
    } else if (total_sim_steps_ > max_sim_steps_) {
        handle_sim_msg(QString("[Info]: Sim End!"));
        total_sim_steps_ = 0; // init the sim states
        return;
    }
    for (auto it = pubsubserver_->server_->connections_.begin(); it != pubsubserver_->server_->connections_.end(); it++){
        std::string cmd = "step\r\n";
        it->second->send(cmd);
    }
    handle_sim_msg(QString("[Info]:Current Steps:%1").arg(total_sim_steps_));
    ui->sim_process_bar->setValue(total_sim_steps_ / max_sim_steps_ * 100);
    total_sim_steps_++;
}

void Hub::handle_step_sig() {
    // todo
    node_step_over_count_++;
    if (node_step_over_count_ == pubsubserver_->server_->connections_.size()) { // 说明所有节点完成一步仿真
        for (auto it = pubsubserver_->server_->connections_.begin(); it != pubsubserver_->server_->connections_.end(); it++){
            std::string cmd = "synpub\r\n";
            it->second->send(cmd);
        }
    }
}

void Hub::handle_synpub_sig() {
    node_synpub_over_count_++;
    if (node_synpub_over_count_ == pubsubserver_->server_->connections_.size()) { // 所有节点完成话题更新
        node_step_over_count_ = 0; // 清零，准备计算下一步完成仿真的节点数量（同步）
        node_synpub_over_count_ = 0;
        step_cmd(); // 下一步仿真指令
    }
}

void Hub::handle_log_msg(QVariant msg){ // 显示日志信息
    QString msg_rev = msg.value<QString>();
    ui->text_browser->append(msg_rev);
}

void Hub::handle_sim_msg(QVariant msg){ // 显示仿真信息
    QString msg_rev = msg.value<QString>();
    ui->sim_text_browser->append(msg_rev);
}

void Hub::update_topic_show(){
    tree_model_->clear();
    tree_model_->setHorizontalHeaderLabels(QStringList()<<"Node IpPort"<<"Topics Subscribed");
    ui->topic_tree_view->setModel(tree_model_.get());
    ui->topic_tree_view->header()->resizeSection(0,150);
    ui->topic_tree_view->expandAll();
    for(auto it = pubsubserver_->server_->connections_.begin(); it != pubsubserver_->server_->connections_.end(); it++) {
        const InetAddress peer_address = it->second->peerAddress();
        QStandardItem *item = new QStandardItem(QString::fromStdString(peer_address.toIpPort()));
        tree_model_->appendRow(item);
        pubsub::ConnectionSubscription* connSub = boost::any_cast<pubsub::ConnectionSubscription>(it->second->getMutableContext());
        for(auto i = connSub->begin(); i != connSub->end(); i++){
            QStandardItem *sub_item_node = new QStandardItem;
            QStandardItem *sub_item_topic = new QStandardItem(QString::fromStdString(*i));
            QList<QStandardItem*> qlist = {sub_item_node, sub_item_topic};
            tree_model_->appendRow(qlist);
        }
    }
}

void Hub::handle_initover_sig() {
    if (++node_init_over_count_ == pubsubserver_->server_->connections_.size()) {
        node_init_over_count_ = 0;
        handle_sim_msg(QString("[Info] All nodes initialized!"));
    }
}

Hub::~Hub()
{
    delete ui;
}

