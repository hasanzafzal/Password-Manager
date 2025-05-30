#include "Stack.h"

Stack::Stack() : topIndex(-1) {}

void Stack::push(const std::string& val) {
    if (topIndex < MAX_SIZE - 1) {
        data[++topIndex] = val;
    }
}

void Stack::pop() {
    if (topIndex >= 0) {
        topIndex--;
    }
}

std::string Stack::top() {
    return (topIndex >= 0) ? data[topIndex] : "";
}

bool Stack::isEmpty() {
    return topIndex == -1;
}

std::string* Stack::getStack(int& size) {
    size = topIndex + 1;
    return data;
}