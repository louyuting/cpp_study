//
// Created by Yuting Lou on 2019-01-14.
//
#include <iostream>
#include <thread>
#include <python2.7/Python.h>

using namespace std;

class PythonThreadLocker
{
    PyGILState_STATE state;
public:
    PythonThreadLocker() : state(PyGILState_Ensure())
    {}
    ~PythonThreadLocker() {
        PyGILState_Release(state);
    }
};

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
}

void destroy(){
    // 释放Python解释器函数
    Py_Finalize();
}


void exec_python_func(){
    // 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
    string path = "/Users/ytlou/Desktop/cpp/src/multiply";
    string chdir_cmd = string("sys.path.append(\"") + path + "\")";
    const char* cstr_cmd = chdir_cmd.c_str();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(cstr_cmd);

    PyObject *pName, *pModule, *pFunc;
    pName = PyString_FromString("multiply");
    pModule = PyImport_Import(pName);

    PyObject *pArgs, *pValue;
    if (pModule != nullptr)
    {
        pFunc = PyObject_GetAttrString(pModule, "multiply");
        if (pFunc && PyCallable_Check(pFunc))
        {
            pArgs = PyTuple_New(2);
            PyObject* pValue1 = PyInt_FromLong(1000l);
            PyObject* pValue2 = PyInt_FromLong(3l);
            PyTuple_SetItem(pArgs, 0, pValue1);
            PyTuple_SetItem(pArgs, 1, pValue2);

            pValue = PyObject_CallObject(pFunc, pArgs);
            if (pValue != NULL)
            {
                printf("Result of call: %ld\n", PyInt_AsLong(pValue));
            }
            else {
                PyErr_Print();
                fprintf(stderr, "Call failed\n");
            }
        }
        else
        {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", "multiply");
        }
    }
    else
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", "multiply");
    }
}

void thread_func(int n){
    // 执行Python的前置处理
//    for (int i = 0; i < 100; ++i) {
//        cout << n << endl;
//    }
    // 执行Python
    PythonThreadLocker locker;
    exec_python_func();

}


int main() {
    // 初始化
    init();

    /**
     * 多线程执行Python代码；
     * join线程，等待线程结束
     */
    Py_BEGIN_ALLOW_THREADS
    thread t1(thread_func, 1);
    thread t2(thread_func, 2);
    thread t3(thread_func, 3);
    thread t4(thread_func, 4);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    Py_END_ALLOW_THREADS
    cout << "done" << endl;
    destroy();
}