#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};
class LinkedList {
    int length;
    Node* head;
    Node* tail;
public:
    //a
    void prepend(int val) {
        Node* newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }
    //b
    void append(int val)
    {
        Node* newNode = new Node(val);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    //c
    void printList() {
        Node* temp = this->head;
        cout << "\nLinked List:\n ";
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
    //d
    bool search(int val) const
    {
        if (length == 0)
        {
            return false;
        }
        else
        {
            Node* temp = head;
            while (temp->next) {
                if (temp->value == val)
                {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }
    //e
    bool isEmpty()
    {
        if (length == 0)
        {
            return true;
        }
        return false;
    }
    //f
    LinkedList(int val) {
        length = 1;
        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
    }
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    //g
    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    //h
    void deletefirst() {
        if (length == 0)return;
        Node* tep = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete tep;
        length--;
    }
    //i
    void deleteLast()
    {
        if (length == 0)return;
        Node* temp = head;
        Node* pre = temp;
        while (temp->next)
        {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
        length--;
        if (length == 0)
        {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;
    }
    //j
    void insert_after_val(int val1, int val2)
    {
        Node* temp = head;
        Node* pre;
        while (temp->value != val1)
        {
            pre = temp;
            temp = temp->next;
        }
        pre = temp;
        temp = temp->next;
        Node* Newnode = new Node(val2);
        pre->next = Newnode;
        Newnode->next = temp;
        length++;
    }
    //k
    void delete_all_num(int val)
    {
        Node* temp = head;
        Node* p = temp;
        int j = length;
        for (int i = 0; i < j; i++)
        {
            if (temp->value == val)
            {

                if (i == 0)
                {
                    deletefirst();
                    temp = head;
                    p = temp;
                }
                else if (i == j - 1)
                {
                    deleteLast();
                }
                else
                {
                    p->next = temp->next;
                    delete temp;
                    temp = p->next;
                    length--;
                    /* p->next = temp->next;

                     delete temp;
                     temp = p->next;*/
                }

            }
            else
            {
                p = temp;
                temp = temp->next;
            }

        }
    }
    //l
    void removeduplicates() {
        int num;
        Node* temp = head;
        Node* tm = temp;
        for (int i = 0; i < length - 1; i++)
        {
            num = temp->value;
            temp = temp->next;
            tm = temp;
            for (int k = i + 1; k < length; k++)
            {
                if (num == tm->value)
                {
                    tm = tm->next;
                    delete_index(k, num);
                    k--;
                }
                else {
                    tm = tm->next;
                }
            }

        }
    }
    //m
    bool isSorted()
    {
        Node* temp = head;
        Node* pre = temp;
        int j = length;
        while (--j)
        {
            temp = temp->next;
            if (pre->value > temp->value)
            {
                return false;
            }
            pre = temp;
        }
        return true;
    }
    //n
    LinkedList* MergeLinkedLists(LinkedList* L1, LinkedList* L2) {

        if (!L1->isSorted() || !L2->isSorted()) {
            return NULL;

        }
        Node* temp1 = L1->head;
        Node* temp2 = L2->head;

        LinkedList* mergedList = new LinkedList();

        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->value < temp2->value) {
                mergedList->append(temp1->value);

                temp1 = temp1->next;
            }
            else {
                mergedList->append(temp2->value);
                temp2 = temp2->next;
            }
        }

        while (temp1 != NULL) {
            mergedList->append(temp1->value);
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            mergedList->append(temp2->value);
            temp2 = temp2->next;
        }

        return mergedList;
    }
    //o
    void reversePrint() {
        LinkedList* L1 = new LinkedList;
        Node* temp = head;
        while (temp != NULL) {
            L1->prepend(temp->value);
            temp = temp->next;
        }
        L1->printList();
        delete L1;
    }

    // Time Complexity : O(N^2)
    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        }
        else {
            cout << "Head: " << head->value << endl;
        }
    }
    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        }
        else {
            cout << "Tail: " << tail->value << endl;
        }
    }
    void getLength() {
        cout << "Length: " << length << endl;
    }
    Node* get(int index)
    {
        if (length > 0 || length <= length)
        {
            Node* temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
        }
    }
    bool set(int index, int val)
    {
        Node* temp = get(index);
        if (temp) {
            temp->value = val;
            return true;
        }
        return false;
    }
    bool insert(int index, int val)
    {
        if (index<0 || index>length)return false;
        if (index == 0)
        {
            prepend(val);
            return true;
        }
        else if (index == length - 1)
        {
            append(val);
            return true;
        }
        else
        {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }
    }
    void delete_index(int index, int val)
    {
        if (index<0 || index>length)return;
        if (index == 0)
        {
            return deletefirst();

        }
        else if (index == length - 1)
        {
            return deleteLast();
        }
        else {
            Node* pre = get(index - 1);
            Node* temp = pre->next;
            pre->next = temp->next;
            delete temp;
            length--;
        }
    }
};



int main() {

    //a
    LinkedList* L1 = new LinkedList(4);
    //b
    L1->prepend(2);
    L1->prepend(3);
    L1->prepend(7);
    //c
    L1->append(9);
    //d
    L1->prepend(7);
    L1->prepend(8);
    L1->prepend(9);
    //e
    L1->delete_all_num(7);
    //f
    L1->printList();
    //g
    L1->search(2);
    L1->search(9);
    L1->search(10);
    //h
    L1->deletefirst();
    L1->printList();
    //i
    LinkedList* L2 = new LinkedList(1);
    L2->append(8);
    L2->append(3);
    cout << "l2"; L2->printList();
    LinkedList* L3 = new LinkedList(4);
    L3->append(5);
    L3->append(7);
    LinkedList* L4{};
    L4 = L4->MergeLinkedLists(L2, L3);
    L4->printList();
}
