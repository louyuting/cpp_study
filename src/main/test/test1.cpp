#include <iostream>
#include <python2.7/Python.h>
#include <thread>
#include <chrono>
#include <list>

using namespace std;
using namespace std::chrono;

FILE* fd = nullptr;

void init(){
    // 初始化Python运行环境
    Py_Initialize();
    if ( !Py_IsInitialized() ){
        cerr << "init python interpreter fail" << endl;
        return;
    }
    // 初始化对多线程的支持
    PyEval_InitThreads();

    if(!PyEval_ThreadsInitialized()){
        cerr << "Failed to initialize python interpreter supports multi-thread" << endl;
        return;
    }
    //因为调用PyEval_InitThreads成功后，当前线程就拥有了GIL，释放当前线程的GIL
    PyEval_SaveThread();

    fd = fopen("/Users/ytlou/Desktop/cpp/demo/src/test.py","r");
    if (fd == nullptr){
        cerr << "fail to open python source file" << endl;
    }
}

void destroy(){
    // 释放Python解释器函数
    Py_Finalize();
}

void thread_func1(int n){
    for (int i = 0; i < 5; ++i) {
        PyGILState_STATE state = PyGILState_Ensure();
        //PyRun_SimpleString("print('thread1')\n");
        PyRun_SimpleFile(fd, "test.py");
        PyGILState_Release(state);
    }
}
void thread_func2(int n){
    for (int i = 0; i < 5; ++i) {
        PyGILState_STATE state = PyGILState_Ensure();
        //PyRun_SimpleString("print('thread2')\n");
        PyRun_SimpleFile(fd, "test.py");
        PyGILState_Release(state);
    }
}

void thread_func3(int n){
    for (int i = 0; i < 5; ++i) {
        PyGILState_STATE state = PyGILState_Ensure();
        //PyRun_SimpleString("print('thread3')\n");
        PyRun_SimpleFile(fd, "test.py");
        PyGILState_Release(state);
    }
}
void thread_func4(int n){
    for (int i = 0; i < 5; ++i) {
        PyGILState_STATE state = PyGILState_Ensure();
        //PyRun_SimpleString("print('thread4')\n");
        PyRun_SimpleFile(fd, "test.py");
        PyGILState_Release(state);
    }
}
void thread_func(int n){
    for (int i = 0; i < 5; ++i) {
        PyGILState_STATE state = PyGILState_Ensure();
        //PyRun_SimpleString("print('thread4')\n");
        PyRun_SimpleFile(fd, "test.py");
        PyGILState_Release(state);
    }
}



int main() {
    init();
    std::chrono::nanoseconds start = std::chrono::duration_cast< std::chrono::nanoseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::cout << start.count() << std::endl;

    for (int i = 0; i < 100; ++i) {
        thread t(thread_func, i);
        t.detach();
    }


    std::chrono::nanoseconds end = std::chrono::duration_cast< std::chrono::nanoseconds >(
            std::chrono::system_clock::now().time_since_epoch()
    );
    std::cout << end.count() << std::endl;

    std::cout << "diff: " << end.count() - start.count() << std::endl;
    destroy();
    return 0;
}