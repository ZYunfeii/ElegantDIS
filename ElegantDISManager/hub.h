#ifndef HUB_H
#define HUB_H

#include <QMainWindow>
#include <QThread>
#include <QStandardItemModel>

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
    void init_cmd();
    void handle_step_sig();
    void handle_sim_msg(QVariant);
    void handle_synpub_sig();

private:
    Ui::Hub *ui;
    std::shared_ptr<QStandardItemModel> tree_model_;

    QThread *thread_;
    pubsub::PubSubServer *pubsubserver_;

    std::size_t node_step_over_count_;     // 在每一步仿真中已经完成仿真的节点数量
    std::size_t node_synpub_over_count_;   // 在每一步仿真中已经完成话题更新的节点数量
    std::size_t total_sim_steps_;         // 总仿真步长
    std::size_t max_sim_steps_;            // 最大仿真步长
};
#endif // HUB_H
