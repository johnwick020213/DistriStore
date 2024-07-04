cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Server)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 源文件
set(SOURCES
    src/network/NetworkHandler.cpp
    src/network/RPCServer.cpp
    #src/raft/RaftConfig.cpp
    #src/raft/RaftLog.cpp
    #src/raft/RaftNode.cpp
    #src/raft/RaftServer.cpp
    #src/storage/KeyValueStore.cpp
    #src/storage/StorageServer.cpp
)

# 可执行文件
add_executable(Server main.cpp ${SOURCES})

# 链接 pthread 库
target_link_libraries(Server pthread)

