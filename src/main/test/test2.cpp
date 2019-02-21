//
// Created by Yuting Lou on 2019-01-11.
//
#include <iostream>
#include <string>
#include <python2.7/Python.h>
using namespace std;


void test_use_multi_param()
{
    Py_Initialize();
    // 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
    string path = "/Users/ytlou/Desktop/cpp/src/multiply";
    string chdir_cmd = string("sys.path.append(\"") + path + "\")";
    const char* cstr_cmd = chdir_cmd.c_str();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString(cstr_cmd);



    PyObject *pName, *pModule, *pFunc;
    pName = PyString_FromString("multiply");
    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

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
            Py_DECREF(pArgs);
            if (pValue != NULL)
            {
                printf("Result of call: %ld\n", PyInt_AsLong(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
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
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else
    {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", "multiply");
    }
    Py_Finalize();
}


int main(int argc, char *argv[])
{
    test_use_multi_param();
    cout << "finished" << endl;
}
