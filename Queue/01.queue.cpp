/*
    Queue is a linear structure which follows a particular order in which the operations are performed. 
    The order is First In First Out (FIFO).
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int frontP, rearP, size, capacity;
    int *arr;

public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int item);
    int dequeue();
    int front();
    int rear();
};

Queue::Queue(int capacity)
{
    arr = new int[capacity];
    this->capacity = capacity;
    this->frontP = this->size = 0;
    this->rearP = capacity - 1;
}

Queue::~Queue()
{
    delete[] arr;
}

bool Queue::isFull()
{
    return size == capacity;
}

bool Queue::isEmpty()
{
    return size == 0;
}

void Queue::enqueue(int item)
{
    if (isFull())
    {
        cout << "Overflow\n";
        return;
    }
    rearP = (rearP + 1) % capacity;
    arr[rearP] = item;
    size++;
    cout << item << " enqueued to queue\n";
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return INT_MIN;
    }
    int item = arr[frontP];
    frontP = (frontP + 1) % capacity;
    size--;
    return item;
}

int Queue::front()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return INT_MIN;
    }
    return arr[frontP];
}

int Queue::rear()
{
    if (isEmpty())
    {
        cout << "Underflow\n";
        return INT_MIN;
    }
    return arr[rearP];
}

int main()
{
    Queue queue(1000);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout << queue.dequeue() << " dequeqed from queue\n";
    cout << "Front item is " << queue.front() << endl;
    cout << "Rear item is " << queue.rear() << endl;

    return 0;
}
