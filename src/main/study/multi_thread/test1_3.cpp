//
// Created by 娄宇庭 on 2018/12/20.
//

#include <thread>
#include <iostream>

using namespace std;

/**
 * Creating a thread using Lambda functions
 * @return
 */
int main(){
    cout<< "main thread id: " << std::this_thread::get_id() << endl;
    int x = 9;
    thread thread1([]{
        cout<< "thread1 id: " << std::this_thread::get_id() << endl;
        for(int i = 0; i < 100000; i++);
        cout<<"line3: thread1 function Executing"<<endl;
    });
    for(int i = 0; i < 10000; i++);
    cout<<"line1: Display From MainThread"<<endl;
    cout<<"line2: Waiting For Thread to complete"<<endl;
    thread1.join();
    cout<<"line4: Exit of Main function"<<endl;
    return 0;
}
