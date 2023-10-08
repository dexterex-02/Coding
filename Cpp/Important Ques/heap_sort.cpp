//!important

#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = (2 * i);
    int right = (2 * i) + 1;
    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int *arr, int n)
{
    int t = n;
    while (t > 1)
    {
        swap(arr[t], arr[1]);
        t--;
        heapify(arr, t, 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    arr[0] = -1;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
