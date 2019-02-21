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

void fun(shared_ptr<int> p1){
    p1.get();
    cout << "fun引用次数:" <<  p1.use_count() << endl;
}

int main(){
    // 验证共享资源的shared_ptr智能指针；
    // 当作为参数传递进函数的时候，函数内部引用次数会自增并在函数结束之后自减。
    shared_ptr<int> sptr1 = make_shared<int>(100);
    cout << "fun before引用次数是：" <<  sptr1.use_count() << endl;
    fun(sptr1);
    cout << "fun after引用次数是：" <<  sptr1.use_count() << endl;
}


