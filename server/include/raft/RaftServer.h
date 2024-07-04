#ifndef RAFT_SERVER_H
#define RAFT_SERVER_H

#include <vector>
#include "RaftNode.h"

// Raft服务器类，管理集群中的多个节点
class RaftServer {
public:
    // 构造函数，初始化服务器
    RaftServer(const std::vector<std::string>& nodeAddresses);

    // 启动服务器
    void start();

    // 停止服务器
    void stop();

    // 广播消息给所有节点
    void broadcastMessage(const std::string& message);

private:
    std::vector<RaftNode> nodes; // 集群中的节点列表
};

#endif // RAFT_SERVER_H

