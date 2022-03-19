/*************************************************************************
 @Author: 
 @Created Time : 2022年02月02日 星期三 16时49分23秒
 @File Name: 1.cpp
 @Description:
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    A() {
        cout << "A构造" << endl;
    }
    ~A() {
        cout << "A析构" << endl;
    }
};

class B : public A
{
public:
    B() {
        cout << "B构造" << endl;
    }
    ~B() {
        cout << "B析构" << endl;
    }
};


int main()
{
    int a = 3;
    int b = 4;
    int* ptr1 = new int[a];
    int* ptr = new int[a += b];
    cout << "size of ptr is " << sizeof(ptr1) / sizeof(ptr1[0])<< endl;
    return 0;
}
