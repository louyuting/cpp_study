//
// Created by Yuting Lou on 2019-01-15.
//
#include <chrono>
#include <iostream>

long get_timestamp_nanoseconds(){
    return std::chrono::duration_cast< std::chrono::nanoseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

int main(){
    long start = get_timestamp_nanoseconds();
    for (int i = 0; i < 1000000; ++i) {
    }
    long end = get_timestamp_nanoseconds();
    std::cout << "diff: " << end - start << std::endl;
}