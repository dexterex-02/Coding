#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (qfront == rear)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        if (rear == size - 1)
            return;

        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        int ans;
        if (qfront == rear)
            return -1;
        else
        {
            ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};

int main()
{
    Queue q;
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        q.enqueue(value);
    }
    cout<<q.front()<<"\n";
    cout << q.dequeue()<<"\n";
    cout<<q.front()<<"\n";
    if(q.isEmpty())
        cout << "queue is empty\n";
    else
        cout << "not empty\n";
}