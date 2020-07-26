/*
    Stack is a linear data structure which follows a particular order in which the operations are performed. 
    The order may be LIFO(Last In First Out) or FILO(First In Last Out).
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack
{
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow\n";
        return false;
    }
    else
    {
        arr[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = arr[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element is " << s.peek() << endl;
    cout << s.pop() << " Popped from stack\n";
    cout << "Top element is " << s.peek() << endl;
}
