//
// Created by Yuting Lou on 2019-01-17.
//
#include <iostream>
#include <memory>
#include "hello.hxx"

using namespace std;

int main(int argc, char* argv[]){
    try {
        unique_ptr<hello_t> h (hello (argv[1]));

        for (hello_t::name_const_iterator i(h->name().begin()); i!=h->name().end(); ++i)
        {
            cout << h->greeting() << ", " << *i << "!" << endl;
        }
    } catch (const xml_schema::exception& e){
        cerr << e << endl;
        return 1;
    }
}