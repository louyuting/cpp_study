//
// Created by 娄宇庭 on 2018/12/16.
//

#ifndef DEMO_MEMBER_INITIALLIZATION_LIST_TEST_H
#define DEMO_MEMBER_INITIALLIZATION_LIST_TEST_H


#include <iostream>
using namespace std;

class Test1{
public:
    Test1();
    Test1(const Test1& t1);

    Test1&operator=(const Test1& t1);

private:
    int a;
};

Test1::Test1() {
    cout << "Test1 Constructor" << endl;
}

Test1::Test1(const Test1 &t1) {
    cout << "Test1 Copy Constructor" << endl;
    this->a = t1.a;
}

Test1& Test1::operator=(const Test1 &t1) {
    cout << "Test1 assignment" << endl;
    this->a = t1.a;
    return *this;
}


class Test2{
public:
    Test2(Test1& t1);
private:
    Test1 test1;
};
// copy constructor
Test2::Test2(Test1 &t1):test1(t1){
    //this->test1 = t1;
}


#endif //DEMO_MEMBER_INITIALLIZATION_LIST_TEST_H
