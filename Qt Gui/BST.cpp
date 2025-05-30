#include "BST.h"

BST::BST() : root(nullptr) {}

BST::Node* BST::insert(Node* node, const std::string& key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}

BST::Node* BST::search(Node* node, const std::string& key) {
    if (!node || node->key == key) return node;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
}

BST::Node* BST::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

BST::Node* BST::remove(Node* node, const std::string& key) {
    if (!node) return node;
    if (key < node->key) node->left = remove(node->left, key);
    else if (key > node->key) node->right = remove(node->right, key);
    else {
        if (!node->left) return node->right;
        else if (!node->right) return node->left;
        Node* temp = findMin(node->right);
        node->key = temp->key;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

void BST::inorder(Node* node, std::string* result, int& index) {
    if (!node) return;
    inorder(node->left, result, index);
    result[index++] = node->key;
    inorder(node->right, result, index);
}

void BST::insert(const std::string& key) {
    root = insert(root, key);
}

bool BST::search(const std::string& key) {
    return search(root, key) != nullptr;
}

void BST::remove(const std::string& key) {
    root = remove(root, key);
}

std::string* BST::inorderTraversal(int& size) {
    static std::string result[100];
    size = 0;
    inorder(root, result, size);
    return result;
}