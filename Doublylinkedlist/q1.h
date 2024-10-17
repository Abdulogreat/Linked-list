#ifndef Q1_H
#define Q1_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T val);
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void insertAtHead(T val);
    void insertAtTail(T val);
    void reverseLinkList();
    bool isPalindrome();
    void reorderLinkList();
    void swapNodes(int n);
    void removeNodes();
    void printList();
};

#include "q1.cpp" // To include the template definitions

#endif // Q1_H
