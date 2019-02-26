//
// Created by 娄宇庭 on 2018/12/17.
//

#include "shared_ptr_test3.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(){
    cout << "===================Start===================" << endl;
    /**
     * make_shared函数
     */
    // 创建一个智能指针，指向初值是42的int类型的数据。
    shared_ptr<int> p3 = make_shared<int>(42);
    // 创建一个智能指针，指向初值是"9999999999"的string类型的数据。
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // 创建一个智能指针，指向初值是0的int类型的数据。
    shared_ptr<int> p5 = make_shared<int>();
    // 创建一个智能指针，指向动态分配的空vector<string>
    auto p6 = make_shared<vector<string>>();

    /**
     * shared_ptr 智能指针的拷贝和赋值
     */
    // p指向的对象只有p一个引用着
    auto p = make_shared<int>(42);
    // 拷贝，p和q指向相同的对象，此对象有两个引用者
    auto q(p);
    cout << "p指向对象的引用个数：" << p.use_count() << endl;

    // r指向的int只有一个引用者。
    auto r = make_shared<int>(42);
    // 给r赋值，使它指向另外一个地址，
    // q指向的对象引用计数加一
    // r指向的对象引用计数减一
    // r原来指向的对象引用计数已经为0，会被自动释放
    r = q;

    cout << "===================StrBlog===================" << endl;
    StrBlog b1;
    StrBlog b2 = {"111", "222", "333"};
    b1 = b2;// assignment operator
    b2.push_back("444");

    cout <<"b1 size = :" <<  b1.size() << endl;
    cout <<"b2 size = :" <<  b2.size() << endl;
}

class Foo{

};

template <typename T>
shared_ptr<Foo> factory(T arg){
    // 这里由shared_ptr负责释放foo实例的内存
    return make_shared<Foo>(arg);
}














