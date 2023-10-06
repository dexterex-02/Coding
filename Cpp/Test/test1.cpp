#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> v, int n){
    int ans = 0;
    for (int i = 0;i<n;i++){
        if(v[i]>0)
            ans++;
        v[i+1]=v[i+1]-(i+1);
        cout << v[i ] << "\n";
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
    cout << solve(v, n);
    return 0;
}