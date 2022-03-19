#ifndef QUEUE_HPP
#define QUEUE_HPP

const int maxSize = 50;

template <class T>
class Queue
{
public:
    Queue() {};
    ~Queue() {};
    virtual void enQueue(const T& x) = 0;
    virtual bool deQueue(T& x) = 0;
    virtual bool getFront(T& x) = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual int getSize() const = 0;
    virtual void makeEmpty() = 0;
};

#endif