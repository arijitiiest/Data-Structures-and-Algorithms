/*
    Implementation of a doubly linked list.

    A node can be added in 4 ways:
        1. insert at the front of the linked list,
        2. insert after a given node,
        3. insert before a given node,
        4. insert at the end

    A node can be deleted in 2 ways:
        1. delete a node given as key,
        2. delete a node given as index,
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// Insertion

// Insert at the front
void insert_front(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = new Node(data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = (*root);
    (*root)->prev = newNode;
    *root = newNode;
}

// Insert after a given node
void insert_after(Node **root, int key, int data)
{
    Node *temp = (*root);
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Insert before a given node
void insert_before(Node **root, int key, int data)
{
    Node *temp = (*root);
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp == (*root))
    {
        temp->prev = newNode;
        (*root) = newNode;
        return;
    }
    temp->prev->next = newNode;
    temp->prev = newNode;
}

// Insert at the end
void insert_back(Node **root, int data)
{
    if ((*root) == NULL)
    {
        *root = new Node(data);
        return;
    }

    Node *prev, *temp = (*root);
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    newNode->prev = prev;
    prev->next = newNode;
}

// Delete a node given as key
void delete_node(Node **root, int key)
{
    Node *temp = (*root);
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    if (temp == (*root))
    {
        *root = (*root)->next;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Delete a node given as index
void delete_index(Node **root, int index)
{
    Node *temp = (*root);
    if (index == 0)
    {
        *root = (*root)->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Segmentation Fault\n";
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

// Prints the list starting from the given node
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    insert_front(&head, 10);

    insert_after(&head, 10, 20);

    insert_before(&head, 20, 15);

    insert_back(&head, 25);

    insert_front(&head, 9);
    insert_front(&head, 8);
    insert_front(&head, 7);

    cout << "Elements in List after inserting : ";
    printList(head);

    delete_node(&head, 9);

    delete_index(&head, 1);
    delete_index(&head, 0);

    cout << "Elements in List after deleting : ";
    printList(head);

    return 0;
}
