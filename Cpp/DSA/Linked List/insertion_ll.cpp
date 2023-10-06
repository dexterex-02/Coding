#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

//*to insert the node at the beginning of the linked list
void InsertheadNode(node *&head, int d)
{

    // new node create
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

//*to insert any node at the end of the list
void InsertTailNode(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        node *temp = new node(data);
        tail->next = temp;
        tail = temp;
    }
}

//*to insert the node at particular position of linked list
void InsertAtPosition(node *&head, node *&tail, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        InsertheadNode(head, d);
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
        InsertTailNode(head, tail, d);
        return;
    }

    // creating a node for d
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int n, value;
    cin >> n;
    while (n--)
    {
        cin >> value;
        InsertTailNode(head, tail, value);
    }
    print(head);
    int k;
    cin >> k >> value;
    InsertAtPosition(head, tail, k, value);
    print(head);
    return 0;
}