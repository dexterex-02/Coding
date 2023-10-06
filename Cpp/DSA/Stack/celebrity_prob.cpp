//! very important question of stack

#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }
    int celeb = s.top();
    int row = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[celeb][i] == 0)
            row++;
    }
    if (row != n)
        return -1;

    int col = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][celeb] == 1)
            col++;
    }
    if (col != n - 1)
        return -1;
    return celeb;
}

int main()
{

    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }
    cout << celebrity(M, n) << endl;
    return 0;
}