#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

// traversing a linked list
void print(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// gives length of Linked List
int getLength(node *head)
{
    int len = 0;
    node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void insertAtHead(node *&tail, node *&head, int d)
{

    // empty list
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(node *&tail, node *&head, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(node *&tail, node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(tail, head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    // creating a node for d
    node *nodeToInsert = new node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;

        delete curr;
    }
}

int main()
{

    node *head = NULL;
    node *tail = NULL;

    print(head);
    // cout << getLength(head) << endl;

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtHead(tail, head, 8);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtTail(tail, head, 25);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    deleteNode(7, head);
    print(head);
    cout << "head  " << head->data << endl;
    cout << "tail  " << tail->data << endl;

    return 0;
}
