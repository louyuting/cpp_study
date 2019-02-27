#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <assert.h>

using namespace std;

int main(int argc, char* args[]){
    string s1 = string("3333");
    string s2 = string("sr2sr2sr2");
    string& s1_r = s1;
    s1_r = "《《《dddd》》》";
    assert(s1 =="《《《dddd》》》");
    s1_r = s2;
    assert(s1_r == s2);
    cout<< s1_r << endl;

    list<string> str_list(100);
    vector<int> int_vector(212213);
    assert(str_list.size() == 100);
    assert(int_vector.size() == 212213);
    cout<< "str_list size is:" << str_list.size() << endl;
    cout<< "int_vector size is:" << int_vector.size() << endl;

    map<string, int> words;
    words["lou"] = 111;
    map<string, int>::const_iterator it = words.cbegin();
    for(; it!= words.cend(); ++it){
        cout << "key: " << it->first << ",value: " << it->second << endl;
    }
    cout<< "lwou:" <<  words["lwou"] << endl;
    cout<< "lou:" <<  words["lou"] << endl;

    cout << "foreach string array" << endl;
    string poo[4] = {"aaa", "bbb", "ccc", "ddd"};
    vector<string> svec3(poo, poo+4);

    for (int i = 0; i < svec3.size(); ++i) {
        cout<< svec3[i] << endl;
    }

    auto iterator1 = svec3.begin();
    for (; iterator1!=svec3.end(); ++iterator1) {
        cout<< *iterator1 << endl;
    }
}


template <typename elemType>
void display_message(const string &msg, const vector<elemType> &vec){
    cout << msg;

}


template <typename T>
T* find(const vector<T> &vec, const T &value){
    for (int i = 0; i < vec.size(); ++i) {
        if( vec[i] == value)
            return &vec[i];
    }
    return 0;
}



