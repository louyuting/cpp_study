//
// Created by 娄宇庭 on 2018/12/20.
//
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
/**
 * Data Sharing and Race Conditions
 */


class Wallet{
public:
    Wallet():money(0){}

    int getMoney(){ return this->money;}

    void addMoney(int n){
        for (int i = 0; i < n; ++i) {
            (this->money)++;
        }
    }
private:
    int money;
};

int test(){
    Wallet wallet;
    vector<thread> threads;
    for (int i = 0; i <5 ; ++i) {
        threads.push_back(thread(&Wallet::addMoney, &wallet, 1000));
    }
    for (int i = 0; i <5 ; ++i) {
        threads.at(i).join();
    }
    return wallet.getMoney();
}


int main(){
    int val = 0;
    for(int k = 0; k < 1000; k++) {
        if((val = test()) != 5000)
        {
            std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
        }
    }
    return 0;
}





