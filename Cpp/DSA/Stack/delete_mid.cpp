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

void solve(stack<int> &inputStack, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // RECURSIVE CALL
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
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
    deleteMiddle(st, n);
    printStack(st);
    return 0;
}