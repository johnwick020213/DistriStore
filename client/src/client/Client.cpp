#include "../../include/client/Client.h"

// 构造函数，初始化客户端
Client::Client(const std::string& serverAddress, int serverPort)
    : serverAddress(serverAddress), serverPort(serverPort), networkHandler(serverAddress, serverPort) {}

// 发送请求并接收响应
void Client::sendRequest(const std::string& request) {
    if (networkHandler.sendData(serverAddress, serverPort, request)) {
        std::cout << "Sent request: " << request << std::endl;
        std::string response = networkHandler.receiveData();
        std::cout << "Received response: " << response << std::endl;
    } else {
        std::cerr << "Failed to send request" << std::endl;
    }
}

