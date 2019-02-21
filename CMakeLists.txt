cmake_minimum_required(VERSION 3.12)
project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

# boost
set(BOOST_ROOT "/usr/local/include/boost")
#添加头文件搜索路径
include_directories(/usr/local/include)
#添加库文件搜索路径
link_directories(/usr/local/lib)


add_executable(demo src/main/test/main.cpp)

add_executable(effective_07 src/main/effective/num07/test.cpp)
add_executable(effective_08 src/main/effective/num08/test.cpp)
add_executable(effective_test src/main/effective/numtest/test.cpp)

add_executable(study_array src/main/study/containers/array/test.cpp)
add_executable(study_forward_list src/main/study/containers/forward_list/test.cpp)
add_executable(study_list src/main/study/containers/list/test.cpp)
add_executable(study_vector src/main/study/containers/vector/test.cpp)
add_executable(study_string src/main/study/string/stringstream_test.cpp)
add_executable(study_stringstream src/main/study/string/stringstream_test.cpp)


add_executable(study_ptr_auto src/main/study/ptr/auto_ptr_test.cpp)
add_executable(study_ptr_shared1 src/main/study/ptr/shared_ptr1.cpp)
add_executable(study_ptr_shared2 src/main/study/ptr/shared_ptr2.cpp)
add_executable(study_ptr_unique_ptr_test src/main/study/ptr/unique_ptr_test.cpp)


add_executable(study_multi_thread_test1_1 src/main/study/multi_thread/test1_1.cpp)
add_executable(study_multi_thread_test1_2 src/main/study/multi_thread/test1_2.cpp)
add_executable(study_multi_thread_test1_3 src/main/study/multi_thread/test1_3.cpp)
add_executable(study_multi_thread_test2_1 src/main/study/multi_thread/test2_1.cpp)
add_executable(study_multi_thread_test3_1 src/main/study/multi_thread/test3_1.cpp)
add_executable(study_multi_thread_test3_2 src/main/study/multi_thread/test3_2.cpp)
add_executable(study_multi_thread_test4_1 src/main/study/multi_thread/test4_1.cpp)


add_executable(essential_chap3 src/main/essential/chap3/chap3.cpp)
add_executable(essential_chap4_test1 src/main/essential/chap4/test1.cpp)
add_executable(essential_chap4_member_initiallization_list_test src/main/essential/chap4/member_initiallization_list_test.cpp)
add_executable(essential_chap5_libmat src/main/essential/chap5/LibMat.cpp)
add_executable(essential_chap6_01 src/main/essential/chap6/template_test.cpp)


add_executable(cpp_primer_chap7_test1 src/main/cpp_primer/chap7/test1.cpp)
add_executable(cpp_primer_chap12_test1 src/main/cpp_primer/chap12/test12_1.cpp)
add_executable(cpp_primer_chap12_test3 src/main/cpp_primer/chap12/test12_3.cpp)
add_executable(cpp_primer_chap13_test1 src/main/cpp_primer/chap13/test1.cpp)
add_executable(cpp_primer_chap15_test1 src/main/cpp_primer/chap15/test1.cpp)


