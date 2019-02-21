//
// Created by Yuting Lou on 2019-01-12.
//
#include <iostream>
#include <thread>

using namespace std;

void test(){
    for (int i = 0; i < 100000000000000; ++i) {

    }
}


int main(){


    for (int i = 0; i <7 ; ++i) {
        thread t(test);
        t.detach();
    }

    std::this_thread::sleep_for(std::chrono::seconds(10000000000000));
    return 0;
}