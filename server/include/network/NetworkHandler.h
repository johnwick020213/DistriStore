#ifndef NETWORK_HANDLER_H
#define NETWORK_HANDLER_H

#include <string>
#include <vector>

// 网络处理器类，用于处理网络通信
class NetworkHandler {
public:
    // 构造函数，初始化网络处理器
    NetworkHandler(const std::string& address, int port);

    // 发送数据到指定地址和端口
    bool sendData(const std::string& address, int port, const std::string& data);

    // 接收数据
    std::string receiveData();

    // 启动网络服务
    void startService();

    // 停止网络服务
    void stopService();

private:
    std::string address; // 网络地址
    int port;            // 端口号
    int socketFd;        // 套接字文件描述符

    // 创建套接字并连接到指定地址和端口
    int createSocket(const std::string& address, int port);

    // 发送指定长度的数据
    int sendn(int socket, const char* buf, int len);

    // 接收指定长度的数据
    int recvn(int socket, char* buf, int len);
};

#endif // NETWORK_HANDLER_H

