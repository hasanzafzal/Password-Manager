#include "PasswordManagerBackend.h"
#include <fstream>
#include <sstream>

PasswordManagerBackend::PasswordManagerBackend() {
    // Load entries from file on initialization
    load_from_file("passwords.txt");
}

void PasswordManagerBackend::add_entry(const std::string& account_name, const std::string& password) {
    stack.push(account_name + ":" + password);
    queue.enqueue(account_name + ":" + password);
    bst.insert(account_name);
    linkedList.add_entry(account_name, password);
}

std::string PasswordManagerBackend::find_entry(const std::string& account_name) {
    LinkedList::Node* entries = linkedList.list_entries();
    while (entries) {
        if (entries->account_name == account_name) {
            return entries->password;
        }
        entries = entries->next;
    }
    return "";
}

bool PasswordManagerBackend::delete_entry(const std::string& account_name) {
    LinkedList::Node* entries = linkedList.list_entries();
    LinkedList::Node* prev = nullptr;

    while (entries) {
        if (entries->account_name == account_name) {
            if (prev) {
                prev->next = entries->next;  // Skip the current node
            } else {
                linkedList.set_head(entries->next);  // Update head if it's the first node
            }
            delete entries;  // Free memory
            return true;
        }
        prev = entries;
        entries = entries->next;
    }
    return false;  // Entry not found
}

LinkedList::Node* PasswordManagerBackend::list_entries() const {
    return linkedList.list_entries();
}

void PasswordManagerBackend::save_to_file(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        return;
    }

    LinkedList::Node* entries = linkedList.list_entries();
    while (entries) {
        outFile << entries->account_name << ":" << entries->password << "\n";
        entries = entries->next;
    }

    outFile.close();
}

void PasswordManagerBackend::load_from_file(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string account_name, password;
        if (std::getline(iss, account_name, ':') && std::getline(iss, password)) {
            add_entry(account_name, password);
        }
    }

    inFile.close();
}
