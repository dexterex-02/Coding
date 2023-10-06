#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x)
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
            return false;

        else if (front == -1)
            front = rear = 0;

        else if (front == 0 && rear != size)
            front = size - 1;

        else
            front--;

        arr[front] = x;
        return true;
    }

    bool pushRear(int x)
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
            return false;

        else if (front == -1)
            front = rear = 0;

        else if (rear == size - 1 && front != 0)
            rear = 0;

        else
            rear++;

        arr[rear] = x;
        return true;
    }

    int popFront()
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

    int popRear()
    {
        if (front == -1)
            return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
            front = rear = -1;

        else if (rear == 0)
            rear = size - 1;

        else
            rear--;

        return ans;
    }

    int getFront()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (front == -1)
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
            return true;
        else
            return false;
    }
};

int main()
{

    Deque d(5);
    cout << d.isEmpty() << "\n";     // true
    cout << d.pushFront(10) << "\n"; // 10
    cout << d.pushRear(20) << "\n";  // 10 20
    cout << d.pushFront(30) << "\n"; // 30 10 20
    cout << d.pushFront(40) << "\n"; // 40 30 10 20
    cout << d.popRear() << "\n";     // 20    40 30 10
    cout << d.getRear() << "\n";     // 10
    cout << d.getFront() << "\n";    // 40
    cout << d.isFull() << "\n";      // false
    cout << d.popFront() << "\n";    // 40    30 10
    cout << d.pushFront(50) << "\n"; // 50 30 10
    cout << d.pushRear(60) << "\n";  // 50 30 10 60
    cout << d.pushFront(70) << "\n"; // 70 50 30 10 60
    cout << d.pushFront(80) << "\n"; // false as size is 5
    cout << d.isFull() << "\n";      // true
}