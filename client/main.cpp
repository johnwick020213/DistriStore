#include "include/client/Client.h"

int main() {
    // 创建客户端实例
    Client client("127.0.0.1", 8080);

    // 发送请求并接收响应
    client.sendRequest("echo Hello, RPC!");

    return 0;
}

