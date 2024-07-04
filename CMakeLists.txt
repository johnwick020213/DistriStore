cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(RaftProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加子目录
add_subdirectory(client)
add_subdirectory(server)

