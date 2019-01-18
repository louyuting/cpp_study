//
// Created by 娄宇庭 on 2018/12/18.
//

#include "test12_3.h"
#include <fstream>

int main(){
    fstream     f("dictionary.txt");//创建一个fstream文件流对象

    runQueries(f);

}