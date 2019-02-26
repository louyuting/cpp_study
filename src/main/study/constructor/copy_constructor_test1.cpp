//
// Created by 娄宇庭 on 2019/2/24.
//
#include <iostream>
#include <string>
#include <typeinfo>


/**
 * 验证初始化的书序
 */
using namespace std;

class BaseTest1{
public:
    BaseTest1();
    BaseTest1(const BaseTest1& t1);
    BaseTest1& operator=(const BaseTest1& t1);
private:
    int a;
};

BaseTest1::BaseTest1()
{
    cout << "BaseTest1 Constructor" << endl;
    this->a = 0;
}

BaseTest1::BaseTest1(const BaseTest1 &t1)
{
    cout << "BaseTest1 Copy Constructor" << endl;
    this->a = t1.a;
}

BaseTest1& BaseTest1::operator=(const BaseTest1 &t1)
{
    cout << "BaseTest1 assignment" << endl;
    this->a = t1.a;
    return *this;
}

class BaseTest2
{
public:
    BaseTest2()
    {
        cout << "BaseTest2 Constructor" << endl;
        this->a = 0;
    }
    BaseTest2(const BaseTest2& t)
    {
        cout << "BaseTest2 Copy Constructor" << endl;
        this->a = t.a;
    }
    BaseTest2& operator=(const BaseTest2& t)
    {
        cout << "BaseTest2 assignment" << endl;
        this->a = t.a;
        return *this;
    }
private:
    int a;
};


class Test{
public:
    Test(BaseTest1& t1, BaseTest2& t2):test1(t1),test2(t2) {
        cout << "constructor Test(BaseTest1& t1, BaseTest2& t2)" << endl;
    }

    // copy constructor
    Test(Test& t){
        cout << "copy constructor Test!" <<endl;
        this->test1 = t.test1;
        this->test2 = t.test2;
    }
public:
    BaseTest2 test2;
    BaseTest1 test1;
};

Test getReturn()
{
    BaseTest1 test1;
    BaseTest2 test2;
    Test test(test1, test2);
    return test;
}


void test_const_lvalue(const Test& test) {
    cout << "Test class name:" << typeid(test).name() << endl;
}


int main(int argc, char* args[])
{
    BaseTest1 test1;
    BaseTest2 test2;
    Test test(test1, test2);


//    Test t = getReturn();

    cout << "=============test_const_lvalue function============" << endl;
    //
    test_const_lvalue(test);
    Test& test_ref = test;
    // 左值
    test_const_lvalue(test_ref);
}