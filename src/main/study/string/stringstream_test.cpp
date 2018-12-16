//
// Created by 娄宇庭 on 2018/12/13.
//
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    cout << "====================start====================" << endl;

    stringstream ss("hahahahahaha");
    cout << ss.str() << endl;
    cout << ss.str() << endl;
    cout << "====================end====================" << endl;
    ss.str("123456");
    cout << ss.str() << endl;
    return 0;
}