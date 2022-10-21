#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue{
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);
    ~Queue();

    T& pop();
    void push(const T&);
    void print();

private:
    void resize(int);
    int size;
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
private:
    const T**;
};

#endif 
