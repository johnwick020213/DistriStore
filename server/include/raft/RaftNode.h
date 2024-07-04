#ifndef RAFT_NODE_H
#define RAFT_NODE_H

#include <string>
#include <vector>
#include "RaftLog.h"

// 节点状态枚举类型
enum class NodeState {
    Follower,  // 跟随者
    Candidate, // 候选人
    Leader     // 领导者
};

// Raft节点类，表示集群中的一个节点
class RaftNode {
public:
    // 构造函数，初始化节点
    RaftNode(const std::string& address, int port);

    // 启动节点
    void start();

    // 停止节点
    void stop();

    // 接收来自其他节点的RPC请求
    std::string receiveRPC(const std::string& request);

private:
    std::string address; // 节点地址
    int port;            // 端口号
    NodeState state;     // 节点状态
    int currentTerm;     // 当前任期
    int votedFor;        // 投票给的候选人ID
    RaftLog log;         // 节点日志

    // 选举定时器
    void startElectionTimer();

    // 心跳定时器
    void startHeartbeatTimer();

    // 处理选举请求
    std::string handleVoteRequest(const std::string& request);

    // 处理追加日志请求
    std::string handleAppendEntries(const std::string& request);
};

#endif // RAFT_NODE_H

