#include "../../include/network/RPCServer.h"
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

RPCServer::RPCServer(const std::string& address, int port)
    : address(address), port(port), socketFd(-1) {}

void RPCServer::registerMethod(const std::string& methodName, std::function<std::string(const std::string&)> handler) {
    methodHandlers[methodName] = handler;
}

void RPCServer::startService() {
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(address.c_str());
    serverAddr.sin_port = htons(port);

    if (bind(socketFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        close(socketFd);
        return;
    }

    if (listen(socketFd, 5) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        close(socketFd);
        return;
    }

    std::cout << "RPC server started at " << address << ":" << port << std::endl;

    while (true) {
        int clientSocket = accept(socketFd, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }

        char buffer[1024];
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::string request(buffer);
            std::string response = handleRequest(request);
            send(clientSocket, response.c_str(), response.size(), 0);
        }

        close(clientSocket);
    }
}

void RPCServer::stopService() {
    if (socketFd != -1) {
        close(socketFd);
        socketFd = -1;
    }
}

std::string RPCServer::handleRequest(const std::string& request) {
    // 简单的协议解析，假设请求格式为 "methodName params"
    size_t pos = request.find(' ');
    std::string methodName = request.substr(0, pos);
    std::string params = request.substr(pos + 1);

    auto it = methodHandlers.find(methodName);
    if (it != methodHandlers.end()) {
        return it->second(params);
    } else {
        return "Error: Method not found";
    }
}

