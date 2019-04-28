//
// Created by 娄宇庭 on 2018/12/15.
//

#include <iostream>
#include <memory>

using namespace std;

class Test
{
public:
    int m_a;
    Test(int a=0) : m_a(a)
    {
        cout << "Test Calling constructor" << endl;
    }
    ~Test()
    {
        cout << "Test Calling destructor" << endl;
    }
};


void fun(auto_ptr<Test> p1 )
{
    cout << "fun : auto_ptr p1->m_a: " << p1->m_a << endl;
}

/**
 * 测试基本使用
 * @return
 */
int main()
{
    auto_ptr<Test> p1(new Test(5));
    cout << "auto_ptr p1->m_a: " << p1->m_a << endl;
    // auto_ptr会自动销毁
    try {
        auto_ptr<Test> p2(new Test(5));
        // p的控制权转移到Fun函数中，然后在Fun函数作用于结束的时候，p已经被释放了。
        fun(p2);
        cout << "after call p2" << endl;
        // 出错，因为p所有权在Fun函数中转移，且在Fun执行完毕时候释放掉了。所以这里p是NULL
        if(p2.get() == NULL){
            cout << "p2 is nullptr" << endl;
        } else {
            cout << p2->m_a << endl;
        }
    } catch (char const* e)
    {
        cout<<"Something has gone wrong"<<endl;
    }

    return 1;
}
