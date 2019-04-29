//
// Created by Yuting Lou on 2019-04-29.
//
#include <iostream>
#include <atomic>

using namespace std;

int main(){
    atomic_int atomicInt(10);
    bool rt = atomicInt.is_lock_free();
    string sr = rt?"true":"false";
    cout << sr << endl;
}














