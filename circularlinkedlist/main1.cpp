#include"Q1.h"
int main()
{
    SinglyCircularLinkedList list;

    list.insert_at_end(2);
    list.insert_at_end(3);
    list.insert_at_end(4);
    list.insert_at_end(5);
    list.insert_at_end(6);

    list.insert_at_beginning(1);
    list.insert_at_beginning(19);
    cout << "List after inserting 19 and 1 at the start: ";
    list.traverse_list();

    list.insert_at_end(7);
    list.insert_at_end(8);
    list.insert_at_end(9);
    cout << "List after inserting 7, 8, and 9 at the end: ";
    list.traverse_list();

    list.delete_from_beginning();
    cout << "List after deleting 19 from the start: ";
    list.traverse_list();

    list.delete_from_end();
    cout << "List after deleting 9 from the end: ";
    list.traverse_list();

    list.delete_node(5);
    cout << "List after deleting 5: ";
    list.traverse_list();


    list.delete_next(list.head);
    cout << "List after deleting the next node of head: ";
    list.traverse_list();

    bool found = list.search_list(3);
    cout << "Element 3 " << (found ? "found" : "not found") << " in the list." << endl;

    list.mid_list();

    cout << "Final list: ";
    list.traverse_list();

    SinglyCircularLinkedList list2;
    list2.insert_at_end(10);
    list2.insert_at_end(11);
    list2.insert_at_end(12);
    cout << "Merging two lists: ";
    merge_lists(list, list2);
    return 0;
}