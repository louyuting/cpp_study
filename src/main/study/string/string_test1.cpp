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

void string_test1(){
    string s1 = string("3333");
    string s2 = string("sr2sr2sr2");
    string& s1_r = s1;//引用指向的对象不可改变
    s1_r = "<<<dddd>>>";
    assert(s1 =="<<<dddd>>>");
    s1_r = s2;
    assert(s1_r == "sr2sr2sr2");
    cout<< s1_r << endl;
}

void string_substr_test1(){
    string s1("3333444466665555");
    string s1_sub = s1.substr(5,5);
    cout <<"s1_sub=" << s1_sub << endl;
    assert(s1_sub=="44466");
    s1_sub = "11111";
    assert(s1=="3333444466665555");
    cout <<"s1=" << s1 << endl;
    assert(s1_sub=="11111");
    cout <<"s1_sub=" << s1_sub << endl;
}

void string_append_test1()
{
    string s1("1111");
    s1.append(4, '2');
    s1.append("3333");
    cout << s1 << endl;
}

void string_c_str_test1()
{
    string s1("1111");
    s1.append(4, '2');
    s1.append("3333");
    string rt = s1.c_str();
    cout << rt << endl;
    rt.append("4444");
    cout << s1 << endl;
    cout << rt << endl;
}


void string_test2(){
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



int main(int argc, char* args[]){
    cout<<"/************string_test1()********************/"<<endl;
    string_test1();
    cout<< "/************string_substr_test1()********************/" << endl;
    string_substr_test1();
    cout<< "/************string_append_test1()********************/" << endl;
    string_append_test1();
    cout<< "/************string_c_str_test1()********************/" << endl;
    string_c_str_test1();
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



