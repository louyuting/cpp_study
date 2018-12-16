//
// Created by 娄宇庭 on 2018/11/6.
//

#ifndef DEMO_TEST_H
#define DEMO_TEST_H

#include <string>
#include <iostream>

using namespace std;

class Test {
public:
    string name;

    Test(){
        name = "default";
        cout << "Test constructor" << endl;
    }
    Test(const string& str){
        this->name = str;
        cout << "Test constructor" << endl;
    }

//    Test& operator=(const Test& source){
//        cout << "operator =" << endl;
//        if (this != &source)
//        {
//            this->name = source.name;
//        }
//        return *this;
//    }
};


#endif //DEMO_TEST_H
