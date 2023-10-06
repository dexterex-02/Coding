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
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

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

bool isCircularList(node *head)
{
    // empty list
    if (head == NULL)
        return true;

    node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;
    
    if (temp == head)
        return true;

    return false;
}

bool detectLoop(node *head)
{

    if (head == NULL)
        return false;

    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void print(node *&head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data <<  " ";
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
    tail->next = head;
    if (isCircularList(tail))
        cout << " Linked List is Circular in nature" << endl;
    
    else
        cout << "Linked List is not Circular " << endl;
    return 0;
}