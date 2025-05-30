#ifndef PASSWORDMANAGERBACKEND_H
#define PASSWORDMANAGERBACKEND_H

#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include "LinkedList.h"
#include <string>

class PasswordManagerBackend {
public:
    PasswordManagerBackend();
    void add_entry(const std::string& account_name, const std::string& password);
    bool delete_entry(const std::string& account_name);
    std::string find_entry(const std::string& account_name);
    LinkedList::Node* list_entries() const;

    void save_to_file(const std::string& filename);  // Save entries to a file
    void load_from_file(const std::string& filename);  // Load entries from a file

private:
    Stack stack;
    Queue queue;
    BST bst;
    LinkedList linkedList;
};

#endif // PASSWORDMANAGERBACKEND_H
