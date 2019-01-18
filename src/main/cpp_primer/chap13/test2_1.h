//
// Created by 娄宇庭 on 2018/12/17.
//

#ifndef DEMO_TEST1_H
#define DEMO_TEST1_H

#include <iostream>

using namespace std;

//定义行为像值的类版本。 多个对象分别保存自己的指针对象和指向的地址
class HasPtr{
public:
    // 构造器动态分配自己的 string 副本。
    HasPtr(const string& s = string()) : ps(new string(s)), i(0){}
    //copy constructor, 对于ps指向的String，每个HasPtr都应该有自己的拷贝。
    HasPtr(const HasPtr& p):ps(new string(*p.ps)), i(p.i){}
    // 声明：赋值运算符重载
    HasPtr&operator=(const HasPtr&);
    // 析构器
    ~HasPtr(){
        delete ps;
    }
private:
    // 指针
    string* ps;
    int i;
};

//赋值运算符定义
HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    // 拷贝底层的string
    auto newp = new string(*rhs.ps);
    // 释放this->ps的旧内存
    delete this->ps;
    this->ps = newp;
    this->i = rhs.i;
    return *this;
}

#endif //DEMO_TEST1_H
