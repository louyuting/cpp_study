#include <iostream>
#include <list>
#include <mutex>
#include <algorithm>
#include <thread>
#include <vector>
#include <assert.h>
#include "../../util/util.h"

using namespace std;


std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int some_val)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.emplace_back(some_val);
}

bool list_contains(int value_to_find)
{
    lock_guard<mutex> guard(some_mutex);
    std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

void funct()
{
    for (int i = 0; i < 10000; ++i) {
        add_to_list(i);
    }
}


void mutex_protect_shared_data_test1()
{
    cout << "------step1-----"<<endl;
    add_to_list(1);
    add_to_list(2);
    add_to_list(3);
    add_to_list(4);
    long long start1 = get_timestamp_micros();
    vector<thread> vt;
    vt.reserve(1000);
    for (int i = 0; i <1000 ; ++i) {
        vt.emplace_back(thread(funct));
    }
    for (auto idx = vt.begin(); idx != vt.end(); idx++) {
        idx->join();
    }
    long long end1 = get_timestamp_micros();
    cout << "1000thread test result count=" << some_list.size() <<"; time diff="<< end1-start1 << "us"<< endl;
    assert(some_list.size()==1000*10000+4);

    cout << "------step3-----"<<endl;
    long long start3 = get_timestamp_micros();
    list<int> l3;
    for (int j = 0; j <10000000 ; ++j) {
        l3.emplace_back(j);
    }
    long long end3 = get_timestamp_micros();
    cout << "single thread test result count=" << l3.size() <<"; time diff="<< end3-start3 << "us"<< endl;
    cout << "over" << endl;
}



int main()
{
    cout << "/*************************mutex_protect_shared_data_test1()*************************************/" << endl;
    mutex_protect_shared_data_test1();
}



