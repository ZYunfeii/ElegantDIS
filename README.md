# 关于本项目

本项目基于Muduo网络库实现Linux下分布式仿真系统。之后会持续更新，目前完成了一些分布式仿真的基本功能。

几句话概括分布式仿真系统：多台机器，每台机器有自己的运算逻辑，每台机器之间的输出与输入互相耦合（e.g. host1的输出为host2的输入），要求多台机器构成一个运算系统。

# 项目框架

![structure](./README.assets/structure.jpg)

# 项目效果展示

![](./README.assets/DIS2.gif)

## 管理节点

1. 日志显示栏
2. 仿真节点IP Port显示，订阅话题显示
3. 仿真显示栏
4. 开始按钮和初始化仿真节点按钮
   ![在这里插入图片描述](README.assets/88335df957d7410fbfaa240c11820425.png)

## 仿真节点（客户节点）

## GUI界面版本

1. 填入管理节点IP和Port后向管理节点进行连接；
2. 日志显示栏显示日志信息；
3. 保存仿真话题随时间变化数据功能；
4. 消息传递基于Json；

![在这里插入图片描述](README.assets/89326c5f108149988a9e75ad77db364f.png)

## 非GUI版本

实现了非GUI界面的客户节点（最小实现），在文件夹DISClientNoGUI下，不依赖QT。同时，对数据的传输采用protobuf3序列化，优化了一些代码结果。
proto文件生成：在proto/src文件夹下执行`protoc -I . --cpp_out=.. transdata.proto`

编译：1. `cd build` `cmake ..`  2. `make` 3.  `cd ..`

运行：`./build/DISClient --flagfile config.flags` （使用gflags配置参数，更改.flags文件即可改变配置）

![image-20221127154417489](./README.assets/image-20221127154417489.png)

# 项目配置

项目依赖:

1. muduo_base, muduo_net (Muduo网络库：https://github.com/chenshuo/muduo )
2. QT5（管理节点和GUI版本的客户节点需要）
3. Jsoncpp
4. pthread
5. gflags
6. protobuf3 (非GUI版本客户节点采用)

**Muduo库在编译前将net/TcpServer中的connections_改为public。**

测试系统：Ubuntu18.04

## qmake
**可使用qmake编译管理节点和GUI版本客户节点**
进入ElegantDISManager或者ElegantDISClient下build文件夹，执行：

```shell
qmake .. 
make debug
```
**可使用cmake编译非GUI版本客户节点**
在build文件夹下执行：
```shell
cmake .. 
make
```
完成编译。build目录下执行二进制文件即可。

## vscode一键编译

根据项目根目录下 `.vscode`配置运行即可。

# 项目原理

## 同步逻辑

总体逻辑图如下:

![image-20220520191503451](./README.assets/image-20220520191503451.png)

项目基于Muduo网络库，受其中examples/hub代码启发：

1. 客户端采用QT搭建，主线程负责显示，子线程用于网络监听和一系列指令接受与发布逻辑；
2. 客户节点通过回调绑定设置仿真步进函数和初始化函数；
3. 管理节点向已注册的节点发布步进命令和初始化命令（目前只支持这两种操作）；
3. 由于Topic的数据格式可能会较为复杂,因此统一采用JSON格式传递;

**仿真同步逻辑（该DIS系统的核心思想）:**
对于仿真节点，其在步进函数中需要做的是将订阅话题的数据用于输入，计算得到需要发布话题的新值。之后向管理节点发布`stepover`指令，管理节点设置变量记录当前仿真步接受到`stepover`的节点数量，当数量等于所注册的节点数量时，管理节点发布`synpub`指令给所有仿真节点，仿真节点接收到该指令后将需要发布的话题值发布，通过管理节点转送到订阅该话题的节点，节点更新订阅话题的值，同时节点需要记录每一步仿真中订阅话题已更新数量，当所有订阅话题都被更新后，仿真节点向管理节点发布`synpubover`指令。管理节点统计每一仿真步中接受到`synpubover`的数量，当其等于所注册节点数量时，说明所有节点都完成话题更新了，此时再次向所有节点发布step指令进行下一步仿真。该逻辑保证了仿真的同步和时序的正常。
逻辑：所有节点先仿真一步->所有节点发布话题新值->所有节点更新话题值->下一步仿真。如果在step过程中又pub，时序会混乱。

对于管理节点，其需要记录注册仿真节点的各种信息。由于Muduo网络库是基于事件触发的，下面给出当管理节点收到消息后的处理函数:

```Cpp
void PubSubServer::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime) {
    ParseResult result = kSuccess;
    while (result == kSuccess) { 
        string cmd;
        string topic;
        string content;
        result = parseMessage(buf, &cmd, &topic, &content); // 对buf中收到的字节流进行处理
        if (result == kSuccess) { // 处理到一个满足格式要求的指令
            if (cmd == getCmdStr(NODE_NAME)) {
                ConnectionSubscription* connSub = boost::any_cast<ConnectionSubscription>(conn->getMutableContext());
                connSub->insert(getCmdStr(NODE_NAME) + " " + content);
            } else if (cmd == getCmdStr(PUB)) {  // 如果指令是客户节点的发布指令
                doPublish(conn->name(), topic, content, receiveTime);
            }
            else if (cmd == getCmdStr(SUB)) { // 如果指令是客户节点的订阅指令
                doSubscribe(conn, topic);
            }
            else if (cmd == getCmdStr(UNSUB)) { // 如果指令是客户节点的退订指令
                doUnsubscribe(conn, topic);
            }
            else if (cmd == getCmdStr(STEP_OVER)) { // 如果指令是客户节点完成一步仿真指令
                emit step_over_sig(); // 发送信号使主线程采取相应动作
            }
            else if (cmd == getCmdStr(INIT_OVER)) {
                // todo
                emit init_over_sig();
            }
            else if (cmd == getCmdStr(SYN_PUB_OVER)) {
                emit synpub_over_sig();
            }
            else {
                conn->shutdown(); // 否则关闭连接
                result = kError;
            }
        }
        else if (result == kError) {
            conn->shutdown();
        }
    }
}
```

对于仿真节点，当有消息到来时的处理函数：

```Cpp
void PubSubClient::onMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp receiveTime) {
    ParseResult result = kSuccess;
    while (result == kSuccess) {
        string cmd;
        string topic;
        string content;
        result = parseMessage(buf, &cmd, &topic, &content);
        if (result == kSuccess) {
            if (cmd == getCmdStr(PUB) && subscribeCallback_) {
                // pub + " " + topic + "\r\n" + content + "\r\n"
                subscribeCallback_(topic, content, receiveTime);
            }
            if (cmd == getCmdStr(STEP)) {
                // step + " " + sim_time + "\r\n"
                step(content);
            }
            if (cmd == getCmdStr(INIT)) {
                init(content);
            }
            if (cmd == getCmdStr(SYN_PUB)) {
                handle_synpub();
            }
        }
        else if (result == kError) {
            conn->shutdown();
        }
    }
}
```

可以看到，当接收到step或者init命令时，程序将执行上层注册的回调函数。并向管理节点发布over指令。其中emit是为了让qt主线程相应并显示相关日志信息。

## 保存话题

采用在线保存的方式，即边仿真边保存，但io操作可能会拖垮主线程，采用线程池方式将数据存储操作打包提交给池，实现高效存储。