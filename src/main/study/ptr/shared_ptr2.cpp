//
// Created by 娄宇庭 on 2018/12/15.
//

#include "shared_ptr1.h"
#include <iostream>
#include <memory>

using namespace std;

int main(){
    //shared_ptr<Test> sptr1(new Test[5]);
    shared_ptr<Test> sptr2(new Test[5],
            [](Test* p) {delete[]p;});

}


