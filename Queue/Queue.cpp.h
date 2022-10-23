#include "Queue.h"
template<typename T>
Queue<T>::Queue(){
    head = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
Queue<T>::Queue(const Queue& obj){
    size = obj.size;
    capacity = obj.capacity
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] == obj.head[i];
}

template<typename T>
Queue<T>::Queue(Queue&&){
    size = obj.size;
    capacity = obj.capacity
    head = obj.head;
    obj.head = nullptr;
}

template<typename T>
Queue<T>::~Queue(){
    delete[] head;
}

template<typename T>
int Queue<T>::getSize(){return size;}
template<typename T>
int Queue<T>::getCapacity(){return capacity;}

template<typename T>
T& Queue<T>::pop(){
    if(size == 0){
        range_error err("Cannot pop empty Queue.");
        throw(err);
    }
    head++;
    size--;
    return head - 1;
}

template<typename T>
void Queue<T>::push(const T& obj){
    if(size == capacity - 1){
        resize();
    }
    head[size++] = obj;
}

template<typename T>
void Queue<T>::resize(int new_cap = -1){
    if(new_cap < 0)
        capacity += capacity / 2;
    else 
        capacity = new_cap;
    T * swap = new T[size];
    for(int i = 0; i < size; i++)
        swap[i] = head[i];
    delete[] head;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = swap[i];
    delete[] swap;
}

template<typename T>
const Queue<T>& Queue<T>::operator=(const Queue& obj){
    size = obj.size;
    capacity = obj.capacity;
    delete head;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = obj.head[i];
    return *this;
}

template<typename T>
const Queue<T>& Queue<T>::operator=(Queue&& obj){
    size = obj.size;
    capacity = obj.capacity;
    head = obj.head;
    obj.head = nullptr;
}

template<typename T>
const Queue<T>& Queue<T>::operator+(const Queue& obj){
    for(int i = 0; i < obj.size; i++)
        push(obj.head[i]);

    return *this;
}


template<typename T>
const Queue<T>& Queue<T>::operator+(const T& obj){
    push(obj);
    return *this;
}

template<typename T>
bool Queue<T>::operator==(const Queue& obj){
    if(size != obj.size)
        return false;
    if(capacity != obj.capacity)
        return false;
    for(int i = 0; i < size; i++)
        if(head[i] != obj[i])
            return false;
    return true;
}

template<typename R>
friend std::ostream& operator<<<R>(std::ostream& out, const Queue<R>& obj){
    out << "[";
    for(int i = 0; i < size - 1; i++)
        out << head[i] << ", ";
    out << head[size - 1] << "]" << std::endl; 
}

template<typename R>
void operator>>(std::istream& in, const Queue<R>& obj){
    for(int i = 0; i < in.gcount(); i++)
        push(in >>);
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] head;
    size = 0;
    capacity = 0;
    delete[] container;
}
template<typename T>
const PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& obj) {
    size = obj.size;
    capacity = obj.capacity;
    delete[] head;
    head = new T[capacity];
    for (int i = 0; i < size; i++)
        head[i] = obj.head[i];
    for (int i = 0; i < 10; i++)
        container[i] = obj.container[i];
    return *this;
}
template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& obj) {
    size = obj.size;
    capacity = obj.capacity;
    delete[] head;
    head = new T[capacity];
    for (int i = 0; i < size; i++)
        head[i] = obj.head[i];
    for (int i = 0; i < 10; i++)
        container[i] = obj.container[i];
}


template<typename T>
bool PriorityQueue<T>::operator==(const PriorityQueue& obj) {
    if (size != obj.size)
        return false;
    if (capacity != obj.capacity)
        return false;
    for (int i = 0; i < size; i++)
        if (head[i] != obj.head[i])
            return false;
    for (int i = 0; i < 10; i++)
        if (container[i] != obj.container[i])
            return false;
    return true;
}
template<typename T>
const PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue&& obj) {
    size = obj.size;
    capacity = obj.capacity;
    delete head;
    head = new T[capacity];
    for (int i = 0; i < size; i++)
        head[i] = obj.head[i];
    for (int i = 0; i < 10; i++)
        container[i] = obj.container[i];
    return *this;
}
template<typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue&& obj) {
    size = obj.size;
    capacity = obj.capacity;
    delete head;
    head = new T[capacity];
    for (int i = 0; i < size; i++)
        head[i] = obj.head[i];
    for (int i = 0; i < 10; i++)
        container[i] = obj.container[i];
}
template<typename T>
const PriorityQueue<T>& PriorityQueue<T>::operator+(const PriorityQueue& obj)
{
    for (int i = 0; i < 10; i++)
        container[i] + obj.container[i];
}
