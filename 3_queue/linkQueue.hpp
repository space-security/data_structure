#ifndef LINKQUEUE_HPP
#define LINKQUEUE_HPP

#include <iostream>
#include <cassert>
#include "Queue.hpp"

using std::ostream;

template <class T>
struct linkNode
{
    T data;
    linkNode<T>* next;

    linkNode(linkNode<T>* ptr = nullptr) : next(ptr) {}
    linkNode(const T& val, linkNode<T>* ptr = nullptr) : data(val), next(ptr) {}
};

template <class T>
class linkQueue : public Queue<T>
{
private:
    linkNode<T>* front;
    linkNode<T>* rear;

public:
    linkQueue() : front(nullptr), rear(nullptr) {}
    ~linkQueue() { makeEmpty(); }

    void enQueue(const T& x); // 进入队列
    bool deQueue(T& x);       // 出队
    bool getFront(T& x);      // 得到队首元素
    bool isEmpty() const {return front == nullptr;}     // 判断是否为空
    bool isFull() const {return false;}      // 判断是否已满
    int getSize() const;      // 获取此时队列中的数据多少
    void makeEmpty();         // 数组置空，但是数组结构保留

    // 友元函数，重载<<操作符
    friend ostream& operator<<(ostream& os, linkQueue<T>& Q) {
        os << "the number of elements is " << Q.getSize() << std::endl;
        int i = 0;
        linkNode<T>* ptr = Q.front;
        while (ptr != nullptr) {
            os << ++i << ": " << ptr->data << std::endl;
            ptr = ptr->next;
        }
        return os;
    }
};

// 入队
template <typename T>
void linkQueue<T>::enQueue(const T& x)
{
    if (isEmpty() == true) {
        // 如果为空，则队首和队尾都需要操作
        front = rear = new linkNode<T>(x);
    } else {
        // 不为空，则新建结点为队尾
        rear->next = new linkNode<T>(x);
        rear = rear->next;
    }
}

// 出队
template<typename T>
bool linkQueue<T>::deQueue(T& x)
{
    if (isEmpty() == true) return false;
    x = front->data;
    linkNode<T>* ptr = front;
    front = front->next;
    delete ptr;
    return true;
}

// 得到队首元素
template <typename T>
bool linkQueue<T>::getFront(T& x)
{
    if (isEmpty() == true) return false;
    x = front->data;
    return true;
}

// 队列中实际存储数据的多少
template <typename T>
int linkQueue<T>::getSize() const
{
    linkNode<T>* ptr = front;
    int i = 0;
    while (ptr != nullptr) {
        ++i;
        ptr = ptr->next;
    }
    return i;
}

// 链表置空
template <typename T>
void linkQueue<T>::makeEmpty()
{
    linkNode<T>* ptr;
    while (front != nullptr) {
        ptr = front;
        front = front->next;
        delete ptr;
    }
}


#endif