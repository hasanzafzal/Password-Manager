#include "Queue.h"

Queue::Queue() : frontIndex(0), rearIndex(-1), count(0) {}

void Queue::enqueue(const std::string& val) {
    if (count < MAX_SIZE) {
        rearIndex = (rearIndex + 1) % MAX_SIZE;
        data[rearIndex] = val;
        count++;
    }
}

void Queue::dequeue() {
    if (count > 0) {
        frontIndex = (frontIndex + 1) % MAX_SIZE;
        count--;
    }
}

std::string Queue::front() {
    return (count > 0) ? data[frontIndex] : "";
}

bool Queue::isEmpty() {
    return count == 0;
}

std::string* Queue::getQueue(int& size) {
    size = count;
    static std::string temp[MAX_SIZE];
    for (int i = 0; i < count; ++i) {
        temp[i] = data[(frontIndex + i) % MAX_SIZE];
    }
    return temp;
}