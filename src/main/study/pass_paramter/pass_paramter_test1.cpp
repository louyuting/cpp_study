//
// Created by 娄宇庭 on 2019/2/24.
//
#include "../common/constructor_basic_object.h"

/**
 * 左值引用传参，可以改变入参对象本身的值
 * @param lstr
 */
void func_param_lvalue(string& lstr){
    lstr = "louyuting-copy";
}

//void func_1(int i){
//    cout << i <<endl;
//}

void func_1(int& i){
    cout << i <<endl;
}


void func_1(const int& i){
    cout << i <<endl;
}


int main(int argc, char* args[]){
    cout << "test case1: lvalue pass can change value" << endl;
    string str1 = "louyuting";
    string& str1_ref = str1;
    func_param_lvalue(str1);
    func_param_lvalue(str1_ref);

    str1_ref = "louyuting-str1_ref";
    cout << str1 << endl;
    cout << str1_ref << endl;

    int ii = 0;
    int& ii_ref= ii;
    const int& ii_ref_const = ii;
    // 常量，所以调用void func_1(const int& i){}
    func_1(1);
    // 变量，可以改变ii，所以是void func_1(int& i){}
    func_1(ii);
    // 变量，可以改变ii，所以是void func_1(int& i){}
    func_1(ii_ref);
    // ii_ref_const不可变，所以调用void func_1(const int& i){}
    func_1(ii_ref_const);

    int* p_i = new int(2);
    delete p_i;
    p_i = new int(3);
    cout << *p_i << endl;
}