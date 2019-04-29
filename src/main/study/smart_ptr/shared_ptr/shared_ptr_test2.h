//
// Created by 娄宇庭 on 2018/12/17.
//

#ifndef DEMO_TEST1_H
#define DEMO_TEST1_H


#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// statement
/**
 * 多个对象共享底层数据
 */
class StrBlog{
public:
    typedef vector<string>::size_type size_type;
    StrBlog();
    StrBlog(initializer_list<string> il);

    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    // 添加和删除元素
    void push_back(const string& str){
        data->push_back(str);
    }
    void pop_back();

    //元素访问
    string& front() const ;
    string& back() const ;
private:
    shared_ptr<vector<string>> data;
    //如果data[i]不合法就抛出异常
    /**
     *
     * @param i 元素的index
     * @param msg 错误信息
     */
    void check(size_type i, const string &msg) const;
};

// declare
StrBlog::StrBlog(): data(make_shared<vector<string>>()) {
    // empty
}

StrBlog::StrBlog(initializer_list<string> il)
: data(make_shared<vector<string>>(il)){
    //empty
}

void StrBlog::check(StrBlog::size_type i, const string &msg) const {
    if (i >= this->data->size()){
        throw out_of_range(msg);
    }
}

string& StrBlog::front() const {
    check(0, "front on empty strblog");
    return this->data->front();
}

string& StrBlog::back() const {
    check(0, "back on empty strblog");
    return this->data->back();
}

void StrBlog::pop_back() {
    check(0, "pop_back on empty strblog");
    this->data->pop_back();
}

#endif //DEMO_TEST1_H
