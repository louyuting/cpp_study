cmake_minimum_required(VERSION 3.12)
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)

project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

## boost
#set(BOOST_ROOT "/usr/local/include/boost")
##添加头文件搜索路径
#include_directories(/usr/local/include /usr/include/)
##添加库文件搜索路径
#link_directories(/usr/local/lib /usr/lib/)



# boost
add_executable(boost_main src/main/study/boost/main.cpp)


# constructor
#add_executable(constructor_copy_test1 src/main/study/constructor/copy_constructor_test1.cpp)
#
#
#add_executable(effective_07 src/main/study/object_oriented/inheritance_test1.cpp)
#
#
#add_executable(study_array src/main/study/containers/array/test.cpp)
#add_executable(study_forward_list src/main/study/containers/forward_list/test.cpp)
#add_executable(study_list src/main/study/containers/list/inheritance_test1.cpp)
#add_executable(study_vector src/main/study/containers/vector/test.cpp)
#
#
## pass_paramter
#add_executable(pass_paramter_test1 src/main/study/pass_paramter/pass_paramter_test1.cpp)
#
#
## src/main/study/string
#add_executable(study_string_test1 src/main/study/string/string_test1.cpp)
#add_executable(study_stringstream_test1 src/main/study/string/stringstream_test.cpp)
#
#
#
#
#add_executable(study_rvalue_ref_move_forward_test1 src/main/study/rvalue_reference_move_forward/rvalue_reference_move_semantic_test.cpp)
#
#
#
#
#add_executable(study_ptr_auto src/main/study/smart_ptr/auto_ptr_test.cpp)
#add_executable(study_ptr_shared1 src/main/study/smart_ptr/shared_ptr1.cpp)
#add_executable(study_ptr_shared2 src/main/study/smart_ptr/shared_ptr2.cpp)
#add_executable(study_ptr_unique_ptr_test  src/main/study/smart_ptr/unique_ptr_test.cpp)
#add_executable(study_ptr_unique_ptr_test2 src/main/study/smart_ptr/unique_ptr_test2.cpp)
#
#
#add_executable(study_multi_thread_test1_1 src/main/study/multi_thread/test1_1.cpp)
#add_executable(study_multi_thread_test1_2 src/main/study/multi_thread/test1_2.cpp)
#add_executable(study_multi_thread_test1_3 src/main/study/multi_thread/test1_3.cpp)
#add_executable(study_multi_thread_test2_1 src/main/study/multi_thread/test2_1.cpp)
#add_executable(study_multi_thread_test3_1 src/main/study/multi_thread/test3_1.cpp)
#add_executable(study_multi_thread_test3_2 src/main/study/multi_thread/test3_2.cpp)
#add_executable(study_multi_thread_test4_1 src/main/study/multi_thread/test4_1.cpp)
#
#
#add_executable(essential_chap3 src/main/study/template/template_stl_test1.cpp)
#add_executable(essential_chap4_member_initiallization_list_test src/main/study/constructor/member_initiallization_list_test.cpp)
#add_executable(essential_chap5_libmat src/main/study/object_oriented/oo_virtual_LibMat.cpp)
#add_executable(essential_chap6_01 src/main/study/template/template_test2.cpp)
#
#
#add_executable(cpp_primer_chap12_test1 src/main/study/smart_ptr/shared_ptr_test3.cpp)
#add_executable(cpp_primer_chap12_test3 src/main/study/smart_ptr/shared_ptr_test4.cpp)
#add_executable(cpp_primer_chap13_test1 src/main/study/constructor/copy_constructor_assignment_test1.cpp)
#add_executable(cpp_primer_chap15_test1 src/main/study/object_oriented/inheritance_test2.cpp)
#
#
