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

void Fun(){
    int a=0, b=5, c;
    if (a==0){
        throw "Invalid divisor";
    }
    c = b/a;
    return;
}

void Fun(auto_ptr<Test> p1 )
{
    cout<<p1->m_a<<endl;
}

int main(){

//    auto_ptr<Test> p(new Test(5));
//    cout << p->m_a << endl;

    // auto_ptr会自动销毁
    try {
        auto_ptr<Test> p(new Test(5));
        // p的控制权转移到Fun函数中，然后在Fun函数作用于结束的时候，p已经被释放了。
        Fun(p);
        // 出错，因为p所有权在Fun函数中转移，且在Fun执行完毕时候释放掉了。所以这里p是NULL
        cout << p->m_a << endl;
    } catch (char const* e){
        cout<<"Something has gone wrong"<<endl;
    }
}
