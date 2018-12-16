//
// Created by 娄宇庭 on 2018/11/6.
//

#include "test.h"


int main(){

    Test a("a");
    Test& c = a;
    cout << a.name << endl;
    cout << c.name << endl;
    cout << &a << endl;
    cout << &c << endl;
}
