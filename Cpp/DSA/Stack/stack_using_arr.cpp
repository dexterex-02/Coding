#include <bits/stdc++.h>
using namespace std;

class Stack
{
    // properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
    }

    void pop()
    {
        if (top >= 0)
            top--;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
            return -1;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    int n, value;
    cin >> n;
    Stack s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        s.push(value);
    }
    s.pop();
    cout << s.peek() << "\n";
    if (s.isEmpty())
        cout << "true";
    else
        cout << "false";
}