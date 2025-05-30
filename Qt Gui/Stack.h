#ifndef STACK_H
#define STACK_H

#include <string>  // Include for std::string

class Stack {
private:
    static const int MAX_SIZE = 100;
    std::string data[MAX_SIZE];  // Change to std::string
    int topIndex;

public:
    Stack();
    void push(const std::string& val);  // Change to std::string
    void pop();
    std::string top();  // Change to std::string
    bool isEmpty();
    std::string* getStack(int& size);  // Change to std::string
};

#endif