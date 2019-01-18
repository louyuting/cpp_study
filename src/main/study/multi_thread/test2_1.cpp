//
// Created by 娄宇庭 on 2018/12/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
using namespace std;

void thread_func(){
    for(int i=0; i<100000; i++);
    cout<<"thread id is:" << std::this_thread::get_id() <<endl;
    for(int i=0; i<100000; i++);
}


/**
 * join or detach
 *
 * @return
 */
int main(){
    vector<thread> thread_pool;
    for (int j = 0; j < 10; ++j) {
        thread_pool.push_back(thread(thread_func));
    }
    cout<<"Waiting all worker threads finished!"<<endl;
    for (int j = 0; j < 10; ++j) {
        thread_pool[j].join();
    }
    for(int i=0; i<100000; i++);
    cout<<"all worker threads has finished, exiting main thread!"<<endl;
    return 0;
}







