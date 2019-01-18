//
// Created by 娄宇庭 on 2018/12/17.
//
/**
 * 测试 copy constructor
 */
#include "test1.h"

#include <iostream>
#include <string>
using namespace std;

class Str {
public:
    Str() = default;
    Str(const int n, const string nam): num(n), name(nam){
        cout << "construct!" << endl;
    }
    // copy constructor
    Str(const Str& rhs) : num(rhs.num), name(rhs.name){
        cout << "copy construct!" << endl;
    }
    Str&operator=(const Str& rhs){
        this->num = rhs.num;
        this->name = rhs.name;
        cout << "assignment!" << endl;
    }

    int get_num(){ return this->num;}
    string get_name(){ return this->name;}

private:
    int num;
    string name;
};

int main(){
    cout << "Start chapter13 test1.cpp" << endl;
    cout << "Step1" << endl;
    /**
     * constructor
     */
    Str s1 = Str(1, "1");
    cout << "Result，num="<< s1.get_num()<< ", name="<<s1.get_name() << endl;
    Str s = Str(2, "2");

    cout << "Step2" << endl;
    /**
     * copy constructor
     */
    Str s2(s1);
    cout << "Result，num="<< s2.get_num()<< ", name="<<s2.get_name() << endl;

    cout << "Step3" << endl;
    /**
     * copy constructor
     */
    Str s3 = s1;
    cout << "Result，num="<< s3.get_num()<< ", name="<<s3.get_name() << endl;

    cout << "Step4" << endl;
    /**
     * assignment
     */
    s3 = s;
    cout << "Result，num="<< s3.get_num()<< ", name="<<s3.get_name() << endl;
}
