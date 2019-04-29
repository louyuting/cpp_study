//
// Created by 娄宇庭 on 2019/2/20.
//

#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>

using namespace std;

class Test
{
public:
    explicit Test(int num):_num(num)
    {
        cout << "default constructor Test, this->num="<< this->_num<< endl;
    }

    Test(const Test& test): _num(test._num)
    {
        cout << "copy constructor Test, this->num="<< this->_num<< endl;
    }

    Test(Test&& r_test) noexcept
    {
        this->_num = r_test._num;
        cout << "move constructor Test, this->num="<< this->_num<< endl;
    }

    ~Test()
    {

        cout << "destructor  Test, this->num="<< this->_num << endl;
    }
public:
    int _num;
};

unique_ptr<int> _get_unique_ptr()
{
    unique_ptr<int> tmp = make_unique<int>(1);
    return tmp;
}

void _handler_unique_ptr(unique_ptr<int>&& ptr)
{
    *ptr = 20;
    unique_ptr<int> tmp = std::move(ptr);
}

/**
 * unique_ptr:
 * 1. 独占语义
 * 2. 不存在复制语义，拷贝赋值和拷贝构造都不可以， 只存在移动语义。
 * 3. 主要作为auto_ptr替代品
 * @return
 */
void unique_ptr_normal_test1()
{
    unique_ptr<int> p_int_1(new int(32));
    unique_ptr<int> p_int_2 = std::make_unique<int>(64);
    cout << *p_int_1<<endl;
    cout << *p_int_2<<endl;

    // error statement, because of copy constructor is deleted explicitly
    // unique_ptr<int> p_int3(p_int_2);
    // unique_ptr<int> p_int4 = p_int_2;
    // error statement, because of copy assignment is deleted explicitly
    // unique_ptr<int> p_int_5;
    // p_int_5 = p_int_2;

    // move constructor is illegal
    unique_ptr<int> p_int6(std::move(p_int_1));
    assert(p_int_1 == nullptr);
    // move assignment is
    unique_ptr<int> p_int7;
    p_int7 = std::move(p_int_2);
    assert(p_int_2 == nullptr);
    if (!p_int_1)
    {
        cout << "p_int_1 is nullptr:" << endl;
    }
    if (p_int_2 == nullptr)
    {
        cout << "p_int_2 is nullptr:" << endl;
    }
}


void unique_ptr_normal_test2()
{
    //get unique_ptr instance from function return value
    unique_ptr<int> p_int8 = _get_unique_ptr();
    assert(p_int8 != nullptr);
    if (!p_int8)
    {
        cout << "p_int_8 is nullptr:" << endl;
    } else
    {
        cout << "p_int_8 is:"<< *p_int8 << endl;
    }

    //传递参数，移动构造函数，在函数里面处理完毕之后就会被释放
    //所以在调用handler_unique_ptr函数移动走p_int9之后，p_int9会变成null
    unique_ptr<int> p_int9 = make_unique<int>(9);
    _handler_unique_ptr(std::move(p_int9));
    //_handler_unique_ptr(std::move(p_int9));
    if (p_int9)
    {
        cout << "p_int9 is not nullptr:" << (!p_int9) << endl;
    }
    else
    {
        cout << "p_int9 is nullptr:"<< (!p_int9) << endl;
    }
}

void unique_ptr_normal_test3()
{
    // 容器里面保存指针, 可以取出
    vector<unique_ptr<Test>> vector1;
    for (int i = 0; i < 100; ++i) {
        unique_ptr<Test> bak = std::make_unique<Test>(Test(i));
        vector1.push_back(std::move(bak));
    }
    // vector里面保存的是unique_ptr指针，当我们通过move移动指令取出来之后，
    // 那么vector里面对应的数据就已经为null了.
    unique_ptr<Test> first   = std::move(vector1[99]);
    cout<< first->_num <<endl;
    first->_num = 9999;
    cout<< first->_num <<endl;
    unique_ptr<Test> first_2 = std::move(vector1[99]);
    assert(first_2== nullptr);
    if (!first_2)
    {
        cout<< "pointer has been used!"<<endl;
    }
}



void unique_ptr_normal_test4(){
    cout<< "step 1" << endl;
    unique_ptr<Test> p1 = make_unique<Test>(move(Test(0)));
    cout<< "p1->num"<< p1->_num << endl;
    cout<< "step 2" << endl;
    Test* tmp = new Test(88);
    cout<< "step 3" << endl;
    p1.reset(tmp);
    cout<< "step 4" << endl;
    cout<< p1->_num << endl;
}


void unique_ptr_normal_test5(){
    unique_ptr<Test> p2(new Test(2));
    cout<< "p2->num="<< p2->_num << endl;
}



int main(){
    cout<< "/************unique_ptr_normal_test1()********************/" << endl;
    unique_ptr_normal_test1();
    cout<< "/************unique_ptr_normal_test2()********************/" << endl;
    unique_ptr_normal_test2();
    cout<< "/************unique_ptr_normal_test3()********************/" << endl;
    unique_ptr_normal_test3();
    cout<< "/************unique_ptr_normal_test4()********************/" << endl;
    unique_ptr_normal_test4();
    cout<< "/************unique_ptr_normal_test5()********************/" << endl;
    unique_ptr_normal_test5();
}