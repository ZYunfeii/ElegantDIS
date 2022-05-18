#include "hub.h"
#include "ui_hub.h"

Hub::Hub(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hub)
    , thread_(new QThread())
    , pubsubserver_(new pubsub::PubSubServer)
{
    ui->setupUi(this);
    connect(this, &Hub::start_server_sig, pubsubserver_, &pubsub::PubSubServer::start);
    connect(pubsubserver_, &pubsub::PubSubServer::log_msg, this, &Hub::handle_log_msg);
    pubsubserver_->moveToThread(thread_);
    thread_->start();
    emit start_server_sig();

    connect(this->pubsubserver_, &pubsub::PubSubServer::update_topic_sig, this, &Hub::update_topic_show);
    connect(ui->start_sim_button, &QPushButton::clicked, this, &Hub::step_cmd);

    connect(this->pubsubserver_, &pubsub::PubSubServer::step_over_sig, this, &Hub::handle_step_sig); // todo
}

void Hub::step_cmd(){
    if (pubsubserver_->server_->connections_.empty()) {
        handle_log_msg(QString("no simnode!"));
        return;
    }
    for (auto it = pubsubserver_->server_->connections_.begin(); it != pubsubserver_->server_->connections_.end(); it++){
        std::string cmd = "step\r\n";
        it->second->send(cmd);
    }
}

void Hub::handle_step_sig() {
    // todo
    handle_log_msg(QString("simnode step once over!"));
}

void Hub::handle_log_msg(QVariant msg){
    QString msg_rev = msg.value<QString>();
    ui->text_browser->append(msg_rev);
}

void Hub::update_topic_show(){
    ui->topic_browser->clear();
    for(auto it = pubsubserver_->topics_.begin(); it != pubsubserver_->topics_.end(); it++) {
        ui->topic_browser->append(QString::fromStdString(it->second.topic_));
    }
}

Hub::~Hub()
{
    delete ui;
}

