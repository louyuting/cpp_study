//
// Created by Yuting Lou on 2019-04-30.
//
#include <iostream>
#include <vector>
#include "../study/util/util.h"
using namespace std;

int main(){
    std::cout << "start" << std::endl;
    long long start = get_timestamp_micros();
    for (int j = 0; j < 3*1024; ++j) {
        vector<long long> v;
        v.reserve(1024*1024);
        for (long long i=0; i<1024*1024; i++)
        {
            v.emplace_back(i);
        }
    }
    long long end = get_timestamp_micros();
    cout << end-start << "us" << endl;
    std::cout << "end" << std::endl;
}