.
├── client
│   ├── include                    # 客户端头文件目录
│   │   └── client                # 客户端特定的头文件
│   ├── main.cpp                   # 客户端主程序入口点
│   └── src                        # 客户端源文件目录
│       └── client                # 客户端特定的源文件
├── config.txt                     # 配置文件
├── README.md                      # 项目说明文档
└── server
    ├── CMakeLists.txt             # CMake构建脚本
    ├── include                    # 服务器端头文件目录
    │   ├── network               # 网络相关功能头文件目录
    │   │   ├── NetworkHandler.h  # 网络处理器头文件
    │   │   └── RPCServer.h       # RPC服务器头文件
    │   ├── raft                  # Raft一致性算法头文件目录
    │   │   ├── RaftConfig.h      # Raft配置头文件
    │   │   ├── RaftLog.h         # Raft日志头文件
    │   │   ├── RaftNode.h        # Raft节点头文件
    │   │   └── RaftServer.h      # Raft服务器头文件
    │   └── storage               # 存储相关功能头文件目录
    │       ├── KeyValueStore.h   # 键值存储头文件
    │       └── StorageServer.h   # 存储服务器头文件
    ├── main.c                     # 服务器端主程序入口点
    └── src                        # 服务器端源文件目录
        ├── network                # 网络相关功能源文件目录
        │   ├── NetworkHandler.cpp # 网络处理器实现文件
        │   └── RPCServer.cpp      # RPC服务器实现文件
        ├── raft                   # Raft一致性算法源文件目录
        │   ├── RaftConfig.cpp     # Raft配置实现文件
        │   ├── RaftLog.cpp        # Raft日志实现文件
        │   ├── RaftNode.cpp       # Raft节点实现文件
        │   └── RaftServer.cpp     # Raft服务器实现文件
        └── storage                # 存储相关功能源文件目录
            ├── KeyValueStore.cpp  # 键值存储实现文件
            └── StorageServer.cpp  # 存储服务器实现文件

