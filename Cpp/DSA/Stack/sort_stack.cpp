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

void sortedInsert(stack<int> &stack, int num)
{
    // base case
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    // recusrive call
    sortedInsert(stack, num);

    stack.push(n);
}

void sortStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
        return;

    int num = stack.top();
    stack.pop();

    // recursive call
    sortStack(stack);

    sortedInsert(stack, num);
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
    sortStack(st);
    printStack(st);
    return 0;
}