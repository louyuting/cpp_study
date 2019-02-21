//
// Created by Yuting Lou on 2019-01-18.
//
#include <iostream>
#include <ostream>
#include <memory>
#include <vector>

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



std::unique_ptr<D> pass_through(std::unique_ptr<D> p){
    p->bar();
    return p;
}


void close_file(std::FILE* fp){
    std::fclose(fp);
}



int main(int argc, char* argv[]){
    std::cout << "unique ownership semantics demo" << endl;
    {
        auto p = std::make_unique<D>();
        // 移动构造函数，p会被析构，也就是p编程nullptr
        auto q = pass_through(std::move(p));
        assert(!p); // 现在 p 不占有任何内容并保有空指针
        q->bar();   // 而 q 占有 D 对象
    }// ~D 调用于此

    std::cout << "Runtime polymorphism demo" << endl;
    {
        std::unique_ptr<B> p = std::make_unique<D>();
        p->bar();

        std::vector<std::unique_ptr<B>> v;  // unique_ptr 能存储于容器
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for(auto& p: v){
            p->bar(); // 虚派发
        }
    }//// ~D called 3 times

    cout << "custom deleter demo" << endl;

    {
        FILE* fpz = std::fopen("/Users/ytlou/Desktop/fw_dev32/demo/cpp/cpp_study/src/main/study/smart_ptr/demo.txt", "r"); // 准备要读的文件
        std::unique_ptr<std::FILE, void (*)(std::FILE*)> fp(fpz, close_file);
        if(fp) // fopen 可以打开失败；该情况下 fp 保有空指针
            std::cout << (char)std::fgetc(fp.get()) << '\n';
    } // fclose() 调用于此，但仅若 FILE* 不是空指针
    // （即 fopen 成功）

    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
        {
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });  // p 占有 D
        p->bar();
    } // 调用上述 lambda 并销毁 D

    std::cout << "Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p{new D[3]};
    } // 调用
}