//
//#include "JosephusList.h"
//
//JosephusList::JosephusList(int n) : size(n)
//{
//    int add = 1;
//    PersonNode* temp = new PersonNode();
//    temp->id = add;
//    head = temp;
//    head->next = head;
//
//    while (add < n)
//    {
//        add++;
//        PersonNode* newnode = new PersonNode();
//        newnode->id = add;
//        temp->next = newnode;
//        newnode->next = temp;
//        temp = temp->next;
//    }
//    temp->next = head;
//}
//
//JosephusList::~JosephusList()
//{
//    PersonNode* temp = head->next;
//    while (temp != head)
//    {
//        PersonNode* current = temp;
//        temp = temp->next;
//        delete current;
//    }
//    delete head;
//    size = 0;
//}
//
//void JosephusList::display()
//{
//    PersonNode* temp = head;
//    while (temp->next != head)
//    {
//        cout << temp->id << ",";
//        temp = temp->next;
//    }
//    cout << temp->id << endl;
//}
//
//PersonNode* JosephusList::findTail()
//{
//    PersonNode* temp = head;
//    while (temp->next != head)
//    {
//        temp = temp->next;
//    }
//    return temp;
//}
//
//void JosephusList::deletenode(PersonNode* previous, PersonNode* current)
//{
//    if (current == head)
//        head = head->next;
//
//    previous->next = current->next;
//    cout << "Execution result in: " << endl;
//    cout << current->id << endl;
//    delete current;
//    size--;
//}
//
//int JosephusList::getwinner(int m)
//{
//    PersonNode* token = head;
//    PersonNode* previous = findTail();
//
//    while (size > 1)
//    {
//        int pass = 0;
//        while (pass < m)
//        {
//            previous = token;
//            token = token->next;
//            pass++;
//        }
//        deletenode(previous, token);
//        token = previous->next;
//    }
//    return token->id;
//}
