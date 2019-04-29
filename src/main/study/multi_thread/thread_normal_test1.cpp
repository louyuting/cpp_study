//
// Created by 娄宇庭 on 2018/12/20.
//
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>
#include <future>
#include <numeric>



using namespace std;

void thread_func(){
    cout<<"line2: thread function Executing"<<endl;
}


void thread_normal_test1()
{
    vector<thread> vec_threads;
    vec_threads.reserve(10);
    for (int j = 0; j < 10; ++j) {
        vec_threads.emplace_back(std::move(thread(thread_func)));
    }
    cout << "wait for all worker to finish" << endl;
    std::for_each(vec_threads.begin(), vec_threads.end(), std::mem_fn(&std::thread::join));
    std::cout<<"Exiting from Main Thread"<<std::endl;
}

void thread_normal_test2()
{
    thread t1(thread_func);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 100; ++i) {}
    t1.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
}

void thread_normal_test3()
{

    thread thread1(thread_func);
    for(int i = 0; i < 100; i++);
    cout<<"line1: Display From MainThread"<<endl;
    thread1.join();
    cout<<"line3: Exit of Main function"<<endl;
}

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
    auto len = end - beg;
    if (len < 1000)
        return std::accumulate(beg, end, 0);

    RandomIt mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                             parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

void thread_normal_test4()
{
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << endl;
}

/**
 * Creating a thread using Function Pointer
 *
 * @return
 */
int main(){
    cout<<"/************thread_normal_test1()********************/"<<endl;
    thread_normal_test1();
    cout<<"/************thread_normal_test2()********************/"<<endl;
    thread_normal_test2();
    cout<<"/************thread_normal_test3()********************/"<<endl;
    thread_normal_test3();
    cout<<"/************thread_normal_test4()********************/"<<endl;
    thread_normal_test4();
    return 0;
}







