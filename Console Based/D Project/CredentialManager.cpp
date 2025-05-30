#include "CredentialManager.h"
#include <iostream>
using namespace std;

CredentialManager::CredentialManager() : head(nullptr) {}

CredentialManager::~CredentialManager()
{
    CredentialNode* current = head;
    while (current) {
        CredentialNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void CredentialManager::addCredential() 
{
    string site, username, password;
    cout << "Enter site: ";
    cin >> site;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    addCredential(site, username, password);
}

void CredentialManager::addCredential(const string& site, const string& username, const string& password) 
{
    CredentialNode* newNode = new CredentialNode;
    newNode->site = site;
    newNode->username = username;
    newNode->password = password;
    newNode->next = head;
    head = newNode;
}

CredentialNode* CredentialManager::linearSearch(const string& site) 
{
    CredentialNode* current = head;
    while (current) 
    {
        if (current->site == site) 
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void CredentialManager::viewCredentials()
{
    CredentialNode* current = head;
    while (current) 
    {
        cout << "Site: " << current->site
            << ", Username: " << current->username
            << ", Password: " << current->password << endl;
        current = current->next;
    }
}

string CredentialManager::generatePassword(int length, bool includeSymbols) 
{
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    string pool = chars;
    if (includeSymbols) pool += symbols;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, pool.size() - 1);
    string password;
    for (int i = 0; i < length; ++i) 
    {
        password += pool[distrib(gen)];
    }
    return password;
}

void CredentialManager::addPasswordToHistory(const string& password) 
{
    passwordHistory.push(password);
}

void CredentialManager::addPasswordWithStrength(const string& password, int strength)
{
    strengthHeap.push({ strength, password });
}

string CredentialManager::getStrongestPassword() 
{
    if (!strengthHeap.empty()) {
        return strengthHeap.top().second;
    }
    return "";
}

void CredentialManager::sortCredentials()
{
    mergeSort(&head);
}

CredentialNode* CredentialManager::sortedMerge(CredentialNode* a, CredentialNode* b) 
{
    if (!a) return b;
    if (!b) return a;

    if (a->site <= b->site) 
    {
        a->next = sortedMerge(a->next, b);
        return a;
    }
    else
    {
        b->next = sortedMerge(a, b->next);
        return b;
    }
}

void CredentialManager::frontBackSplit(CredentialNode* source, CredentialNode** frontRef, CredentialNode** backRef) 
{
    CredentialNode* slow = source;
    CredentialNode* fast = source->next;
    while (fast) 
    {
        fast = fast->next;
        if (fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = nullptr;
}

void CredentialManager::mergeSort(CredentialNode** headRef) 
{
    CredentialNode* head = *headRef;
    if (!head || !head->next)
    {
        return;
    }
    CredentialNode* a, * b;
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = sortedMerge(a, b);
}

int CredentialManager::getListSize() 
{
    int count = 0;
    CredentialNode* current = head;
    while (current) 
    {
        count++;
        current = current->next;
    }
    return count;
}

CredentialNode** CredentialManager::listToArray(int& size) 
{
    size = getListSize();
    if (size == 0) return nullptr;
    CredentialNode** arr = new CredentialNode * [size];
    CredentialNode* current = head;
    int index = 0;
    while (current)
    {
        arr[index++] = current;
        current = current->next;
    }
    return arr;
}

CredentialNode* CredentialManager::binarySearch(const string& site) 
{
    sortCredentials(); 
    int size = 0;
    CredentialNode** arr = listToArray(size);
    int left = 0, right = size - 1;
    CredentialNode* result = nullptr;
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid]->site == site)
        {
            result = arr[mid];
            break;
        }
        else if (arr[mid]->site < site)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    delete[] arr;
    return result;
}