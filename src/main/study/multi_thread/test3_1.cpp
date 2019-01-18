//
// Created by 娄宇庭 on 2018/12/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
using namespace std;

void thread_func(int x, string str){
    for(int i=0; i<100000; i++);
    cout<<"worker thread id is:" << std::this_thread::get_id() <<endl;
    cout<<"thread x:" << x <<endl;
    cout<<"thread str:" << str <<endl;
    for(int i=0; i<100000; i++);
}


/**
 * Carefully Pass Arguments to Threads
 *
 * @return
 */
int main(){
    thread t1(thread_func, 10, "test");
    if(t1.joinable()){
        t1.join();
    }
    for(int i=0; i<100000; i++);
    cout<<"worker thread has finished, exiting main thread!"<<endl;
    return 0;
}







