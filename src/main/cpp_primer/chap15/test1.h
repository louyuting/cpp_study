//
// Created by 娄宇庭 on 2018/12/17.
//

#ifndef DEMO_TEST1_H
#define DEMO_TEST1_H

#include <iostream>
using namespace std;


class Quote{
public:
    // 告诉编译器帮我生成默认的构造函数
    Quote() = default;
    Quote(const string& book_sn, double sale_price): bookNo(book_sn), price(sale_price){}
    // 对析构函数进行动态绑定
    virtual ~Quote() = default;

    string isbn() const { return this->bookNo;};
    virtual double net_price(size_t n) const { return n*price ;};

private:
    string bookNo;// 书本唯一的SN
protected:
    double price = 0.0;//普通状态下不打折的价格
};


class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book_sn, double price, size_t qty, double disc)
    : Quote(book_sn, price), min_qyt(qty), discount(disc){}

    // 覆盖基类
    double net_price(size_t n) const override;

private:
    size_t min_qyt = 0;// 适用于折扣的最低购买量
    double discount = 0.0;//折扣额
};

double Bulk_quote::net_price(size_t cnt) const {
    if ( cnt > this->min_qyt ){
        return cnt * (1-this->discount) * this->price;
    } else {
        return cnt * this->price;
    }
}

// 打印买出的总价
double print_total(ostream& os, const Quote& item, size_t n){
    // 根据 item 的实际类型，动态的调用net_price
    double net = item.net_price(n);
    os << "ISBN:" << item.isbn() <<" #sold: " << n << " total due:" << net << endl;
    return net;
}













#endif //DEMO_TEST1_H
