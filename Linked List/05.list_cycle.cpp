/*
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

    Try solving it using constant additional space.

    Input : 
                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

    Return the node corresponding to node 3. 
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *detectCycle(Node *head)
{
    Node *temp1 = head, *temp2 = head;
    while (temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
        if (temp1 == temp2)
            break;
    }

    if (temp2 == NULL && temp2->next == NULL)
        return NULL;

    Node *curr = head;
    while (curr != temp1)
    {
        curr = curr->next;
        temp1 = temp1->next;
    }
    return curr;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next->next;

    Node *temp = detectCycle(head);
    if (temp == NULL)
        cout << "No cycle detected\n";
    else
        cout << "Cycle at " << temp->data << endl;
}
