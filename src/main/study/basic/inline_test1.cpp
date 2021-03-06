//
// Created by 娄宇庭 on 2018/12/19.
//
#include <iostream>
#include <string>

using namespace std;

class Screen {
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(string(ht*wd, c)){}
    // 隐式内联：在类里定义的成员函数默认会被认为是内联函数
    char get() const { return content[cur];}
    // 显示指定内联声明
    inline char get(pos ht, pos wd) const ;
    // 能在定义里面设置内联
    Screen& move(pos r, pos c);
private:
    pos cur=0;
    pos height=0, width=0;
    string content;
};

inline
Screen& Screen::move(Screen::pos r, Screen::pos c) {
    pos row = r * width;
    this->cur = row + c;
    return *this;
}

