//
// Created by 娄宇庭 on 2018/12/15.
//

#include "shared_ptr1.h"
#include <iostream>
#include <memory>

using namespace std;


void fun(shared_ptr<int> p1){
    p1.get();
    cout << "fun引用次数:" <<  p1.use_count() << endl;
}

int main(){
    shared_ptr<int> sptr1 = make_shared<int>(100);
    cout << "fun before引用次数是：" <<  sptr1.use_count() << endl;
    fun(sptr1);
    cout << "fun after引用次数是：" <<  sptr1.use_count() << endl;
}


