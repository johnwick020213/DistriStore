#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include "../../../server/include/network/NetworkHandler.h"

// 客户端类，用于与服务器通信
class Client {
public:
    // 构造函数，初始化客户端
    Client(const std::string& serverAddress, int serverPort);

    // 发送请求并接收响应
    void sendRequest(const std::string& request);

private:
    std::string serverAddress; // 服务器地址
    int serverPort;            // 服务器端口
    NetworkHandler networkHandler; // 网络处理器实例
};

#endif // CLIENT_H

