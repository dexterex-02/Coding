#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> v;
    int n, value;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> value;
        v.push_back(value);
    }
    vector<int> ans = nextSmallerElement(v, n);
    for(auto i:ans)
        cout << i << " ";
    return 0;
}