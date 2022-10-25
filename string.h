#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>

class String
{
public:
    String(const char *cstr = nullptr);
    String(const String &str);  //拷贝构造，传入的参数是自己的类型 
    String &operator=(const String &str);  // 拷贝赋值
    ~String();   // 以上三个函数叫做Big Three 三个特殊函数

    char *get_c_str() const { return m_data; }  // 这个const添加的位置是在（）之后，{}之前。不能记错l

private:
    char *m_data;
};

inline
String::String(const char* cstr)
{
    if (cstr){
        m_data = new char[strlen(cstr) + 1];  //创建空间
        strcpy(m_data, cstr);  // 拷贝内容
    }
    else {
        m_data = new char[1]; 
        *m_data = '\0';  // 指针存放的内容，表示字符串为空
        
    }
}

// 拷贝构造
inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

// 拷贝赋值
inline
String& String:: operator=(const String& str)
{
    if (this == &str)
        return *this;  //自我赋值检查很关键,如果使用者进行自我赋值的话，就必须有这个自我赋值检查，否者，前面已经删除了就没有办法创建相同长度的地址了
    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline 
String::~String()
{
    delete[] m_data; // 释放内存就是这样的形式啊记住就好了 对象死亡前一刻调用析构函数，释放动态创建的内存
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}
#endif