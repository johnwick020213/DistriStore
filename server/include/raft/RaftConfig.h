#ifndef RAFT_CONFIG_H
#define RAFT_CONFIG_H

#include <string>
#include <vector>

// Raft配置类，包含Raft算法的配置信息
class RaftConfig {
public:
    // 构造函数，初始化配置
    RaftConfig(const std::string& configFilePath);

    // 加载配置文件
    bool loadConfig();

    // 获取节点地址列表
    std::vector<std::string> getNodeAddresses() const;

    // 获取选举超时时间
    int getElectionTimeout() const;

    // 获取心跳间隔时间
    int getHeartbeatInterval() const;

private:
    std::string configFilePath; // 配置文件路径
    std::vector<std::string> nodeAddresses; // 节点地址列表
    int electionTimeout; // 选举超时时间
    int heartbeatInterval; // 心跳间隔时间
};

#endif // RAFT_CONFIG_H

