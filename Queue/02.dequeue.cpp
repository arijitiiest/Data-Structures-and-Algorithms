/*
    Deque or Double Ended Queue is a generalized version of Queue data structure that allows 
    insert and delete at both ends.In previous post we had discussed introduction of deque.
*/

#include <bits/stdc++.h>
using namespace std;

class Deque
{
    int *arr;
    int front, rear, size;

public:
    Deque(int capacity)
    {
        front = -1;
        rear = 0;
        size = capacity;
        arr = new int[size];
    }
    ~Deque()
    {
        delete[] arr;
    }

    // Operations on Dequeue
    void insertfront(int key);
    void insertrear(int key);
    void deletefront();
    void deleterear();
    bool isEmpty();
    bool isFull();
    int getFront();
    int getRear();
};

bool Deque::isEmpty()
{
    return (front == -1);
}

bool Deque::isFull()
{
    return ((front == 0 && rear == size - 1) || front == rear + 1);
}

void Deque::insertfront(int key)
{
    if (isFull())
    {
        cout << "Overflow\n";
        return;
    }

    // Initially Queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        front = (front + size - 1) % size;
    }
    arr[front] = key;
}

void Deque::insertrear(int key)
{
    if (isFull())
    {
        cout << "Overflow\n";
        return;
    }
    // Initially Queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {

        rear = (rear + 1) % size;
    }
    arr[rear] = key;
}

void Deque::deletefront()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return;
    }

    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

void Deque::deleterear()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return;
    }
    // Deque has only one element
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear = (rear + size - 1) % size;
    }
}

int Deque::getFront()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return INT_MIN;
    }
    return arr[front];
}

int Deque::getRear()
{
    if (isEmpty())
    {
        cout << "Queue Underflow\n";
        return INT_MIN;
    }
    return arr[rear];
}

int main()
{
    Deque dq(10);

    dq.insertrear(5);
    cout << "Inserted 5 in rear end\n";

    dq.insertrear(10);
    cout << "Inserted 10 in rear end\n";

    cout << "Rear element is : " << dq.getRear() << endl;

    dq.deleterear();
    cout << "Rear element deleted\n";

    cout << "Rear element is : " << dq.getRear() << endl;

    dq.insertfront(4);
    cout << "Inserted 4 in front end\n";

    cout << "Front element is : " << dq.getFront() << endl;

    dq.deletefront();
    cout << "Front element deleted\n";

    cout << "Front element is : " << dq.getFront() << endl;

    return 0;
}
