//
// Created by 娄宇庭 on 2018/12/13.
//
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

/**
 * 右值引用和move语义的测试。
 */
class MyString
{
public:
    static size_t M_C_Cnt;//移动构造函数调用次数
    static size_t M_A_Cnt;//移动赋值函数调用次数
    static size_t C_C_Cnt;//拷贝构造函数调用次数
    static size_t C_A_Cnt;//拷贝赋值函数调用次数
private:
    // 实际持有的字符串的指针
    char* m_pData;
    // 字符串的长度
    size_t m_nLen;
public:
    // 空构造函数
    MyString():m_pData(nullptr), m_nLen(0)
    {
        std::cout<<"constructor MyString()"<<endl;
    }
    // 构造函数
    MyString(const char* pStr)
    {
        std::cout<<"constructor MyString(const char* pStr)"<<endl;
        this->m_nLen = strlen(pStr);
        copy_data(pStr);
    }
    // 拷贝构造函数
    MyString(const MyString& other){
        std::cout<<"copy constructor MyString"<<endl;
        MyString::C_C_Cnt ++;
        if (other.m_pData){
            this->m_nLen = other.m_nLen;
            delete_data();
            copy_data(other.m_pData);
        }
    }
    // 拷贝赋值函数
    MyString& operator=(const MyString& other){
        std::cout<<"copy assignment"<<endl;
        MyString::C_A_Cnt++;
        // 避免自我赋值
        if (this == &other){
            return *this;
        }
        // 删除自己
        delete_data();
        // 赋值拷贝, 包括m_nLen和m_pData
        this->m_nLen = other.m_nLen;
        copy_data(other.m_pData);
        return *this;
    }

    // 移动构造函数
    MyString(MyString&& other): m_pData(other.m_pData), m_nLen(other.m_nLen){
        std::cout<<"move constructor "<<endl;
        MyString::M_C_Cnt++;
        //释放原有的资源
        other.m_pData = nullptr;
        other.m_nLen = 0;
    }
    //移动赋值函数
    MyString& operator=(MyString&& other){
        std::cout<<"move assignment "<<endl;
        MyString::M_A_Cnt++;
        if (this == &other){
            // 自我赋值
            return *this;
        }
        delete_data();
        this->m_pData = other.m_pData;
        other.m_nLen = other.m_nLen;
        //other不再指向原有的资源
        other.m_pData = nullptr;
        other.m_nLen = 0;
        return *this;
    }

private:
    void copy_data(const char *pData)
    {
        if (pData)
        {
            this->m_pData = new char[m_nLen + 1];
            memcpy(this->m_pData, pData, m_nLen);
            this->m_pData[m_nLen] = '\0';
        }
    }

    void delete_data()
    {
        if (this->m_pData != nullptr)
        {
            delete this->m_pData;
            this->m_pData = nullptr;
        }
    }

};

size_t MyString::M_C_Cnt = 0;
size_t MyString::M_A_Cnt = 0;
size_t MyString::C_C_Cnt = 0;
size_t MyString::C_A_Cnt = 0;



int main() {
    cout << "start" << endl;
    std::vector<MyString> vector1;
    vector1.reserve(10);
    for(int i=0;i<10;i++){
        //左值
        MyString tmp("work");
        //当将tmp传递给push_back函数的时候，会调用拷贝构造函数。
        vector1.push_back(tmp);
    }
    cout << "Constructor_Copy_Cnt = "       << MyString::C_C_Cnt << endl;
    cout << "Constructor_Assignment_Cnt = " << MyString::C_A_Cnt << endl;
    cout << "Move_Copy_Cnt = "              << MyString::M_C_Cnt << endl;
    cout << "Move_Assignment_Cnt = "        << MyString::M_A_Cnt << endl;

    cout << "==================================================" << endl;
    MyString str1("Yuting Lou");
    //拷贝构造函数
    MyString str2(str1);
    // 移动构造函数
    MyString str3("Yuting Lou");
    {
        MyString str4(std::move(str3));
    }

    MyString str5;
    // 拷贝赋值
    str5 = str2;
    MyString str6;
    // 移动赋值
    str6 = std::move(str2); // str2的内容也失效了，不要再使用

    return 0;
}