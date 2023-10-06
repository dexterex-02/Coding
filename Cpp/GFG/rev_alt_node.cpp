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
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverse(node* head){
    if(head==NULL || head->next==NULL)
        return head;

    node *curr = head;
    node *forward = NULL;
    node *pre = NULL;
    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = pre;
        pre=curr;
        curr = forward;
    }
    return pre;
}

void rearrange(node *head)
{
    if (!head || !head->next)
        return;
    node *alter = head->next;
    node *temp = head;
    node *head2 = alter;

    while (alter != NULL && alter->next != NULL)
    {
        temp->next = alter->next;
        temp = temp->next;
        alter->next = temp->next;
        alter = alter->next;
    }
    head2=reverse(head2);
    temp->next = head2;
    print(head);
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
    rearrange(head);
    return 0;
}