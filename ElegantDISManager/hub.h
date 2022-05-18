#ifndef HUB_H
#define HUB_H

#include <QMainWindow>
#include <QThread>

#include "pubsubserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Hub; }
QT_END_NAMESPACE

class Hub : public QMainWindow
{
    Q_OBJECT

public:
    Hub(QWidget *parent = nullptr);
    ~Hub();

signals:
    void start_server_sig();
public slots:
    void handle_log_msg(QVariant);
    void update_topic_show();
    void step_cmd();
    void handle_step_sig();

private:
    Ui::Hub *ui;

    QThread *thread_;
    pubsub::PubSubServer *pubsubserver_;

};
#endif // HUB_H
