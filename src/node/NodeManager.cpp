#include "Node.h"
#include <vector>
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

class NodeManager {
public:
    // 构造函数
    NodeManager() {}
    
    // 添加节点
    void addNode(int id) {
        nodes.push_back(std::unique_ptr<Node>(new Node(id))); 
        std::cout << "Node " << id << " 已添加.\n";
    }
    
    // 启动所有节点
    void startAllNodes() {
        for (auto& node : nodes) {
            node->start();
        }
        std::cout << "所有节点已启动.\n";
    }
    
    // 停止所有节点
    void stopAllNodes() {
        for (auto& node : nodes) {
            node->stop();
        }
        std::cout << "所有节点已停止.\n";
    }
    
    // 监控节点状态
    void monitorNodes() {
        while (true) {
            for (const auto& node : nodes) {
                std::cout << "Node " << node->getId() << " 状态: " << (node->isRunning() ? "运行中" : "已停止") << "\n";
            }
            std::this_thread::sleep_for(std::chrono::seconds(5)); // 每5秒输出一次节点状态
        }
    }

private:
    // 存储节点的容器
    std::vector<std::unique_ptr<Node>> nodes;
};
