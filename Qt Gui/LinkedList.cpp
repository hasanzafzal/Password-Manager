#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add_entry(const std::string& account_name, const std::string& password) {
    Node* newNode = new Node(account_name, password);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

LinkedList::Node* LinkedList::list_entries() const {
    return head;
}

void LinkedList::set_head(Node* new_head) {
    head = new_head;  // Update the head pointer
}
