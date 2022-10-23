#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

template<typename T>
class Queue{
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);
    virtual ~Queue();

    int getSize();
    int getCapacity();

    T& pop();
    void push(const T&);

    virtual const Queue& operator=(const Queue&);
    virtual const Queue& operator=(Queue&&);
    virtual const Queue& operator+(const Queue&);
    virtual const Queue& operator+(const T&);
    virtual bool operator==(const Queue&);
    const T& operator--();
    friend std::ostream& operator<<(std::ostream&, const Queue<T>&);
    friend void operator>>(std::istream&, const Queue<T>&);
private:
    void resize(int new_cap = -1);
    int size;
    int capacity;
    T * head;
};

template<typename T>
class PriorityQueue : Queue<T>{
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    PriorityQueue(PriorityQueue&&);
    ~PriorityQueue();

    void push(int);//Int to set the object's priority in the queue, push to container with same priority.
    Queue<T>& pop();
    PriorityQueue& operator=(const PriorityQueue&);
    PriorityQueue& operator=(PriorityQueue&&);
    PriorityQueue& operator+(const PriorityQueue&);
    bool operator==(const PriorityQueue&);
private:
    Queue<T> container[10];
};

#include "Queue.cpp.h"
#endif 
