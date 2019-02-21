//
// Created by 娄宇庭 on 2018/12/15.
//

#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
    int m_a;
    Test(int a=0) : m_a(a){}

    ~Test(){
        cout << "Calling destructor" << endl;
    }
};

int main(){
    //shared_ptr<Test> sptr1(new Test[5]);
    // 自定义析构时候的删除器
    shared_ptr<Test> sptr2(new Test[5],
            [](Test* p) {delete[]p;});

}


