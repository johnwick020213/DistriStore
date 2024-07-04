#ifndef STORAGE_SERVER_H
#define STORAGE_SERVER_H

#include <string>
#include "KeyValueStore.h"

// 存储服务器类，用于处理存储相关的请求
class StorageServer {
public:
    // 构造函数，初始化存储服务器
    StorageServer();

    // 处理设置键值对请求
    std::string handleSetRequest(const std::string& key, const std::string& value);

    // 处理获取键值对请求
    std::string handleGetRequest(const std::string& key);

    // 处理删除键值对请求
    std::string handleRemoveRequest(const std::string& key);

private:
    KeyValueStore keyValueStore; // 键值存储实例
};

#endif // STORAGE_SERVER_H

