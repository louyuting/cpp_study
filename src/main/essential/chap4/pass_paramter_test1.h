//
// Created by 娄宇庭 on 2018/12/16.
//

#ifndef DEMO_TEST1_H
#define DEMO_TEST1_H

#include <string>
#include <iostream>

using namespace std;

class Triangular{
public:
    Triangular();
    Triangular(int len=1, int beg_pos=1);
    Triangular(const Triangular& rhs);
    ~Triangular(){};

private:
    int _length;
    int _beg_pos;
    int _next;
    string _name;
};

Triangular::Triangular() {
    this->_length = 1;
    this->_beg_pos = 1;
    this->_next = 0;
}

Triangular::Triangular(int len, int beg_pos) {
    this->_length = len>0?len:1;
    this->_beg_pos = beg_pos>0?beg_pos:1;
    this->_next = beg_pos-1;
}

Triangular::Triangular(const Triangular &rhs)
:_length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._next){

}






#endif //DEMO_TEST1_H
