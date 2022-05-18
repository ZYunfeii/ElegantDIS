#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QThread>
#include <QVariant>
#include <map>
#include "pubsub.h"
#include "clienttopic.h"
namespace Ui {
class interface;
}

class interface : public QWidget
{
    Q_OBJECT

signals:
    void start_client_sig();
public slots:
    void handle_log_msg(QVariant);
    void handle_topic_update(QVariant topic_name, QVariant topic_data);
    void connect_hub();

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();
private:
    void step_func();
    void topic_init();

private:
    Ui::interface *ui;
    QThread *thread_;
    pubsub::PubSubClient *pubsubclient_;
private:
    std::vector<std::string> subscribe_topic_name_;
    std::vector<std::string> publish_topic_name_;
    std::map<std::string, ClientTopic> subscribe_topic_map_;
    std::map<std::string, ClientTopic> publish_topic_map_;
};

#endif // INTERFACE_H
