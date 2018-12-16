//
// Created by 娄宇庭 on 2018/12/10.
//
#include "chap3.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * 查找vector里面是否有value
 * @param vec
 * @param value
 * @return
 */
const int* find(const vector<int> &vec, const int value){
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value)
            return &(vec[i]);
    }
    return 0;
}


template <typename E>
const E* find1(const vector<E> &vec, const E &value)
{
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value)
            return &(vec[i]);
    }
    return 0;
}


const int* find3(const int* arr, int size, const int value){
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value)
            return &(arr[i]);
    }
    return 0;
}

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    const int* finded = find1(a, 3);
    cout<< &a << endl;
    cout<< &a[0] << endl;
    cout<< &a[1] << endl;
    cout<< &a[2] << endl;
    cout<< finded << endl;
    cout<< *(finded) << endl;

    cout<< "==========================================" << endl;
    int arr[] = {1,2,3,4,5};
    const int* finded3 = find3(arr, 5, 3);
    cout<< finded3 << endl;
    cout<< *(finded3) << endl;

    return 0;
}

