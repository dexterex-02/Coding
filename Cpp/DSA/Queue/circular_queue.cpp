#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n)
    {
        this->size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return false;

        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;

        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        if (front == -1)
            return -1;

        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    CircularQueue q(n);
    cout << q.enqueue(5) << " ";
    cout << q.enqueue(4) << " ";
    cout << q.enqueue(1) << " ";
    cout << q.dequeue() << " ";
    cout << q.enqueue(7) << " ";
    cout << q.enqueue(12) << " ";
    return 0;
}