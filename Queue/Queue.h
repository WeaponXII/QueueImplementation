#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
/*
template<typename T>
class Queue ;
template <typename R>
std::ostream& operator<<(std::ostream&, const Queue<R>&);
template <typename R>
std::istream& operator>>(std::istream&, const Queue<R>&);
*/
const int MAX_PRIO = 10;

template <typename T>
class Queue{
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);
    virtual ~Queue();

    bool isEmpty();

    virtual T& pop();   
    virtual void push(const T&);

    virtual Queue& operator=(Queue&&);
    virtual Queue& operator+(const Queue&);
    virtual Queue& operator=(const Queue&);
    virtual Queue& operator+(const T&);
    virtual const bool operator==(const Queue&);
     
    template <typename R>
    friend std::ostream& operator<<(std::ostream&, const Queue<R>&);
    template <typename R>
    friend std::istream& operator>>(std::istream&, Queue<R>&);
private:
    void resize(int);
    int size;
    int capacity;
    T * head;
};

template <typename T>
class PriorityQueue : public Queue<T>{
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    PriorityQueue(PriorityQueue&&);
     
    T& pop() override;
    void push(const T&) override;
    void push(const int, const T&);
    void push(const int, const Queue<T>&);

    PriorityQueue& operator=(const PriorityQueue&);
    PriorityQueue& operator+(const PriorityQueue&);
    const bool operator==(const PriorityQueue&);

    template <typename R>
    friend std::ostream& operator<<(std::ostream&, const PriorityQueue<R>&);
    template <typename R>
    friend std::istream& operator>>(std::istream&, PriorityQueue<R>&);
private:
    Queue<T> container[MAX_PRIO];
};

#include "Queue.cpp.h"
#endif 
