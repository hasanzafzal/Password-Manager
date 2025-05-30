#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

class LinkedList {
public:
    // Node that holds account name and password
    struct Node {
        std::string account_name;
        std::string password;
        Node* next;

        Node(const std::string& account, const std::string& pass)
            : account_name(account), password(pass), next(nullptr) {}
    };

    LinkedList();  // Constructor to initialize head
    void add_entry(const std::string& account_name, const std::string& password);  // Method to add entries
    Node* list_entries() const;  // Method to return the head of the linked list
    void set_head(Node* new_head);  // Add this method

private:
    Node* head;  // Head of the linked list
};

#endif // LINKEDLIST_H
