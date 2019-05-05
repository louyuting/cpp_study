//
// Created by 娄宇庭 on 2019/5/4.
//
#include <iostream>
#include <string>
#include <atomic>
#include <assert.h>

using namespace std;

/**
 * 测试原子标志位，atomic_flag保证是lock free的。
 */
void atomic_flag_normal_test1()
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

void atomic_bool_normal_test1()
{
    cout << "----step1----" << endl;
    std::atomic<bool> ab(false);
    assert(ab.load() == false);
    ab.store(true);
    bool x2=ab.load(std::memory_order_acquire);
    assert(x2 == true);
    cout << "x2 is:" << x2 << endl;
    bool x3 = ab.exchange(false, std::memory_order_acq_rel);
    assert(x3 == true);
}

class Foo{};

void atomic_ptr_normal_test1()
{
    Foo some_array[5];
    std::atomic<Foo*> p(some_array);
    Foo* x=p.fetch_add(2);  // p加2，并返回原始值
    cout << "some_body:" << some_array << "; x:" << x << endl;
    assert(x==some_array);
    assert(p.load()==&some_array[2]);
    x=(p-=1);  // p减1，并返回原始值
    assert(x==&some_array[1]);
    assert(p.load()==&some_array[1]);
}


int main()
{
    cout << "/***********************atomic_flag_normal_test1()*****************************/" << endl;
    atomic_flag_normal_test1();
    cout << "/***********************atomic_bool_normal_test1()*****************************/" << endl;
    atomic_bool_normal_test1();
    cout << "/***********************atomic_ptr_normal_test1()*****************************/" << endl;
    atomic_ptr_normal_test1();
}