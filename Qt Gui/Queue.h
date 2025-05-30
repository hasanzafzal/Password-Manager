#ifndef QUEUE_H
#define QUEUE_H

#include <string>  // Include for std::string

class Queue {
private:
    static const int MAX_SIZE = 100;
    std::string data[MAX_SIZE];  // Change to std::string
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue();
    void enqueue(const std::string& val);  // Change to std::string
    void dequeue();
    std::string front();  // Change to std::string
    bool isEmpty();
    std::string* getQueue(int& size);  // Change to std::string
};

#endif