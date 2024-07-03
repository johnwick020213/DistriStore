cmake_minimum_required(VERSION 3.10)
project(DistributedStorageSystem)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(DistributedStorageSystem
    src/main.cpp
    src/node/Node.cpp
    src/network/NetworkCommunicator.cpp
)


