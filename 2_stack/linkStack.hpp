#ifndef LINKSTACK_HPP
#define LINNSTACK_HPP

#include <iostream>
#include "Stack.hpp"
#include <cassert>

using std::ostream;

template <class T>
struct linkNode
{
    T value;
    linkNode* next;

    linkNode(linkNode<T>* next1 = nullptr) : next(next1) {}
    linkNode(const T& val, linkNode<T>* next1 = nullptr) : value(val), next(next1) {}
};

template <class T>
class linkStack : public Stack<T>
{
private:
    linkNode<T>* top;
public:
    linkStack() : top(nullptr) {};
    ~linkStack() { makeEmpty(); };
    
    void Push(const T& x);
    bool Pop(T& x);
    bool getTop(T& x);
    bool isEmpty() const;
    bool isFull() const { return false; }
    int getSize() const;
    void makeEmpty();

    friend ostream& operator<<(ostream& os, const linkStack<T>& s)
    {
        linkNode<T>* ptr = s.top;
        int i = 0;
        while (ptr != nullptr) {
            os << i << ':' << ptr->value << std::endl;
            ++i; ptr = ptr->next;
        }
        return os;
    }
};

// Push**********************
template <typename T>
void linkStack<T>::Push(const T& x)
{
    top = new linkNode<T>(x, top);
    assert(top != nullptr);       // 创建新节点失败退出
}

// Pop
template <typename T>
bool linkStack<T>::Pop(T& x)
{
    if (this->isEmpty() == true) return false;
    x = top->value;
    linkNode<T>* p = top;
    top = top->next;
    delete p;
    return true;
}

// getTop
template <typename T>
bool linkStack<T>::getTop(T& x)
{
    if (this->isEmpty() == true) return false;
    x = top->value;
    return true;
}

// isEmpty
template <typename T>
bool linkStack<T>::isEmpty() const
{
    linkNode<T>* ptr = top;
    return top == nullptr;
}

//getSize
template <typename T>
int linkStack<T>::getSize() const
{
    linkNode<T>* ptr = top;
    int size = 0;
    while (ptr != nullptr) {
        ++size;
        ptr = ptr->next;
    }
    return size;
}

// 链式栈置空
template <typename T>
void linkStack<T>::makeEmpty()
{
    linkNode<T>* ptr;
    while (top != nullptr) {
        ptr = top;
        top = ptr->next;
        delete ptr;
    }
}

#endif