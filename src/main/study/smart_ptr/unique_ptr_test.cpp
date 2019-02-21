//
// Created by 娄宇庭 on 2019/2/20.
//

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/**
 * unique_ptr:
 * 1. 独占语义
 * 2. 不存在复制语义，拷贝赋值和拷贝构造都不可以， 只存在移动语义。
 * 3. 主要作为auto_ptr替代品
 * @return
 */

unique_ptr<int> get_unique_ptr(){
    unique_ptr<int> tmp = make_unique<int>(1);
    return tmp;
}

void handler_unique_ptr(unique_ptr<int> ptr){
    *ptr = 20;
}

class TT{
public:
    TT(int num):_num(num){
        cout << "constructor TT" << endl;
    }
    ~TT(){
        cout << "destructor TT" << endl;
    }

public:
    int _num;
};

int main(){
    unique_ptr<int> p_int_1(new int(32));
    unique_ptr<int> p_int_2 = std::make_unique<int>(64);
    cout << *p_int_1<<endl;
    cout << *p_int_2<<endl;

//    拷贝构造被deleted
//    unique_ptr<int> p_int3(p_int_2);
//    unique_ptr<int> p_int4 = p_int_2;
//    拷贝赋值也是被deleted
//    unique_ptr<int> p_int_5;
//    p_int_5 = p_int_2;

    // 移动构造是存在的
    unique_ptr<int> p_int6(std::move(p_int_1));
    unique_ptr<int> p_int7;
    p_int7 = std::move(p_int_2);
    if (!p_int_1){
        cout << "p_int_1 is null:" << endl;
    }
    if (p_int_2 == nullptr) {
        cout << "p_int_2 is null:" << endl;
    }

    // 可以从函数返回然后获取unique_ptr
    unique_ptr<int> p_int8 = get_unique_ptr();
    if (!p_int8) {
        cout << "p_int_8 is null:" << endl;
    } else {
        cout << "p_int_8 is:"<< *p_int8 << endl;
    }

    //传递参数，移动构造函数，在函数里面处理完毕之后就会被释放
    //所以在调用handler_unique_ptr函数移动走p_int9之后，p_int9会变成null
    unique_ptr<int> p_int9 = make_unique<int>(8);
    handler_unique_ptr(std::move(p_int9));
    if (!p_int9) {
        cout << "p_int9 is null:" << (!p_int9) << endl;
    } else {
        cout << "p_int9 is not null:"<< (!p_int9) << endl;
    }

    // 容器里面保存指针, 可以取出
    vector<unique_ptr<TT>> vector1;
    for (int i = 0; i < 100; ++i) {
        unique_ptr<TT> bak = std::make_unique<TT>(i);
        vector1.push_back(std::move(bak));
    }
    // vector里面保存的是unique_ptr指针，当我们通过move移动指令取出来之后，
    // 那么vector里面对应的数据就已经为null了.
    unique_ptr<TT> first   = std::move(vector1[99]);
    cout<< first->_num <<endl;
    first->_num = 9999;
    //vector1[99] = std::move(first);
    unique_ptr<TT> first_2 = std::move(vector1[99]);
    if (!first_2){
        cout<< "pointer has been used!"<<endl;
    }
    cout<< "ending" <<endl;
}