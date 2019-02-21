//
// Created by Yuting Lou on 2019-01-18.
//
#include <iostream>
#include <ostream>
#include <memory>
#include <vector>

#include "unique_ptr_test_common.h"

using namespace std;

std::unique_ptr<D> pass_through(std::unique_ptr<D> p){
    p->bar();
    return p;
}


void close_file(std::FILE* fp){
    std::fclose(fp);
}

std::unique_ptr<D> print(std::unique_ptr<D> p){
    p->bar();
    return p;
}


int main(int argc, char* argv[]) {
    std::cout << "unique ownership semantics demo" << endl;
    {
        auto p1 = make_unique<D>();
        auto q1 = print(std::move(p1));
        assert(p1 == nullptr);
        cout << "release q1" << endl;
        D* d1 = q1.release();
        assert(q1== nullptr);
        d1->bar();
        delete d1;
    }

    std::cout << "unique ownership semantics demo2" << endl;
    {
        auto p1 = make_unique<D>();
        auto q1 = print(std::move(p1));
        assert(p1 == nullptr);
        cout << "reset q1" << endl;
        q1.reset();
        assert(q1== nullptr);
    }




}