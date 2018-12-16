//
// Created by 娄宇庭 on 2018/12/13.
//

#include "test.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> vector1;

    vector1.push_back("test1");
    vector1.push_back("test2");
    vector1.push_back("test1");
    vector1.push_back("test3");

    cout << vector1.size() << endl;
    cout << vector1.max_size() << endl;

    vector1.pop_back();
    vector1.erase(vector1.begin()+1, vector1.begin()+3);

    // vector 遍历的三种方式
    for (int i = 0; i <vector1.size(); ++i) {
        cout << vector1[i] << endl;
    }
    cout << "====================" << endl;
    for (const string str : vector1){
        cout << str << endl;
    }
    cout << "====================" << endl;
    vector<string>::const_iterator iter = vector1.begin();
    for (; iter != vector1.end(); iter++){
        cout << *iter << endl;
    }

    cout << "size:" <<  vector1.size() << endl;
    cout << vector1.back() << endl;

    //vector 查找
    auto idx = find(vector1.begin(), vector1.end(), "test1111");
    if (idx == vector1.end()){
        cout << "false" << endl;
    } else {
        cout << "true" << endl;
    }

}