#ifndef SEQQUEUE_HPP
#define SEQQUEUE_HPP

#include <iostream>
#include "Queue.hpp"
#include <cassert>

const int queueIncreace = 20;

template <class T>
class seqQueue : public Queue<T>
{
private:
    int front, rear;       // 首数据和尾数据所在位置
    T* elem;               // 数组头节点
    int size;               // 数组大小
    void overflowProcess(); // 溢出处理
public:
    seqQueue(int sz = 50);
    ~seqQueue() { delete []elem; }

    void enQueue(const T& x); // 进入队列
    bool deQueue(T& x);       // 出队
    bool getFront(T& x);      // 得到队首元素
    bool isEmpty() const;     // 判断是否为空
    bool isFull() const;      // 判断是否已满
    int getSize() const;      // 获取此时队列中的数据多少
    void makeEmpty();         // 数组置空，但是数组结构保留

    int showQueueSize() { return this->size; } // 显示此时数组实际存储容量
};

// 溢出处理
template <typename T>
void seqQueue<T>::overflowProcess()
{
    T* newArray = new T[this->size + queueIncreace];
    if (this->front < this->rear) {
        for (int i = this->front; i < this->rear; ++i) {
            newArray[i] = this->elem[i];
        }
    } else {
        for (int i = 0; i < this->rear; ++i) {
            newArray[i] = this->elem[i];
        }
        for (int i = this->front; i < this->size; ++i) {
            newArray[i + queueIncreace] = this->elem[i];
        }
        this->front += queueIncreace;
    }
    this->size += queueIncreace;
    delete []this->elem;
    this->elem = newArray;
}

// 构造函数
template <typename T>
seqQueue<T>::seqQueue(int sz) : front(0), rear(0), size(sz)
{
    this->elem = new T[maxSize];
    assert(elem != nullptr);
}

// 进入队列，如果队列已满，则先扩容
template <typename T>
void seqQueue<T>::enQueue(const T& x)
{
    if (this->isFull() == true) {
        this->overflowProcess();
    }
    this->elem[rear] = x;
    this->rear = (this->rear + 1) % this->size;
}

// 出队，如果没有数据，返回false
template <typename T>
bool seqQueue<T>::deQueue(T& x)
{
    if (this->isEmpty() == true) return false;
    x = this->elem[this->front];
    this->front = (this->front + 1) % this->size;
    return true;
}

// 得到队首元素
template <typename T>
bool seqQueue<T>::getFront(T& x)
{
    if (this->isEmpty() == true) return false;
    x = this->elem[this->front];
    return true;
}

// 判断是否为空
template <typename T>
bool seqQueue<T>::isEmpty() const
{
    return this->front == this->rear;
}

// 判断是否已满
template <typename T>
bool seqQueue<T>::isFull() const
{
    return (this->rear + 1) % this->size == this->front;
}

// 队列中实际排队个数
template <typename T>
int seqQueue<T>::getSize() const
{
    return (this->rear - this->front) % this->size;
}

// 置空
template <typename T>
void seqQueue<T>::makeEmpty()
{
    this->front = 0;
    this->rear = 0;
}

#endif