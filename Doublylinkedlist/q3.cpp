//#ifndef Q3_CPP
//#define Q3_CPP
//
//#include "q3.h"
//
//// Node constructor definition
//template <typename T>
//Node<T>::Node(T val) : data(val), next(nullptr), prev(nullptr) {}
//
//// DoubleLinkedList constructor
//template <typename T>
//DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr) {}
//
//// Function to insert at tail
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
//// Function to count triplets with sum less than or equal to x
//template <typename T>
//int DoubleLinkedList<T>::countTripletsWithSumLessThanOrEqualTo(T x) {
//    if (!head || !head->next || !head->next->next) {
//        return 0;
//    }
//
//    int count = 0;
//
//    for (Node<T>* first = head; first->next->next != nullptr; first = first->next) {
//        Node<T>* second = first->next;
//        Node<T>* third = tail;
//
//        while (second != third && second->prev != third) {
//            T sum = first->data + second->data + third->data;
//            if (sum <= x) {
//                cout << "Triplet: (" << first->data << ", " << second->data << ", " << third->data << ")\n";
//                count++;
//                second = second->next;
//            }
//            else {
//                third = third->prev;
//            }
//        }
//    }
//
//    return count;
//}
//
//// Function to print the list
//template <typename T>
//void DoubleLinkedList<T>::printList() {
//    Node<T>* current = head;
//    while (current) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << "\n";
//}
//
//#endif // Q3_CPP
