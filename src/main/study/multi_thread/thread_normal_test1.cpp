//
// Created by 娄宇庭 on 2018/12/20.
//

#include "../util/util.h"
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
using namespace std;

void thread_func(){
    for(int i=0; i<100000; i++);
    cout<<"thread id is:" << std::this_thread::get_id() <<"\n";
    for(int i=0; i<100000; i++);
}

void thread_func_2(int x, string str){
    for(int i=0; i<100000; i++);
    cout<<"worker thread id is:" << std::this_thread::get_id() <<endl;
    cout<<"thread x:" << x <<endl;
    cout<<"thread str:" << str <<endl;
    for(int i=0; i<100000; i++);
}

void thread_func_ptr(string* ps){
    for(int i=0; i<100000; i++);
    cout<<"worker thread id is:" << std::this_thread::get_id() <<endl;
    cout<<"worker thread ps address:" << ps <<endl;
    cout<<"worker thread *ps:" << *ps <<endl;
    std::chrono::milliseconds dura( 10000 );
    std::this_thread::sleep_for( dura );
    *ps = "20";
    cout << "worker thread finished!" << endl;
}

void thread_vector_impl_pool_test1()
{
    vector<thread> thread_pool;
    thread_pool.reserve(10);
    for (int j = 0; j < 10; ++j) {
        thread_pool.emplace_back(thread(thread_func));
    }
    cout<<"Waiting all worker threads finished!"<<"\n";
    for (int j = 0; j < 10; ++j) {
        thread_pool[j].join();
    }
    for(int i=0; i<100000; i++);
    cout<<"all worker threads has finished, exiting main thread!"<<"\n";
}

void thread_created_with_args_test1()
{
    thread t1(thread_func_2, 10, "test");
    if(t1.joinable()){
        t1.join();
    }
    for(int i=0; i<100000; i++);
    cout<<"worker thread has finished, exiting main thread!"<<endl;
}

void thread_created_with_args_ptr_test1()
{
    string str = "10";
    std::cout<<"Inside Main Thread, str = "<< str <<std::endl;
    std::thread t(thread_func_ptr, &str);
    t.detach();
    std::chrono::milliseconds dura( 3000 );
    std::this_thread::sleep_for( dura );
    std::cout<<"Inside Main Thread, str = "<< str <<std::endl;
}

/**
 * Creating a thread using Function Objects
 * @return
 */
int main()
{
    cout << "/********************thread_vector_impl_pool_test1()**********************/" << endl;
    thread_vector_impl_pool_test1();
    cout << "/********************thread_created_with_args_test1()**********************/" << endl;
    thread_created_with_args_test1();
    cout << "/********************thread_created_with_args_ptr_test1()**********************/" << endl;
    thread_created_with_args_ptr_test1();
    return 0;
}
