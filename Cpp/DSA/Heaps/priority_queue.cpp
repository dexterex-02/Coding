#include <bits/stdc++.h>
using namespace std;

void printqueue(priority_queue<int, vector<int>, greater<int>> pq, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        pq.push(value);
    }
    printqueue(pq, n);

    return 0;
}