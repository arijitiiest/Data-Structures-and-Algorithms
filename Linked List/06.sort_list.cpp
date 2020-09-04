/*
    Sort a linked list in O(n log n) time using constant space complexity.

    Input : 1 -> 5 -> 4 -> 3
    Returned list : 1 -> 3 -> 4 -> 5
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

Node *mergeLists(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node *head = NULL;
    if (left->data < right->data)
    {
        head = left;
        left = left->next;
    }
    else
    {
        head = right;
        right = right->next;
    }

    Node *p = head;
    while (left && right)
    {
        if (left->data < right->data)
        {
            p->next = left;
            left = left->next;
        }
        else
        {
            p->next = right;
            right = right->next;
        }
        p = p->next;
    }

    if (left)
        p->next = left;

    if (right)
        p->next = right;

    return head;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // find the middle place
    Node *p1 = head, *p2 = head->next;
    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = p1->next;
    p1->next = NULL;

    return mergeLists(sortList(head), sortList(p2));
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 3);

    printList(head);
    head = sortList(head);
    printList(head);
}
