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

node *getMid(node *head)
{
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
node *reverse(node *head)
{

    node *curr = head;
    node *prev = NULL;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(node *head)
{
    if (head->next == NULL)
        return true;

    node *middle = getMid(head);
    node *temp = middle->next;
    middle->next = reverse(temp);

    node *head1 = head;
    node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head2->data != head1->data)
        {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
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
    if(isPalindrome(head))
        cout << "true";
    else
        cout << "false";
    return 0;
}