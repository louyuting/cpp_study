cmake_minimum_required(VERSION 3.12)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


#add_executable(boost_main main.cpp function.cpp)


add_executable(boost_main ${DIR_SRCS})

