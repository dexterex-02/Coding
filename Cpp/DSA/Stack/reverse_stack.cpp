#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &s, int element)
{
    // basecase
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    // recursive call
    reverseStack(stack);

    insertAtBottom(stack, num);
}

int main()
{
    stack<int> st;
    int n,value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        st.push(value);
    }
    printStack(st);
    reverseStack(st);
    printStack(st);
    return 0;
}