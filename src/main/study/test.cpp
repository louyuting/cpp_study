//
// Created by 娄宇庭 on 2019/2/27.
//
#include <iostream>
#include <boost/version.hpp>
#include <constructor_basic_object.h>



int main(){
    int a = 88;
    int b = a;
    b = 99;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}