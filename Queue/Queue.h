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
    virtual bool isEmpty();
    virtual T& pop();
    void push(const T&);

    virtual const Queue& operator=(const Queue&);
    virtual const Queue& operator=(Queue&&);
    virtual const Queue& operator+(const Queue&);
    virtual const Queue& operator+(const T&);
    virtual bool operator==(const Queue&);
    const T& operator--();
    template<typename R>
    friend std::ostream& operator<<<R>(std::ostream&, const Queue<R>&);
    template<typename R>
    friend void operator>><R>(std::istream&, const Queue<R>&);
private:
    void resize(int new_cap = -1);
    int size;
    int capacity;
    T * head;
};

template<typename T>
class PriorityQueue : public Queue<T>{
public:
    PriorityQueue(){};
    PriorityQueue(const PriorityQueue&);
    PriorityQueue(PriorityQueue&&);
    ~PriorityQueue(){};

    void push(int, T&);//Int to set the object's priority in the queue, push value to queue in container with same priority.
    T& pop();//Pop removes and returns one item from the current queue
    bool isEmpty();

    PriorityQueue& operator=(const PriorityQueue&);
    PriorityQueue& operator=(PriorityQueue&&);
    PriorityQueue& operator+(const PriorityQueue&);
    bool operator==(const PriorityQueue&);
private:
    Queue<T> container[10];//Container number is priority,1 lowest, 10 highest
};

#include "Queue.cpp.h"
#endif 
