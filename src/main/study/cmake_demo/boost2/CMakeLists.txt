cmake_minimum_required(VERSION 3.12)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 添加 math 子目录,
# 使用命令 add_subdirectory 指明本项目包含一个子目录 func，
# 这样 func 目录下的 CMakeLists.txt 文件和源代码也会被处理。
add_subdirectory(func)

add_executable(boost_main main.cpp)

# 添加链接库. 表明可执行文件 main 需要连接一个名为 fun_lib 的链接库 。
target_link_libraries(boost_main fun_lib)

