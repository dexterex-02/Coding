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

void print(node *&head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *mergeTwoLists(node *head1, node *head2)
{
    node *curr1 = head1;
    node *curr2 = head2;
    node *resh = NULL;
    node *rest = NULL;
    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data <= curr2->data)
        {
            InsertTailNode(resh, rest, curr1->data);
            curr1 = curr1->next;
        }
        else
        {
            InsertTailNode(resh, rest, curr2->data);
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL)
    {
        InsertTailNode(resh, rest, curr1->data);
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        InsertTailNode(resh, rest, curr2->data);
        curr2 = curr2->next;
    }
    return resh;
}


int main()
{
    node *head1 = NULL;
    node *tail1 = NULL;
    int n, value;
    cin >> n;
    while (n--)
    {
        cin >> value;
        InsertTailNode(head1, tail1, value);
    }
    print(head1);

    node *head2 = NULL;
    node *tail2 = NULL;
    cin >> n;
    while (n--)
    {
        cin >> value;
        InsertTailNode(head2, tail2, value);
    }
    print(head2);
    head1 = mergeTwoLists(head1, head2);
    print(head1);
    return 0;
}