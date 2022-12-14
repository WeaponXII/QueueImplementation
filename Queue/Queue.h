#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

const int MAX_PRIO = 10;

template <typename T>
class Queue{
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);
    virtual ~Queue();

    bool isEmpty() const;

    virtual T& dequeue();   
    virtual void enqueue(const T&);

    virtual Queue& operator=(const Queue&);
    virtual Queue& operator=(Queue&&);
    virtual Queue& operator+(const Queue&);
    virtual Queue& operator+(const T&);
    virtual bool operator==(const Queue&) const;
     
    template <typename R>
    friend std::ostream& operator<<(std::ostream&, const Queue<R>&);
    template <typename R>
    friend std::istream& operator>>(std::istream&, Queue<R>&);
private:
    void resize(int);
    int dequeue_count;
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
     
    T& dequeue() override;
    void enqueue(const T&) override;
    void enqueue(const int, const T&);
    void enqueue(const int, const Queue<T>&);

    PriorityQueue& operator=(const PriorityQueue&);
    PriorityQueue& operator=(PriorityQueue&&);
    PriorityQueue& operator+(const PriorityQueue&);
    bool operator==(const PriorityQueue&) const;

    template <typename R>
    friend std::ostream& operator<<(std::ostream&, const PriorityQueue<R>&);
    template <typename R>
    friend std::istream& operator>>(std::istream&, PriorityQueue<R>&);
private:
    Queue<T> container[MAX_PRIO];
};

#include "Queue.cpp.h"
#endif 
