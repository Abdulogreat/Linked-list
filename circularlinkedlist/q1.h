#pragma once
#include <iostream>
using namespace std;

class SinglyCircularLinkedList
{
public:
    class Node
    {
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    SinglyCircularLinkedList() : head(nullptr) {}
    SinglyCircularLinkedList(const SinglyCircularLinkedList& other);
    ~SinglyCircularLinkedList();

    void insert_at_beginning(int val);
    void insert_at_end(int val);
    void delete_from_beginning();
    void delete_from_end();
    void delete_node(int val);
    void delete_next(Node* ptr);
    bool search_list(int val);
    void mid_list();
    void traverse_list();

    class Iterator
    {
    private:
        Node* current;
    public:
        Iterator(Node* start) : current(start) {}
        bool has_next()
        {
            return current != nullptr;
        }
        int next()
        {
            int val = current->data;
            current = current->next;
            return val;
        }
        Iterator& operator++()
        {
            if (current)
            {
                current = current->next;
            }
            return *this;
        }

        int operator*() const
        {
            return current->data;
        }
    };
    Iterator begin() const
    {
        return Iterator(head);
    }

    friend void merge_lists(SinglyCircularLinkedList& list1, SinglyCircularLinkedList& list2);
};

SinglyCircularLinkedList::SinglyCircularLinkedList(const SinglyCircularLinkedList& other)
{
    if (other.head == nullptr)
    {
        head = nullptr;
        return;
    }
    head = new Node(other.head->data);
    Node* current = head;
    Node* otherCurrent = other.head->next;
    while (otherCurrent != other.head)
    {
        current->next = new Node(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    current->next = head;
}

SinglyCircularLinkedList::~SinglyCircularLinkedList()
{
    if (head == nullptr)
        return;
    Node* current = head;
    do
    {
        Node* next = current->next;
        delete current;
        current = next;
    } while (current != head);
}

void SinglyCircularLinkedList::insert_at_beginning(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void SinglyCircularLinkedList::insert_at_end(int val)
{
    Node* newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void SinglyCircularLinkedList::delete_from_beginning()
{
    if (head == nullptr)
        return;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }
}

void SinglyCircularLinkedList::delete_from_end()
{
    if (head == nullptr)
        return;
    if (head->next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        Node* temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }
}

void SinglyCircularLinkedList::delete_node(int val)
{
    if (head == nullptr)
        return;
    if (head->data == val)
    {
        delete_from_beginning();
        return;
    }
    Node* temp = head;
    while (temp->next != head && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next->data == val)
    {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
}

void SinglyCircularLinkedList::delete_next(Node* ptr)
{
    if (ptr == nullptr || ptr->next == nullptr)
        return;
    Node* toDelete = ptr->next;
    ptr->next = ptr->next->next;
    delete toDelete;
}

bool SinglyCircularLinkedList::search_list(int val)
{
    if (head == nullptr)
        return false;
    Node* temp = head;
    do
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

void SinglyCircularLinkedList::mid_list()
{
    if (head == nullptr)
        return;
    Node* slow = head;
    Node* fast = head;
    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;
}

void SinglyCircularLinkedList::traverse_list()
{
    if (head == nullptr) return;
    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}


void merge_lists(SinglyCircularLinkedList& list1, SinglyCircularLinkedList& list2)
{
    SinglyCircularLinkedList mergedList;
    SinglyCircularLinkedList::Node* current1 = list1.head;
    SinglyCircularLinkedList::Node* current2 = list2.head;

    if (current1 == nullptr && current2 == nullptr)
    {
        mergedList.traverse_list();
        return;
    }

    do
    {
        if (current1 != nullptr && (current2 == nullptr || current1->data <= current2->data))
        {
            mergedList.insert_at_end(current1->data);
            if (current1->next != list1.head)
            {
                current1 = current1->next;
            }
            else
            {
                current1 = nullptr;
            }
        }
        else if (current2 != nullptr)
        {
            mergedList.insert_at_end(current2->data);
            if (current2->next != list2.head)
            {
                current2 = current2->next;
            }
            else
            {
                current2 = nullptr;
            }
        }
    } while (current1 != nullptr || current2 != nullptr);

    mergedList.traverse_list();
}




