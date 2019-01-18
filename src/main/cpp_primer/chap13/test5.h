//
// Created by 娄宇庭 on 2018/12/20.
//

#ifndef DEMO_TEST5_H
#define DEMO_TEST5_H


#include <iostream>
#include <string>

using namespace std;

class StrVec{
public:
    // 指针元素默认初始化
    StrVec():elements(nullptr), first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec& rhs);
    // 移动构造函数, 不应该抛出任何异常
    StrVec(const StrVec&& rhs) noexcept;
    StrVec&operator=(const StrVec& rhs);
    // 移动赋值运算符
    StrVec&operator=(const StrVec&& rhs)noexcept;
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return (first_free - elements);}
    size_t capacity() const { return (cap - elements);}
    string* begin() const { return elements;}
    string* end() const { return first_free;}

private:
    //分配元素
    static allocator<string> alloc;
    void chk_n_alloc(){
        if (size() == capacity()){
            reallocate();
        }
    }
    // 工具函数，used by copy constructor、 assignment、destructor
    pair<string*,string*> alloc_n_copy(const string*, const string*);
    //销毁元素并释放内存
    void free();
    //获得更多内存并拷贝元素
    void reallocate();
    //指向数组首元素的指针
    string* elements;
    //指向数组第一个空闲元素的指针
    string* first_free;
    //指向数组末尾后面一个元素的指针
    string* cap;
};


void StrVec::push_back(const string& str) {
    // 确保有空间容纳元素
    chk_n_alloc();
    // 在first_free指向的元素中构造str的副本
    StrVec::alloc.construct(first_free++, str);
}

pair<string*,string*> StrVec::alloc_n_copy(const string* b, const string* e) {
    // 分配空间保存给定范围的元素
    auto data = StrVec::alloc.allocate(e-b);
    // 初始化并返回一个pair，该pair由data和uninitiated_copy的返回值构成
    return {data, uninitialized_copy(s1, s2, data)};
}


void StrVec::free() {
    // 如果elements为空就什么也不做
    if( elements ){
        for (auto p=first_free; p!=elements; ){
            StrVec::alloc.destroy(--p);
        }
        StrVec::alloc.deallocate(elements, cap-elements);
    }
}


StrVec::StrVec(const StrVec &rhs) {
    // 分配空间足够容纳和rhs一样的元素
    auto newdata = StrVec::alloc_n_copy(rhs.begin(), rhs.end());
    this->elements = newdata.first;
    this->first_free = this->cap = newdata.second;
}

StrVec::StrVec(const StrVec &&rhs) noexcept
    // 初始化列表接管源对象的资源
    :elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap){
    // 使rhs进入一种状态，对其运行析构函数是安全的
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    // 分配空间足够容纳和rhs一样的元素
    auto newdata = StrVec::alloc_n_copy(rhs.begin(), rhs.end());
    // 释放当前this指向的对象
    this->free();
    this->elements = newdata.first;
    this->first_free = this->cap = newdata.second;
    return *this;
}

StrVec& StrVec::operator=(const StrVec &&rhs) noexcept {
    // 直接检测自我赋值
    if( this != &rhs ){
        // 释放已有元素
        free();
        //从 rhs 接管资源
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        // 将RHS 置为可析构状态
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    // 扩容一倍
    auto new_cap = this->size()? 2*this->size():1;
    // 分配新内存
    auto new_data = StrVec::alloc.allocate(new_cap);

    // 将数据从旧内存移动到新内存
    auto dest = new_data;//指向新数组下一个空闲位置
    auto elem = this->elements;//指向旧数组中下一个位置
    for (size_t i = 0; i < size(); ++i) {
        StrVec::alloc.construct(dest++, std::move(*elem++));
    }
    // 移动完成就free旧内存
    free();
    // 更新数据结构
    this->elements = new_data;
    this->first_free = dest;
    this->cap = this->elements+new_cap;
}


#endif //DEMO_TEST5_H
