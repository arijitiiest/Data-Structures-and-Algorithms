/*
    Implementation of a singly linked list.

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
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Insertion

// Insert at the front
void insert_front(Node **root, int data)
{
    Node *newNode = new Node(data);
    newNode->next = (*root);
    (*root) = newNode;
}

// Insert after a given node
void insert_after(Node **root, int key, int data)
{
    Node *temp = (*root);
    while (temp != NULL)
    {
        if (temp->data == key)
            break;
        temp = temp->next;
    }

    if (temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    // Insert after key node
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Insert before a given node
void insert_before(Node **root, int key, int data)
{
    Node *temp, *prev;
    temp = prev = (*root);
    while (temp != NULL)
    {
        if (temp->data == key)
            break;
        prev = temp;
        temp = temp->next;
    }

    if (temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    // Insert before key node
    Node *newNode = new Node(data);
    if (temp == (*root))
    {
        newNode->next = (*root);
        (*root) = newNode;
    }
    else
    {
        prev->next = newNode;
        newNode->next = temp;
    }
}

// Insert at the end
void insert_back(Node **root, int data)
{
    Node *newNode = new Node(data);
    if ((*root) == NULL)
    {
        (*root) = newNode;
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

// Delete a node given as key
void delete_node(Node **root, int key)
{
    Node *prev, *temp = (*root);

    if (temp != NULL && temp->data == key)
    {
        *root = (*root)->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data != key)
    {
        cout << key << " not found\n";
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// Delete a node given as index
void delete_index(Node **root, int index)
{
    if ((*root) == NULL)
        return;

    Node *temp = (*root);

    if (index == 0)
    {
        (*root) = temp->next;
        free(temp);
        return;
    }

    // previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < index - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Segmentation Fault\n";
        return;
    }

    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
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
