//
// Created by 娄宇庭 on 2019/2/24.
//
#include <iostream>

using namespace std;

class HasStr
{
public:
    HasStr()
    {
        cout << "empty construct" << endl;
    }
    HasStr(const string& str): str_name(str)
    {
        cout << "has init value construct" << endl;
    }
    HasStr(HasStr& lvalue):str_name(lvalue.str_name)
    {
        cout << "copy construct" << endl;
    }
    // 移动构造函数
    HasStr(HasStr&& rvalue)
    {
        cout << "move construct" << endl;
        this->str_name = rvalue.str_name;
    }
    HasStr& operator=(HasStr& hasStr)
    {

    }

public:
    string str_name;
};



void func_param_lvalue(string& lstr){

}


int main(int argc, char* args[]){

    string str1 = "louyuting";
    func_param_lvalue(str1);



}