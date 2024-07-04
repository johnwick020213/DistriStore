#ifndef RAFT_LOG_H
#define RAFT_LOG_H

#include <vector>
#include <string>

// 日志条目结构体
struct LogEntry {
    int term;         // 任期号
    std::string data; // 日志数据
};

// Raft日志类，用于管理日志条目
class RaftLog {
public:
    // 添加日志条目
    void appendEntry(const LogEntry& entry);

    // 获取指定索引的日志条目
    LogEntry getEntry(int index) const;

    // 获取最后一个日志条目
    LogEntry getLastEntry() const;

    // 获取日志条目数量
    int getLogSize() const;

private:
    std::vector<LogEntry> logEntries; // 日志条目列表
};

#endif // RAFT_LOG_H

