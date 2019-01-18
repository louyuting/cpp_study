#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <boost/version.hpp>




using namespace std;


int main(){
    cout << "Hello, World!" << endl;
    cout << "Boost版本：" << BOOST_VERSION << endl;
    string sss = string("3333");
    string sss2 = string("sr2sr2sr2");
    string& sr = sss;
    sr = "《《《dddd》》》";
    sr = sss2;
    cout<< sr << endl;



    list<string> slist(100);
    vector<int> ivect(212213);

    cout<< slist.size() << endl;
    cout<< ivect.size() << endl;

    map<string, int> words;
    words["lou"] = 111;


    map<string, int>::iterator it = words.begin();
    for(; it!= words.end(); ++it){
        cout << "key: " << it->first << ",value: " << it->second << endl;
    }
    cout<< "lou:" <<  words["lwou"] << endl;


    string poo[4] = {"aaa", "bbb", "ccc", "ddd"};
    vector<string> svec3(poo, poo+4);

    for (int i = 0; i < svec3.size(); ++i) {
        cout<< svec3[i] << endl;
    }

    vector<string>::iterator iterator1 = svec3.begin();
    for (; iterator1!=svec3.end(); ++iterator1) {
        cout<< *iterator1 << endl;
    }



    return 0;
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











