#ifndef SEQSTACK_HPP
#define SEQSTACK_HPP

#include <iostream>
#include <cassert>
#include "Stack.hpp"

using std::ostream;

const int stackIncreace = 20;

template <class T>
class seqStack : public Stack<T>
{
private:
    T* elem;                 // 栈数组
    int top;                 // 栈顶指针，数组中元素个数减1
    int maxSize;             // 栈最大可以容纳的元素个数
    void overflowProcess();  // 溢出处理
public:
    seqStack(int sz = 50);   // 构造函数，建立一个空栈
    ~seqStack() { delete []elem; } // 析构函数
    void Push(const T& x);   // 如果isFull，则做溢出处理，再添到栈顶
    bool Pop(T& x);          // 如果不是isEmpty，则作pop处理，用x返回
    bool getTop(T& x); // 得到栈顶元素
    bool isEmpty() const;    // 判断是否为空
    bool isFull() const;     // 判断是否已满
    int getSize() const;     // 得到现有数据的多少
    void makeEmpty() { top = -1; } // 清空内容

    // 为了使得有元函数的T与class中的T保持一致，需要将其定义在class内部
    friend ostream& operator<<(ostream& os, const seqStack<T>& s) {
        os << "top = " << s.top << std::endl;
        for (int i = 0; i <= s.top; ++i) {
            os << i << ':' << s.elem[i] << std::endl;
        }
        return os;
    }
};

// private中的溢出处理
template <typename T>
void seqStack<T>::overflowProcess()
{
    T* newArray = new T[maxSize + stackIncreace];
    if (newArray == NULL) { std::cerr << "存储分配失败！" << std::endl; }
    // 将旧数组中元素复制到新的数组中
    for (int i = 0; i <= top; ++i) {
        newArray[i] = elem[i];
    }
    // top不需要改，maxsize需要修改，将原数组删除，将新数组修改名字
    maxSize = maxSize + stackIncreace;
    delete []elem;
    elem = newArray;
}

// 构造函数，构造新的数组
template <typename T>
seqStack<T>::seqStack(int sz) : top(-1), maxSize(sz)
{
    // 构造新数组
    elem = new T[maxSize];
    assert(elem != NULL);
}

// Push操作
template <typename T>
void seqStack<T>::Push(const T& x)
{
    if(this->isFull() == true) overflowProcess();
    elem[++top] = x; // top首先加一，然后elem[top] = x;
}

// Pop操作
template <typename T>
bool seqStack<T>::Pop(T& x)
{
    if (this->isEmpty() == true) {return false;}
    x = elem[top--];
    return true;
}

// getTop操作
template <typename T>
bool seqStack<T>::getTop(T& x)
{
    if (this->isEmpty() == true) {return false;}
    x = elem[top];
    return true;
}

// 判断是否为空
template <typename T>
bool seqStack<T>::isEmpty() const
{
    return top == -1;
}

// 判断是否已满
template <typename T>
bool seqStack<T>::isFull() const
{
    return top == maxSize - 1;
}

// getsize
template <typename T>
int seqStack<T>::getSize() const {
    return this->top + 1;
}

#endif