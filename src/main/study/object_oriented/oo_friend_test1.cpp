//
// Created by 娄宇庭 on 2018/12/17.
//


#include <iostream>
#include <string>
using namespace std;

class Sales_data{
    // 友元声明
    friend Sales_data add(const Sales_data& s1, const Sales_data& s2);
    friend istream& read(istream& is, Sales_data& s1);
    friend ostream& print(ostream& os, const Sales_data& s1);

public:
    Sales_data() = default;
    Sales_data(const string bkNo): bookNo(bkNo){};
    Sales_data(const string bkNo, int n, double p):bookNo(bkNo), unitd_sold(n), revenue(p*n){};
    Sales_data(istream &in);

    string isbn() const { return bookNo}
    Sales_data& combine(const Sales_data&);
private:
    string bookNo;
    int unitd_sold = 0;
    double revenue = 0.0;
};

// 声明
Sales_data add(const Sales_data& s1, const Sales_data& s2);
istream& read(istream& is, Sales_data& s1);
ostream& print(ostream& os, const Sales_data& s1);

