/*
    Given a linked list, remove the nth node from the end of list and return its head.

    For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note: if n is greater than the size of the list, remove the first node of the list.
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

void insert(Node **root, int data)
{
    Node *newNode = new Node(data);
    if ((*root) == NULL)
    {
        (*root) = newNode;
        return;
    }

    Node *temp, *prev;
    temp = (*root);
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newNode;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

Node *removeNthFromEnd(Node *head, int B)
{
    Node *first = head, *second = head;
    int i = 0;
    while (second != NULL && i < B)
    {
        second = second->next;
        i++;
    }

    if (second == NULL)
    {
        head = head->next;
        return head;
    }

    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return head;
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    printList(head);
    int B = 2;
    head = removeNthFromEnd(head, B);
    printList(head);
}