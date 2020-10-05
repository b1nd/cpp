#include <stdexcept>

#include <CyclicQueue.h>

CyclicQueue::CyclicQueue() {
    left_ = 0;
    right_ = 0;
    size_ = 0;
    capacity_ = 100;
    arr_ = new int[100];
}

CyclicQueue::CyclicQueue(int capacity) {
    left_ = 0;
    right_ = 0;
    size_ = 0;
    arr_ = new int[capacity_];
    capacity_ = capacity;
}

CyclicQueue::~CyclicQueue() {
    delete[] arr_;
}

// CyclicQueue::CyclicQueue(const CyclicQueue& other) {
//     // todo
//     throw std::runtime_error("Not implemented!");
// }

CyclicQueue& CyclicQueue::operator=(const CyclicQueue& other) {
    CyclicQueue *copied = new CyclicQueue(other.capacity_);
        
    for (int i = 0; i < other.size_; i++) 
        copied->push(other.arr_[i]);
}

void CyclicQueue::push(int item) {
    size_++;
    arr_[++right_] = item;
}

int CyclicQueue::size() const {
    return abs((right_ - left_) % capacity_);
}

int CyclicQueue::pop() {
    size_--;
    return arr_[left_++ % capacity_];
}

int CyclicQueue::front() const {
    return arr_[left_ % capacity_];
}

void CyclicQueue::clear() {
    left_ = 0;
    right_ = 0;
    size_ = 0;
}