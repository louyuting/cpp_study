//
// Created by 娄宇庭 on 2018/12/17.
//

#ifndef DEMO_TEST1_H
#define DEMO_TEST1_H

#include <iostream>

using namespace std;

//定义行为像指针的类版本， 多个对象公用ps指针
class HasPtr{
public:
    // 构造器动态分配自己的 string 副本。
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)){}
    //copy constructor, 对于ps指向的String，每个HasPtr都应该有自己的拷贝。
    HasPtr(const HasPtr& p):ps(p.ps), i(p.i), use(p.use){++*use;}
    // 声明：赋值运算符重载
    HasPtr& operator=(const HasPtr&);
    // 析构器
    ~HasPtr();
private:
    //共享
    string* ps;
    int i;
    // 记录有多少个对象共享*ps成员
    size_t* use;
};

HasPtr::~HasPtr() {
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

//赋值运算符定义
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use;
    if (--*use == 0){
        delete ps;
        delete use;
    }
    // 共享指针数据域
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

#endif //DEMO_TEST1_H
