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

void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();
    solve(s, x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
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
    int x;
    cin >> x;
    printStack(pushAtBottom(st, x));
    return 0;
}