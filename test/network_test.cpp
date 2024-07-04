#include "../server/include/network/NetworkHandler.h"
#include "../server/include/network/RPCServer.h"
#include <iostream>
#include <thread>

// RPC方法示例
std::string echo(const std::string& params) {
    return "Echo: " + params;
}

void startServer() {
    // 创建并启动RPC服务器
    RPCServer server("127.0.0.1", 8080);
    server.registerMethod("echo", echo);
    server.startService();
}

void startClient() {
    // 等待服务器启动
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 创建网络处理器
    NetworkHandler client("127.0.0.1", 8080);

    // 发送数据并接收响应
    std::string request = "echo Hello, RPC!";
    if (client.sendData("127.0.0.1", 8080, request)) {
        std::cout << "Sent request: " << request << std::endl;
        std::string response = client.receiveData();
        std::cout << "Received response: " << response << std::endl;
    } else {
        std::cerr << "Failed to send request" << std::endl;
    }
}

int main() {
    // 启动服务器线程
    std::thread serverThread(startServer);

    // 启动客户端线程
    std::thread clientThread(startClient);

    // 等待线程完成
    serverThread.join();
    clientThread.join();

    return 0;
}

