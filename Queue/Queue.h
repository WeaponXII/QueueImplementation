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
    
    template<typename R>
    friend std::ostream& operator<<<R>(std::ostream&, const Queue<R>&);
    template<typename R>
    friend void operator>><R>(std::istream&, const Queue<R>&);
private:
    void resize(int);
    int size;
    int capacity;
    T * head;
};

template<typename T>
class PriorityQueue : Queue{
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    PriorityQueue(PriorityQueue&&);
    ~PriorityQueue();

    T& pop();
    void push(int);

    PirorityQueue& operator=(const PriorityQueue&);
    PirorityQueue& operator=(PriorityQueue&&);
    PriorityQueue& operator+();
    bool operator==(const Queue&);
private:
    Queue<T> container[10];
};

#include "Queue.cpp.h"
#endif 
