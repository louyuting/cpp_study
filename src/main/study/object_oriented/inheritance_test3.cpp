//
// Created by Yuting Lou on 2019-04-04.
//
#include <iostream>
using namespace std;

class Base {
public:
    int nums;
    string name;
    Base():nums(0),name("name"){

    }
};

class Second : public Base {
public:
    Second(){
        this->nums=2;
        this->name="name2";
    }
};

int main(){
    cout << "test" << endl;
    static Second second;
    cout << second.name << " " << second.nums << endl;
}