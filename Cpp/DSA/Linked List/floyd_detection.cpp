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

//*function to find circular ll
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

//*function to dected loop in ll
bool detectLoop(node *head)
{
    if (head == NULL)
        return false;
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

//*function to find, detect and remove loop in ll using floyd detection
node *floydDetectLoop(node *head)
{

    if (head == NULL)
        return NULL;

    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
            return slow;
    }
    return NULL;
}

node *getStartingNode(node *head)
{

    if (head == NULL)
        return NULL;

    node *intersection = floydDetectLoop(head);
    node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(node *head)
{

    if (head == NULL)
        return;

    node *startOfLoop = getStartingNode(head);
    node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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

    tail->next = head->next;

    if (floydDetectLoop(head) != NULL)
        cout << "Cycle is present " << endl;
    else
        cout << "no cycle" << endl;
    node *loop = getStartingNode(head);
    cout << "loop starts at " << loop->data << endl;
    removeLoop(head);
    print(head);
    return 0;
}