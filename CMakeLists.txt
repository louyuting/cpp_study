cmake_minimum_required(VERSION 3.12)
project(cpp_study)

set(CMAKE_CXX_STANDARD 14)

find_package(BOOST REQUIRED)
if (Boost_FOUND)
    message("Found Boost")
endif ()
if(NOT Boost_FOUND)
    message("Not found Boost")
endif()
message("Boost_INCLUDE_DIRS-> ${Boost_INCLUDE_DIRS}")
message("Boost_LIBRARIES-> ${Boost_LIBRARIES}")
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})
#添加头文件搜索路径
include_directories(/usr/local/include/)
#添加库文件搜索路径
link_directories(/usr/local/lib/ /usr/lib/)

include_directories(src/main/study/common/)


add_executable(test src/main/study/test.cpp)

# basic
add_executable(basic_test1 src/main/study/basic/inline_test1.cpp)

# boost
add_executable(boost_demo src/main/study/boost/main.cpp)


# constructor
add_executable(copy_constructor_assignment_test1 src/main/study/constructor/copy_constructor_assignment_test1.cpp)
add_executable(copy_constructor_member_init_order_test1 src/main/study/constructor/copy_constructor_member_init_order_test1.cpp)


# containers
add_executable(study_array_test1 src/main/study/containers/array/container_array_test1.cpp)
add_executable(study_list_test1 src/main/study/containers/list/container_list_test1.cpp)
add_executable(study_vector_test1 src/main/study/containers/vector/vector_test1.cpp src/main/study/containers/common.h)
add_executable(study_map_test1 src/main/study/containers/map/map_test1.cpp src/main/study/containers/map/map_test1.h)




# object_oriended
add_executable(object_oriended_inheritance_test1 src/main/study/object_oriented/inheritance_test1.cpp)
add_executable(object_oriended_inheritance_test2 src/main/study/object_oriented/inheritance_test2.cpp)
add_executable(object_oriended_inheritance_test3 src/main/study/object_oriented/inheritance_test3.cpp)
add_executable(object_oriended_friend_test1 src/main/study/object_oriented/oo_friend_test1.cpp)
add_executable(object_oriended_virtual_test1 src/main/study/object_oriented/oo_virtual_LibMat.cpp)


# pass_paramter
add_executable(pass_paramter_test1 src/main/study/pass_paramter/pass_paramter_test1.cpp)


# study_rvalue_ref_move_forward
add_executable(study_rvalue_ref_move_forward_test1 src/main/study/rvalue_reference_move_forward/rvalue_reference_move_semantic_test.cpp)


# string
add_executable(study_string_test1 src/main/study/string/string_test1.cpp)
add_executable(study_stringstream_test1 src/main/study/string/stringstream_test.cpp)
add_executable(study_string_int_test1 src/main/study/string/string_int_test1.cpp)

# smart_ptr
add_executable(study_ptr_auto_test1 src/main/study/smart_ptr/auto_ptr_test1.cpp)

add_executable(study_ptr_shared_test1 src/main/study/smart_ptr/shared_ptr/shared_ptr_test1.cpp)
add_executable(study_ptr_shared_test2 src/main/study/smart_ptr/shared_ptr/shared_ptr_test2.cpp src/main/study/smart_ptr/shared_ptr/shared_ptr_test2.h)
add_executable(study_ptr_shared_test3 src/main/study/smart_ptr/shared_ptr/shared_ptr_test1.cpp src/main/study/smart_ptr/shared_ptr/shared_ptr_test3.h)
add_executable(study_ptr_unique_ptr_test1 src/main/study/smart_ptr/unique_ptr/unique_ptr_test1.cpp)
add_executable(study_ptr_unique_ptr_test2 src/main/study/smart_ptr/unique_ptr/unique_ptr_test2.cpp)


add_executable(study_multi_thread_test1_1 src/main/study/multi_thread/thread_normal_test1.cpp)
add_executable(study_multi_thread_test1_2 src/main/study/multi_thread/test1_2.cpp)
add_executable(study_multi_thread_test1_3 src/main/study/multi_thread/test1_3.cpp)
add_executable(study_multi_thread_test2_1 src/main/study/multi_thread/test2_1.cpp)
add_executable(study_multi_thread_test3_1 src/main/study/multi_thread/test3_1.cpp)
add_executable(study_multi_thread_test3_2 src/main/study/multi_thread/test3_2.cpp)
add_executable(study_multi_thread_test4_1 src/main/study/multi_thread/test4_1.cpp)


add_executable(study_time_test1 src/main/study/time/chrono_get_timestamp_test1.cpp)
add_executable(study_time_test2 src/main/study/time/chrono_test2.cpp)


