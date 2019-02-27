# 查找当前目录下的所有源文件
# 并将名称保存到 FUN_LIB_DIR_SRCS 变量
aux_source_directory(. FUN_LIB_DIR_SRCS)

# 生成链接库，add_library 将目录中的源文件编译为静态链接库。
add_library (fun_lib ${FUN_LIB_DIR_SRCS})