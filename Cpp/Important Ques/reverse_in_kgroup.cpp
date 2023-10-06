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

node *kReverse(node *head, int k)
{
    // base call
    if (head == NULL)
    {
        return NULL;
    }

    // step1: reverse first k nodes
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step2: Recursion dekhlega aage ka
    if (next != NULL)
        head->next = kReverse(next, k);

    // step3: return head of reversed list
    return prev;
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
    cin>>k;
    node *ans=kReverse(head, k);
    print(ans);
    return 0;
}