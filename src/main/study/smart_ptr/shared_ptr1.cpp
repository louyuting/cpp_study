//
// Created by 娄宇庭 on 2018/12/15.
//

#include <iostream>
#include <memory>

using namespace std;

struct Test{
public:
    int m_a;
    Test(int a=0) : m_a(a){
        cout << "constructor of Test" << endl;
    }

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
    cout << "aptr1里面的值: " << *sptr1 << endl;
    cout << "fun before引用次数是：" <<  sptr1.use_count() << endl;
    fun(sptr1);
    cout << "fun after引用次数是：" <<  sptr1.use_count() << endl;

    cout << "=============================================="<< endl;
    shared_ptr<Test> s_ptr_Test = make_shared<Test>(0);
    s_ptr_Test->m_a = 8888;
    cout << "print s_ptr_Test->m_a=[" << s_ptr_Test->m_a << "]" << endl;
}


