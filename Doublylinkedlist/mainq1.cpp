#include "q1.h"

int main() {
    DoubleLinkedList<int> dll;
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(2);
    dll.insertAtTail(1);

    cout << "Original List: ";
    dll.printList();

    dll.reverseLinkList();
    cout << "Reversed List: ";
    dll.printList();

    cout << "Is Palindrome: " << (dll.isPalindrome() ? "Palindrome" : "Not a Palindrome") << endl;

    dll.reorderLinkList();
    cout << "Reordered List: ";
    dll.printList();

    dll.swapNodes(3);
    cout << "After Swapping Nodes: ";
    dll.printList();

    dll.insertAtTail(6);
    dll.insertAtTail(7);
    dll.insertAtTail(8);
    dll.insertAtTail(9);
    dll.insertAtTail(10);

    cout << "List before removing nodes: ";
    dll.printList();

    dll.removeNodes();
    cout << "List after removing nodes: ";
    dll.printList();

    return 0;
}
