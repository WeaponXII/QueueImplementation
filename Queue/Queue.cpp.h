template<typename T>
Queue<T>::Queue(){
    size = 0;
    dequeue_count = 0;
    capacity = 5;
    head = new T[capacity];
}

template<typename T>
Queue<T>::Queue(const Queue& obj){
    size = obj.size;
    dequeue_count = 0;
    capacity = obj.capacity;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = obj.head[i];
}

template<typename T>
Queue<T>::Queue(Queue&& obj){
    size = obj.size;
    capacity = obj.capacity;
    head = obj.head;
    obj.head = nullptr;
}

template<typename T>
Queue<T>::~Queue(){
    delete[] (head - dequeue_count);
}

template<typename T>
bool Queue<T>::isEmpty() const{return size == 0;}

template<typename T>
T& Queue<T>::dequeue(){
    if(size == 0){
        std::range_error err("Cannot dequeue empty Queue.");
        throw(err);
    }
    if(size + 1 == capacity || dequeue_count >= capacity)
        resize(capacity * 2);
    size--;
    capacity--;
    dequeue_count++;
    head++;
    return *(head - 1);
}

template<typename T>
void Queue<T>::enqueue(const T& obj){
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
    delete[] (head - dequeue_count);
    dequeue_count = 0;
    head = new T[capacity];
    for(int i = 0; i < size; i++)
        head[i] = swap[i];
    delete[] swap;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& obj){
    size = obj.size;
    capacity = obj.capacity;
    delete[] (head - dequeue_count);
    dequeue_count = 0;
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
    dequeue_count = obj.dequeue_count;
    obj.head = nullptr;

    return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator+(const Queue& obj){
    for(int i = 0; i < obj.size; i++)
        enqueue(obj.head[i]);

    return *this;
}


template<typename T>
Queue<T>& Queue<T>::operator+(const T& obj){
    enqueue(obj);
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
    std::cout << "Enter the length of your input as an integer: ";
    in >> inp_size;
    T swap;
    std::cout <<endl<< "Enter your values: "<<endl;
    for(int i = 0; i < inp_size; i++){
        in >> swap;
        obj.enqueue(swap);
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
T& PriorityQueue<T>::dequeue(){
    int i = 0;
    for(i; i < MAX_PRIO && container[i].isEmpty(); i++);
    return container[i].dequeue();
}

template<typename T>
void PriorityQueue<T>::enqueue(const T& obj){
    int i = MAX_PRIO - 1;
    for(i; 0 < i && container[i].isEmpty(); i--);
    container[i].enqueue(obj);
}

template<typename T>
void PriorityQueue<T>::enqueue(const int prio_level,const T& obj){
    if (prio_level > MAX_PRIO) {
        std::range_error err("Cannot have priority greater than max priority.");
        throw(err);
    }
    else if (prio_level < 1) {
        std::range_error err("Cannot have priority less than 1");
        throw(err);
    }
    container[prio_level-1].enqueue(obj);
}

template<typename T>
void PriorityQueue<T>::enqueue(const int prio_level,const Queue<T>& obj){
    if (prio_level > MAX_PRIO) {
        std::range_error err("Cannot have priority greater than max priority.");
        throw(err);
    }
    else if (prio_level < 1) {
        std::range_error err("Cannot have priority less than 1");
        throw(err);
    }
    container[prio_level-1] + obj;
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
    int inp_prio;
    std::cout << "Enter the priority you want to assign to your input as an integer between 1-10: ";
    in >> inp_prio;
    in.ignore();
    std::cout << MAX_PRIO;
    if (inp_prio > MAX_PRIO) {
        std::range_error err("Cannot have priority greater than max priority");
        throw(err);
    }
    else if (inp_prio < 1) {
        std::range_error err("Cannot have priority less than 1");
        throw(err);
    }
    std::cout << "Enter values that you would like to add to the Priority Queue:" << std::endl;
    in>> obj.container[inp_prio - 1];

    return in;
}
