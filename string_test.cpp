#include<iostream>
#include"String.h"
// #include"demo.h"
using namespace std;


int main()
{
    // String s1(); //这样不行不知道为什么
    String s2("hello"); //拷贝构造
    String s3(s2);
    cout << s3 << endl;  //拷贝赋值

}