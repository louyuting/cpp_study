//
// Created by Yuting Lou on 2019-01-21.
//

#ifndef CPP_STUDY_UNIQUE_PTR_TEST_COMMON_H
#define CPP_STUDY_UNIQUE_PTR_TEST_COMMON_H

#include <iostream>

using namespace std;


struct B {
    virtual void bar() {
        std::cout << "B::bar\n";
    }
    virtual ~B() = default;
};

struct D : B {
    D() {
        std::cout << "D::D" << endl;
    }

    ~D() {
        std::cout << "D::~D"<< endl;
    }

    void bar() override {
        std::cout << "D::bar"<< endl;
    }
};

#endif //CPP_STUDY_UNIQUE_PTR_TEST_COMMON_H
