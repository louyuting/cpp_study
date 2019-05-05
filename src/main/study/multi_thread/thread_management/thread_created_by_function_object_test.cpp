//
// Created by 娄宇庭 on 2018/12/20.
//

#include <thread>
#include <iostream>
#include "../../util/util.h"

using namespace std;

class DisplayThread
{
public:
    void operator()(){
        for(int i = 0; i < 100000; i++);
        cout<<"line3: thread1 function Executing"<<endl;
    }
};

void thread_created_by_function_obj_test1()
{
    thread thread1((DisplayThread()));
    for(int i = 0; i < 10000; i++);
    cout<<"line1: Display From MainThread"<<endl;
    cout<<"line2: Waiting For Thread to complete"<<endl;
    thread1.join();
    cout<<"line4: Exit of Main function"<<endl;
}

void thread_created_by_function_obj_test2()
{
    thread thread1((DisplayThread()));
    for(int i = 0; i < 10000; i++);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout<<"line1: Display From MainThread"<<endl;
    cout<<"line2: Waiting For Thread to complete"<<endl;
    thread1.join();
    cout<<"line4: Exit of Main function"<<endl;
}

void thread_created_by_function_obj_test3()
{
    thread thread1((DisplayThread()));
    long long start = get_timestamp_micros();
    for(int i = 0; i < 1000000000; i++);
    long long end = get_timestamp_micros();
    cout << "execute 1 billion cost " << end-start << " us" << endl;
    cout<<"line1: Display From MainThread"<<endl;
    cout<<"line2: Waiting For Thread to complete"<<endl;
    thread1.join();
    cout<<"line4: Exit of Main function"<<endl;
}

/**
 * Creating a thread using Function Objects
 * @return
 */
int main()
{
    cout << "/********************thread_created_by_function_obj_test1()**********************/" << endl;
    thread_created_by_function_obj_test1();
    cout << "/********************thread_created_by_function_obj_test2()**********************/" << endl;
    thread_created_by_function_obj_test2();
    cout << "/********************thread_created_by_function_obj_test3()**********************/" << endl;
    thread_created_by_function_obj_test3();
    return 0;
}
