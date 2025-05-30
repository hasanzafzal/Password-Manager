#ifndef BST_H
#define BST_H

#include <string>

class BST {
private:
    struct Node {
        std::string key;  // Change from int to std::string
        Node* left;
        Node* right;
        Node(const std::string& k) : key(k), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insert(Node* node, const std::string& key);  // Change from int to std::string
    Node* search(Node* node, const std::string& key);  // Change from int to std::string
    Node* remove(Node* node, const std::string& key);  // Change from int to std::string
    Node* findMin(Node* node);
    void inorder(Node* node, std::string* result, int& index);

public:
    BST();
    void insert(const std::string& key);  // Change from int to std::string
    bool search(const std::string& key);  // Change from int to std::string
    void remove(const std::string& key);  // Change from int to std::string
    std::string* inorderTraversal(int& size);  // Change from int* to std::string*
};

#endif