#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = (2 * i)+1;
    int right = (2 * i) + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> merge(vector<int> arr1, vector<int> arr2, int n, int m){
    vector<int> ans;
    for(auto i:arr1)
        ans.push_back(i);
    for (auto i : arr2)
        ans.push_back(i);

    int size = ans.size();
    for (int i = (size / 2) - 1; i >= 0;i--){
        heapify(ans, size, i);
    }
    return ans;
}

int main()
{
    vector<int> v1;
    int n, value, m;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> value;
        v1.push_back(value);
    }
    vector<int> v2;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> value;
        v2.push_back(value);
    }
    vector<int> ans = merge(v1, v2, n, m);
    for(auto i:ans)
        cout << i << " ";
    cout << endl;
    return 0;
}