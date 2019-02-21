//
// Created by 娄宇庭 on 2018/12/13.
//
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    cout << "====================start====================" << endl;

    stringstream ss("hahahahahaha");
    ss << "hello world1;";
    cout << ss.str() << endl;
    ss << "hello world2;";
    cout << ss.str() << endl;
    string co;
    ss >> co;
    cout << "co:"<< co << endl;
    cout << "====================end====================" << endl;
    ss.str("123456");
    cout << ss.str() << endl;
    return 0;
}