//
// Created by 娄宇庭 on 2019/5/4.
//
#include <iostream>
#include <string>
#include <atomic>
#include <assert.h>

using namespace std;

/**
 * 使用atomic_flag实现mutex
 */
class spinlock_mutex
{
private:
    atomic_flag flag;

public:
    spinlock_mutex():flag(ATOMIC_FLAG_INIT)
    {
    }

    void lock()
    {
        // 将原子变量设置成true, 并且返回上一次值，也就是false，然后重入时会一直在循环里面。
        while (flag.test_and_set(memory_order_acquire));
    }

    void unlock()
    {
        // 将原子变量设置为false
        flag.clear();
    }


};





void atomic_spinlock_mutex_impl()
{
    cout << "----step1----" << endl;
    std::atomic_flag f = ATOMIC_FLAG_INIT;
    // 设置f为false
    f.clear();
    assert(f.__a_ == false);
    cout << "f = " << f.__a_ << endl;

    cout << "----step2----" << endl;
    // 设置f为true并获取前一个值
    bool x1=f.test_and_set();
    assert(f.__a_ == true);
    assert(x1 == false);
    cout << "f= " << f.__a_ << endl;
    cout << "x1= " << x1 << endl;
}


int main()
{
    cout << "/***********************atomic_flag_normal_test1()*****************************/" << endl;
    atomic_flag_normal_test1();




}