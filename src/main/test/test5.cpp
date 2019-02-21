//
// Created by Yuting Lou on 2019-01-15.
//
#include <chrono>
#include <iostream>


int main(){
    std::chrono::nanoseconds start = std::chrono::duration_cast< std::chrono::nanoseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::cout << start.count() << std::endl;

    for (int i = 0; i < 1000000; ++i) {
    }
    std::chrono::nanoseconds end = std::chrono::duration_cast< std::chrono::nanoseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::cout << end.count() << std::endl;

    std::cout << "diff: " << end.count() - start.count() << std::endl;
}