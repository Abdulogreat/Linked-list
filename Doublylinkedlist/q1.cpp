//#ifndef Q1_CPP
//#define Q1_CPP
//
//#include "q1.h"
//
//// Node constructor definition
//template <typename T>
//Node<T>::Node(T val) : data(val), next(nullptr), prev(nullptr) {}
//
//// DoubleLinkedList constructor
//template <typename T>
//DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}
//
//// Destructor to clean up the list
//template <typename T>
//DoubleLinkedList<T>::~DoubleLinkedList() {
//    Node<T>* current = head;
//    while (current) {
//        Node<T>* nextNode = current->next;
//        delete current;
//        current = nextNode;
//    }
//}
//
//// Insert a node at the head of the list
//template <typename T>
//void DoubleLinkedList<T>::insertAtHead(T val) {
//    Node<T>* newNode = new Node<T>(val);
//    if (!head) {
//        head = tail = newNode;
//    }
//    else {
//        newNode->next = head;
//        head->prev = newNode;
//        head = newNode;
//    }
//}
//
//// Insert a node at the tail of the list
//template <typename T>
//void DoubleLinkedList<T>::insertAtTail(T val) {
//    Node<T>* newNode = new Node<T>(val);
//    if (!tail) {
//        head = tail = newNode;
//    }
//    else {
//        tail->next = newNode;
//        newNode->prev = tail;
//        tail = newNode;
//    }
//}
//
//// Reverse the linked list
//template <typename T>
//void DoubleLinkedList<T>::reverseLinkList() {
//    Node<T>* current = head;
//    Node<T>* temp = nullptr;
//    while (current) {
//        temp = current->prev;
//        current->prev = current->next;
//        current->next = temp;
//        current = current->prev;
//    }
//    if (temp) {
//        head = temp->prev;
//    }
//}
//
//// Check if the list is a palindrome
//template <typename T>
//bool DoubleLinkedList<T>::isPalindrome() {
//    Node<T>* left = head;
//    Node<T>* right = tail;
//    while (left && right && left != right && left->prev != right) {
//        if (left->data != right->data) {
//            return false;
//        }
//        left = left->next;
//        right = right->prev;
//    }
//    return true;
//}
//
//// Reorder the list such that the first half and the reversed second half are interleaved
//template <typename T>
//void DoubleLinkedList<T>::reorderLinkList() {
//    if (!head) return;
//
//    Node<T>* slow = head;
//    Node<T>* fast = head;
//    while (fast && fast->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    Node<T>* secondHalf = slow;
//    Node<T>* prev = nullptr;
//    Node<T>* current = secondHalf;
//
//    while (current) {
//        Node<T>* nextNode = current->next;
//        current->next = prev;
//        current->prev = nextNode;
//        prev = current;
//        current = nextNode;
//    }
//
//    secondHalf = prev;
//    Node<T>* firstHalf = head;
//    Node<T>* temp1, * temp2;
//
//    while (firstHalf && secondHalf) {
//        temp1 = firstHalf->next;
//        temp2 = secondHalf->next;
//
//        firstHalf->next = secondHalf;
//        secondHalf->prev = firstHalf;
//
//        secondHalf->next = temp1;
//        if (temp1)
//            temp1->prev = secondHalf;
//
//        firstHalf = temp1;
//        secondHalf = temp2;
//    }
//}
//
//// Swap nodes at positions n from the start and end of the list
//template <typename T>
//void DoubleLinkedList<T>::swapNodes(int n) {
//    if (!head) return;
//
//    Node<T>* first = head;
//    Node<T>* second = head;
//    int length = 0;
//
//    while (second) {
//        length++;
//        second = second->next;
//    }
//
//    if (n > length / 2) n = length - n + 1;
//
//    second = head;
//    for (int i = 1; i < n; i++) {
//        first = first->next;
//    }
//    for (int i = 1; i < length - n + 1; i++) {
//        second = second->next;
//    }
//
//    if (first == second)
//        return;
//
//    Node<T>* firstPrev = first->prev;
//    Node<T>* secondPrev = second->prev;
//
//    if (firstPrev) {
//        firstPrev->next = second;
//    }
//    if (secondPrev) {
//        secondPrev->next = first;
//    }
//
//    swap(first->next, second->next);
//    swap(first->prev, second->prev);
//
//    if (first->next) {
//        first->next->prev = first;
//    }
//
//    if (second->next) {
//        second->next->prev = second;
//    }
//    if (first->prev) {
//        first->prev->next = first;
//    }
//    if (second->prev) {
//        second->prev->next = second;
//    }
//
//    if (first == head) {
//        head = second;
//    }
//    else if (second == head) {
//        head = first;
//    }
//    if (first == tail) {
//        tail = second;
//    }
//    else if (second == tail) {
//        tail = first;
//    }
//}
//
//// Remove nodes based on certain criteria and print sum and product of remaining node values
//template <typename T>
//void DoubleLinkedList<T>::removeNodes() {
//    Node<T>* current = head;
//    int sum = 0;
//    int product = 1;
//    while (current) {
//        int digitSum = 0;
//        T value = current->data;
//        while (value) {
//            digitSum += value % 10;
//            value /= 10;
//        }
//        if (digitSum % 2 == 0) {
//            Node<T>* toDelete = current;
//            if (current->prev) {
//                current->prev->next = current->next;
//            }
//            if (current->next) {
//                current->next->prev = current->prev;
//            }
//            current = current->next;
//            delete toDelete;
//        }
//        else {
//            sum += current->data;
//            product *= current->data;
//            current = current->next;
//        }
//    }
//    cout << "Sum: " << sum << " " "Product: " << product << endl;
//}
//
//// Print the list
//template <typename T>
//void DoubleLinkedList<T>::printList() {
//    Node<T>* current = head;
//    while (current) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//#endif // Q1_CPP
