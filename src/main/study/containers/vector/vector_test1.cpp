// Created by 娄宇庭 on 2018/12/13.
#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

#include "../common.h"

using namespace std;
using namespace chrono;

void normal_test1(){
    vector<string> vector1;

    vector1.emplace_back("test1");
    vector1.push_back("test2");
    vector1.push_back("test1");
    vector1.push_back("test3");

    cout << vector1.size() << endl;
    cout << vector1.max_size() << endl;

    vector1.pop_back();
    vector1.erase(vector1.begin()+1, vector1.begin()+3);

    // vector 遍历的三种方式
    for (int i = 0; i <vector1.size(); ++i) {
        cout << vector1[i] << endl;
    }
    cout << "====================" << endl;
    for (const string str : vector1){
        cout << str << endl;
    }
    cout << "====================" << endl;
    vector<string>::const_iterator iter = vector1.begin();
    for (; iter != vector1.end(); iter++){
        cout << *iter << endl;
    }

    cout << "size:" <<  vector1.size() << endl;
    cout << vector1.back() << endl;

    //vector 查找
    auto idx = find(vector1.begin(), vector1.end(), "test1111");
    if (idx == vector1.end()){
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
    }
}


/**
 * 获取时间戳，微秒 us
 * @return
 */
long long get_timestamp_micros() {
    system_clock::time_point start = system_clock::now();
//    time_t start_t = system_clock::to_time_t(start);
//    cout << start_t << endl;
    long long time = duration_cast<microseconds>(start.time_since_epoch()).count();
    return time;
}

/**
 * 测试swap函数的性能
 */
void vector_swap_performance_and_clear_func_test1(){
    vector<long> vec1;
    cout << "empty vector vec1.size = " << vec1.size() << endl;
    for (long i = 0; i < 1000; ++i) {
        vec1.emplace_back(i);
        if ( i%10000 == 0 ){
            //cout << "   vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
        }
    }
    cout << "vec1.size = " << vec1.size() << endl;

    vector<long> vec2;
    cout << "empty vector vec2.size = " << vec2.size() << endl;
    for (long i = 0; i < 1000; ++i) {
        vec2.emplace_back(i);
        if ( i%10000 == 0 ){
            //cout << "   vec2.size = " << vec2.size() << "; vec2.cap="<< vec2.capacity()<< endl;
        }
    }
    cout << "vec2.size = " << vec2.size() << endl;

    long long t1 = get_timestamp_micros();
    std::swap(vec1, vec2);
    long long t2 = get_timestamp_micros();
    cout << "t1="<<t1<<"; t2="<<t2<<"; diff=" << t2-t1 << "us" << endl;
    cout << "vec1.size:" << vec1.size() << "| vec1.capacity:"<< vec1.capacity() << endl;
    cout << "vec2.size:" << vec2.size() << "| vec2.capacity:"<< vec2.capacity() << endl;
    cout << "---------" << endl;


    vector<long> vec3;
    for (long i = 0; i < 1000; ++i) {
        vec3.emplace_back(i);
    }
    vector<long > vec4;
    for (long i = 0; i < 1000; ++i) {
        vec4.emplace_back(i);
    }
    vec4.clear();

    cout << vec4.size() << endl;
    cout << vec4.capacity() << endl;
    long long t3 = get_timestamp_micros();
    auto v4_beg = vec4.begin();
    for (long i =0; i< 1000; i++) {
        vec4.insert(v4_beg, vec3[i]);
        v4_beg++;
    }
    long long t4 = get_timestamp_micros();
    cout << "diff:" << t4-t3 << endl;
    cout << vec4.size() << endl;
    cout << vec3.size() << endl;
}


/**
 * 测试swap函数来实现清空vector的case
 * 测试assign函数实现赋值
 */
void vector_clear_assign_test1()
{
    vector<long> vec1;
    cout << "empty vector vec1.size = " << vec1.size() << endl;
    for (long i = 0; i < 1000; ++i) {
        vec1.emplace_back(i);
    }
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;

    cout << "---------" << endl;
    vector<long>().swap(vec1);
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;

    cout << "---------" << endl;
    vector<long> vec2;
    cout << "empty vector vec2.size = " << vec2.size() << endl;
    for (long i = 0; i < 1000; ++i) {
        vec2.emplace_back(i);
    }
    cout << "vec2.size = " << vec2.size() << "; vec2.cap="<< vec2.capacity() << endl;
    vec2.assign(1, 0);
    cout << "vec2.size = " << vec2.size() << "; vec2.cap="<< vec2.capacity() << endl;
    cout << "---------" << endl;
}


void vector_ptr_test1(){
    // 初始了100个元素，值为默认值，如果是对象就会调用默认构造函数
    vector<Test*> vec1(10);
    for (long i = 0; i < 10; ++i) {
        Test* t = new Test;
        vec1.emplace_back(t);
        cout << "vec1.size:" << vec1.size() << "| vec1.capacity:"<< vec1.capacity() << endl;
    }

    for (int j = 0; j < vec1.size(); ++j) {
        if (!vec1[j]){
            cout << "obj is nullptr" << endl;
        } else {
            cout << vec1[j] << endl;
        }
    }
}

void vector_reserve_test1(){
    cout << "----step1----"<< endl;
    vector<int> vec1;
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
    cout << "----step2----"<< endl;
    vec1.reserve(1010000);
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
    vec1.shrink_to_fit();
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
    cout << "----step3----"<< endl;
    for (int i = 0; i < 1000; ++i) {
        vec1.emplace_back(i);
    }
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
    for (int j = 0; j < 1000; ++j) {
        cout << vec1.at(j)<< endl;
    }
    cout << "----step4----"<< endl;
    vector<int>().swap(vec1);
    cout << "vec1.size = " << vec1.size() << "; vec1.cap="<< vec1.capacity() << endl;
}

int main()
{
    cout<< "/************vector_swap_performance_and_clear_func_test1()********************/" << endl;
    vector_swap_performance_and_clear_func_test1();
    cout<< "/************vector_clear_assign_test()********************/" << endl;
    vector_clear_assign_test1();
    cout<< "/************vector_reserve_test1()********************/" << endl;
    vector_reserve_test1();
    return 0;
}