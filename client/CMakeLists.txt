cmake_minimum_required(VERSION 3.10)

# 项目名称
project(Client)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 包含目录
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/../server/include)

# 源文件
set(SOURCES
    src/client/Client.cpp
    ../server/src/network/NetworkHandler.cpp
)

# 可执行文件
add_executable(Client main.cpp ${SOURCES})

# 链接 pthread 库
target_link_libraries(Client pthread)

