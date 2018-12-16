//
// Created by 娄宇庭 on 2018/12/15.
//

#ifndef DEMO_AUTO_PTR_TEST_H
#define DEMO_AUTO_PTR_TEST_H

#include <iostream>

using namespace std;

class Test{
public:
    int m_a;
    Test(int a=0) : m_a(a){}

    ~Test(){
        cout << "Calling destructor" << endl;
    }
};


#endif //DEMO_AUTO_PTR_TEST_H
