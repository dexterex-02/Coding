#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int n, int i)
{
    int smallest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}