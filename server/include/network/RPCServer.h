#ifndef RPC_SERVER_H
#define RPC_SERVER_H

#include <string>
#include <functional>
#include <unordered_map>

// RPC服务器类，用于处理远程过程调用
class RPCServer {
public:
    // 构造函数，初始化RPC服务器
    RPCServer(const std::string& address, int port);

    // 注册RPC方法
    void registerMethod(const std::string& methodName, std::function<std::string(const std::string&)> handler);

    // 启动RPC服务
    void startService();

    // 停止RPC服务
    void stopService();

private:
    std::string address; // 网络地址
    int port;            // 端口号
    int socketFd;        // 套接字文件描述符

    // 存储方法名称和对应处理函数的映射
    std::unordered_map<std::string, std::function<std::string(const std::string&)>> methodHandlers;

    // 处理接收到的RPC请求
    std::string handleRequest(const std::string& request);
};

#endif // RPC_SERVER_H

