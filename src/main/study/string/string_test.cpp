//
// Created by 娄宇庭 on 2018/12/13.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "start" << endl;
    string str1;
    string str2 = "str2";
    cout << str1 << endl;
    cout << str2 << endl;

    str1 = "我是娄宇庭";

    // 返回的是新的对象
    string str1_1 = str1.substr(0, 5);
    cout << str1_1 << endl;
    str1_1 += "add";
    cout << str1_1 << endl;
    cout << str1 << endl;
    cout << "===========================================" << endl;
    cout << str2.size() << endl;
    cout << str2.max_size() << endl;
    cout << str2[1] << endl;
    cout << str2.at(2) << endl;



    return 0;
}