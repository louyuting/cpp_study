//
// Created by 娄宇庭 on 2018/12/20.
//
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
using namespace std;

void thread_func(string* ps){
    for(int i=0; i<100000; i++);
    cout<<"worker thread id is:" << std::this_thread::get_id() <<endl;
    cout<<"worker thread ps address:" << ps <<endl;
    cout<<"worker thread *ps:" << *ps <<endl;
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    *ps = "20";
}

void startNewThread() {
    string str = "10";
    std::cout<<"Inside Main Thread, str = "<< str <<std::endl;
    std::thread t(thread_func, &str);
    t.detach();
    std::chrono::milliseconds dura( 3000 );
    std::this_thread::sleep_for( dura );
    std::cout<<"Inside Main Thread, str = "<< str <<std::endl;
}


/**
 * not to pass address of variable from stack to thread
 *
 * @return
 */
int main(){
    startNewThread();
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    return 0;
}







