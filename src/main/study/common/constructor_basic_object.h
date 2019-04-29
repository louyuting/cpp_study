//
// Created by Yuting Lou on 2019-02-26.
//
/**
 * 主要是定义一些用于测试学习代码的基础类
 */
#ifndef CONSTRUCTOR_BASIC_OBJECT_H
#define CONSTRUCTOR_BASIC_OBJECT_H

#include <iostream>
#include <string>

using namespace std;
/**
 * 一个基础类，包含默认构造函数、拷贝构造/赋值函数，移动构造/赋值函数
 * 成员是一个string, 一个string*
 */
class HasStr
{
public:
    HasStr():str_name(string("")), p_str(new string(""))
    {
        cout << "empty constructor" << endl;
    }
    ~HasStr()
    {
        cout << "destructor" << endl;
        delete this->p_str;
    }
    HasStr(const string& str): str_name(str), p_str(new string(""))
    {
        cout << "has init value constructor" << endl;
    }
    //拷贝构造, 拷贝不改变左值，所以可以使用const定义
    HasStr(const HasStr& lvalue):str_name(lvalue.str_name)
    {
        cout << "copy constructor" << endl;
        // release old memory that the this->p_str point
        if (this->p_str != nullptr )
        {
            delete this->p_str;
        }
        this->p_str = new string(lvalue.get_content());
    }
    //拷贝赋值
    HasStr& operator=(const HasStr& hasStr)
    {
        cout << "operator=" << endl;
        if (this!=&hasStr){
            if (this->p_str != nullptr )
            {
                delete this->p_str;
            }
            this->str_name = hasStr.str_name;
            this->p_str = new string(hasStr.get_content());
        }
        return *this;
    }

    // 移动构造函数
    HasStr(HasStr&& rvalue):p_str(rvalue.p_str), str_name(rvalue.str_name)
    {

        cout << "move constructor" << endl;
        //将右值的指针置为 nullptr，可以安全执行析构。
        rvalue.p_str = nullptr;
    }
    // 移动赋值
    HasStr& operator=(HasStr&& rvalue) noexcept
    {
        this->str_name = rvalue.str_name;
        this->p_str = rvalue.p_str;
        rvalue.p_str = nullptr;
        return *this;
    }

    const string& get_content() const
    {
        return *p_str;
    }
public:
    string str_name;
    string* p_str;
};


#endif //CONSTRUCTOR_BASIC_OBJECT_H
