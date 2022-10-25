template<typename T>
Queue<T>::Queue(){
    size = 0;
    pop_count = 0;
    capacity = 5;
    head = new T[capacity];
}

template<typename T>
Queue<T>::Queue(const Queue& obj){
    size = obj.size;
    pop_count = 0;
    capacity = obj.capacity;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = obj.head[i];
}

template<typename T>
Queue<T>::Queue(Queue&&){
    size = obj.size;
    capacity = obj.capacity;
    head = obj.head;
    obj.head = nullptr;
}

template<typename T>
Queue<T>::~Queue(){
    delete[] (head - pop_count);
}

template<typename T>
bool Queue<T>::isEmpty() const{return size == 0;}

template<typename T>
T& Queue<T>::pop(){
    if(size == 0){
        range_error err("Cannot pop empty Queue.");
        throw(err);
    }
    if(size + 1 == capacity || pop_count >= capacity)
        resize(capacity * 2);
    size--;
    capacity--;
    pop_count++;
    head++;
    return *(head - 1);
}

template<typename T>
void Queue<T>::push(const T& obj){
    if(size == capacity){
        resize(capacity * 2);
    }
    head[size++] = obj;
}


template<typename T>
void Queue<T>::resize(int new_cap){
    capacity = new_cap;
    T * swap = new T[size];
    for(int i = 0; i < size; i++)
        swap[i] = head[i];
    delete[] (head - pop_count);
    pop_count = 0;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = swap[i];
    delete[] swap;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& obj){
    size = obj.size;
    capacity = obj.capacity;
    delete[] (head - pop_count);
    pop_count = 0;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = obj.head[i];
    return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& obj){
    if(*this  == obj)
        return *this;
    size = obj.size;
    capacity = obj.capacity;
    head = obj.head;
    pop_count = obj.pop_count;
    obj.head = nullptr;

    return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator+(const Queue& obj){
    for(int i = 0; i < obj.size; i++)
        push(obj.head[i]);

    return *this;
}


template<typename T>
Queue<T>& Queue<T>::operator+(const T& obj){
    push(obj);
    return *this;
}

template<typename T>
bool Queue<T>::operator==(const Queue& obj) const{
    if(size != obj.size)
        return false;
    if(capacity != obj.capacity)
        return false;
    for(int i = 0; i < size; i++)
        if(head[i] != obj.head[i])
            return false;
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& obj){
    out << "[";
    for(int i = 0; i < (obj.size - 1); i++)
        out << obj.head[i] << ", ";
    out << obj.head[(obj.size - 1)] << ']';

    return out;
}

// Requires user to enter length of their input first 
template<typename T>
std::istream& operator>>(std::istream& in, Queue<T>& obj){
    int inp_size;
    in >> inp_size;
    T swap;
    for(int i = 0; i < inp_size; i++){
        in >> swap;
        obj.push(swap);
    }
    
    return in;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(){
    for(int i = 0; i < MAX_PRIO; i++){
        container[i] = Queue<T>();
    }
}

template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& obj){
    for(int i = 0; i < MAX_PRIO; i++)
        container[i] = obj.container[i];
}

template<typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue&& obj){
    std::cout << "Priority Queue Moved." << std::endl;
    for(int i = 0; i < MAX_PRIO; i++)
        container[i] = std::move(obj.container[i]);
}

template<typename T>
T& PriorityQueue<T>::pop(){
    int i = 0;
    for(i; i < MAX_PRIO && container[i].isEmpty(); i++);
    return container[i].pop();
}

template<typename T>
void PriorityQueue<T>::push(const T& obj){
    int i = MAX_PRIO - 1;
    for(i; 0 < i && container[i].isEmpty(); i--);
    container[i].push(obj);
}

template<typename T>
void PriorityQueue<T>::push(const int prio_level,const T& obj){
    conatainer[prio_level].push(obj);
}

template<typename T>
void PriorityQueue<T>::push(const int prio_level,const Queue<T>& obj){
    container[prio_level] + obj;
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue& obj){
    for(int i = 0; i < MAX_PRIO; i++)
        container[i] = obj.container[i];
    return *this;
}

template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue&& obj){
    for(int i = 0; i < MAX_PRIO; i++)
        container[i] = std::move(obj.container[i]);
    return *this;
    }


template<typename T>
PriorityQueue<T>& PriorityQueue<T>::operator+(const PriorityQueue& obj){
    for(int i = 0; i < MAX_PRIO; i++)
        container[i] + obj.container[i];
    return *this;
}

template<typename T>
bool PriorityQueue<T>::operator==(const PriorityQueue& obj) const{
    for(int i = 0; i < MAX_PRIO; i++)
        if(!(container[i] == obj.container[i]))
            return false;
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PriorityQueue<T>& obj){
    out << "{";
    for(int i = 0; i < MAX_PRIO; i++){
        if(obj.container[i].isEmpty())
            out << "[P" << i + 1 << "][]";
        else
            out << "[P"<< i + 1 << "]" << obj.container[i];
    }
    out << "}";

    return out;
}

// Requires user to enter length of their input first 
template<typename T>
std::istream& operator>>(std::istream& in, PriorityQueue<T>& obj){
    for(int i = 0; i < MAX_PRIO; i++)
        in >> obj.container[i];

    return in;
}
