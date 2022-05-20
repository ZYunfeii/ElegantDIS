#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QThread>
#include <QVariant>
#include <map>
#include "jsoncpp/json/json.h"
#include "pubsub.h"


namespace Ui {
class interface;
}
/*
模块名：分布式客户节点客户端界面
功能：完成客户节点日志信息显示和连接管理节点功能
输入：ip，port，管理节点命令cmd
输出：日志信息
参数注释：见模块内注释
调用注释：调用pubsub类产生客户节点对象
限制注释：无
异常结束注释：进程收到SIGTERM或SIGINT信号后退出
方法注释：见帮助文档
外部环境及资源注释：Linux Ubuntu18.04虚拟机、muduo网络库、boost库
*/
class interface : public QWidget
{
    Q_OBJECT

signals:
    void start_client_sig();
public slots:
    void handle_log_msg(QVariant);
    void handle_topic_update(QVariant topic_name, QVariant topic_data);
    void connect_hub();
    void handle_synpub();
    void update_pubsub_data_browser();

public:
    explicit interface(QWidget *parent = nullptr);
    ~interface();
private:
    void step_func(); // 仿真步进函数
    void init_func(); // 仿真初始化函数
    void topic_init();

    

private:
    Ui::interface *ui;
    QThread *thread_;
    pubsub::PubSubClient *pubsubclient_;
private:
    std::map<std::string, Json::Value> publish_topic_json_map_;
    std::map<std::string, Json::Value> subscribe_topic_json_map_;

    std::size_t syn_topic_count_; // 记录每一步仿真中已经更新的订阅话题数量
};

#endif // INTERFACE_H
