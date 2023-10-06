#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

queue<int> rev(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main()
{
    queue<int> q;
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.push(value);
    }
    printQueue(q);
    q = rev(q);
    printQueue(q);
    return 0;
}