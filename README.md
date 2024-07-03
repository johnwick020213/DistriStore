project-root/
├── include/
│   ├── raft/
│   │   ├── RaftNode.h        # Raft节点的头文件
│   │   ├── RaftLog.h         # Raft日志的头文件
│   │   ├── RaftServer.h      # Raft服务器的头文件
│   │   └── RaftConfig.h      # Raft配置的头文件
│   ├── storage/
│   │   ├── KeyValueStore.h   # Key-Value存储接口的头文件
│   │   └── StorageServer.h   # 存储服务器的头文件
│   ├── network/
│   │   ├── NetworkHandler.h  # 网络处理器的头文件
│   │   └── RPCServer.h       # RPC服务器的头文件
│   └── client/
│       ├── ClientHandler.h   # 客户端处理器头文件
├── src/
│   ├── raft/
│   │   ├── RaftNode.cpp      # Raft节点的实现文件
│   │   ├── RaftLog.cpp       # Raft日志的实现文件
│   │   ├── RaftServer.cpp    # Raft服务器的实现文件
│   │   └── RaftConfig.cpp    # Raft配置的实现文件
│   ├── storage/
│   │   ├── KeyValueStore.cpp # Key-Value存储接口的实现文件
│   │   └── StorageServer.cpp # 存储服务器的实现文件
│   ├── network/
│   │   ├── NetworkHandler.cpp# 网络处理器的实现文件
│   │   └── RPCServer.cpp     # RPC服务器的实现文件
│   └── client/
│       ├── ClientHandler.cpp # 客户端处理器实现文件
├── tests/
│   ├── raft_tests/           # Raft算法的单元测试
│   ├── storage_tests/        # 存储模块的单元测试
│   └── integration_tests/    # 整合测试
├── main.cpp                  # 主程序入口文件
├── CMakeLists.txt            # CMake构建脚本
└── README.md                 # 项目说明文档

