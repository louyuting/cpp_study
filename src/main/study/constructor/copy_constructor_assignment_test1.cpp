//
// Created by 娄宇庭 on 2018/12/17.
//
/**
 * 测试 copy constructor and copy assignment
 */
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Str {
public:
    int num;
    string name;
public:
    Str():name(string("")), num(0) {  }
    Str(const int n, const string name): num(n), name(name)
    {
        cout << "construct!" << endl;
    }
    // copy constructor
    Str(const Str& rhs) : num(rhs.num), name(rhs.name)
    {
        cout << "copy construct!" << endl;
    }
    // copy assignment
    Str& operator=(const Str& rhs)
    {
        cout << "copy assignment!" << endl;
        this->num = rhs.num;
        this->name = rhs.name;
        return *this;
    }
    int get_num() const { return this->num;}
    string get_name() const { return this->name;}


};

int main(){
    cout << "Start copy_constructor_assignment_test1.cpp" << endl;
    cout << "Step1 constructor" << endl;
    /**
     * constructor
     */
    Str s1 = Str(1, "1");
    cout << "Result，num="<< s1.get_num()<< ", name="<<s1.get_name() << endl;
    assert(s1.num  == 1);
    assert(s1.name == "1");

    cout << "Step2 copy constructor" << endl;
    /**
     * copy constructor
     */
    Str s2(s1);
    cout << "Result，num="<< s2.get_num()<< ", name="<<s2.get_name() << endl;
    assert(s2.num  == 1);
    assert(s2.name == "1");


    cout << "Step3 copy constructor" << endl;
    /**
     * copy constructor
     */
    Str s3 = s1;
    cout << "Result，num="<< s3.get_num()<< ", name="<<s3.get_name() << endl;
    assert(s3.num  == 1);
    assert(s3.name == "1");


    cout << "Step4 copy assignment" << endl;
    /**
     * constructor
     */
    Str s4 = Str(4, "4");
    Str s5 = Str(5, "5");
    // assignment
    s5 = s4;
    s4.num = 44;
    s4.name = "44";
    cout << "Result s4，num="<< s4.get_num()<< ", name="<<s4.get_name() << endl;
    cout << "Result s5，num="<< s5.get_num()<< ", name="<<s5.get_name() << endl;
    assert(s4.num  == 44);
    assert(s4.name == "44");
    assert(s5.num  == 4);
    assert(s5.name == "4");
}
