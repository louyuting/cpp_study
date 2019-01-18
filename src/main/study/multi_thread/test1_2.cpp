//
// Created by 娄宇庭 on 2018/12/20.
//

#include <thread>
#include <iostream>

using namespace std;

class DisplayThread{
public:
    void operator()(){
        for(int i = 0; i < 100000; i++);
        cout<<"line3: thread1 function Executing"<<endl;
    }
};

/**
 * Creating a thread using Function Objects
 * @return
 */
int main(){
    thread thread1((DisplayThread()));
    for(int i = 0; i < 10000; i++);
    cout<<"line1: Display From MainThread"<<endl;
    cout<<"line2: Waiting For Thread to complete"<<endl;
    thread1.join();
    cout<<"line4: Exit of Main function"<<endl;
    return 0;
}
