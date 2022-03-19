// 这是一个对栈的虚定义
#ifndef STACK_H
#define STACK_H

const int maxsize = 100;

template <class T>
class Stack 
{
public:
    Stack(){};
    virtual void Push(const T& x) = 0;
    virtual bool Pop(T& x) = 0;
    virtual bool getTop(T& x) = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0;
};

#endif