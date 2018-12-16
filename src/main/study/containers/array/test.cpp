//
// Created by 娄宇庭 on 2018/12/13.
//

#include "test.h"

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main(){
    cout << "start array" << endl;

    array<string, 3> arr = {"1"};
    arr[1] = "2";
    arr[2] = "3";

    // 越界
    //arr[3] = "4";
//    arr[4] = "5";

//    arr.fill("2");
//    arr.fill("3");
//    arr.fill("4");
    cout << "start" << endl;
    for(const auto str : arr){
        cout << str << endl;
    }
    cout << "end" << endl;
    string d[3] = {"a0","a1","a2"};
    for(auto elem : d){
        cout << elem << endl;
    }
}