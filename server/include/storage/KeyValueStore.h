#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H

#include <string>
#include <unordered_map>

// 键值存储类，用于存储键值对
class KeyValueStore {
public:
    // 设置键值对
    void set(const std::string& key, const std::string& value);

    // 获取键值对
    std::string get(const std::string& key) const;

    // 删除键值对
    void remove(const std::string& key);

private:
    std::unordered_map<std::string, std::string> store; // 键值存储容器
};

#endif // KEY_VALUE_STORE_H

