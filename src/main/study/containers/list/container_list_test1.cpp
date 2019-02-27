//
// Created by 娄宇庭 on 2018/12/13.
//
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(){
    cout << "start" << endl;
    list<string> list1;

    list1.push_front("str2");
    list1.push_front("str3");
    list1.push_front("str4");
    list1.push_back("str1");

    for (auto elem : list1) {
        cout << elem << endl;
    }

    for (list<string>::const_iterator iter=list1.begin(); iter!=list1.end(); iter++){
        cout << *iter << endl;
    }

    cout << "================================" << endl;
    list1.erase(list1.begin());
    for (list<string>::const_iterator iter=list1.begin(); iter!=list1.end(); iter++){
            cout << *iter << endl;
    }

    //查找
    auto iter_idx = find(list1.begin(), list1.end(), "str3");
    if (iter_idx!=list1.end()){
        cout<< "find str3"<< endl;
        list1.insert(iter_idx, "str11111");
    }
    for (list<string>::const_iterator iter=list1.begin(); iter!=list1.end(); iter++){
        cout << *iter << endl;
    }
    return 0;
}


