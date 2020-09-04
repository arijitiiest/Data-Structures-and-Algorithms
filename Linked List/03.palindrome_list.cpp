/*
    Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

    Notes:
        Expected solution is linear in time and constant in space.
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

// Compare Two Singly Linked List
bool compareLists(Node *temp1, Node *temp2)
{
    while (temp1 != NULL && temp2 != NULL && temp1->data == temp2->data)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL && temp2 == NULL)
        return true;
    return false;
}

// Reverse a Linked List
void reverse(Node **head)
{
    Node *curr = *head, *next, *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Check Linked List Palindrome
bool isPalindrome(Node *head)
{
    if (head == NULL)
        return false;
    if (head->next == NULL)
        return true;

    Node *slow_ptr = head, *fast_ptr = head, *midNode = NULL, *prev_of_slow_ptr, *second_half;
    bool res;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        prev_of_slow_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
    }

    second_half = slow_ptr;
    if (fast_ptr != NULL)
    {
        second_half = slow_ptr->next;
        midNode = slow_ptr;
    }
    prev_of_slow_ptr->next = NULL;

    reverse(&second_half);
    res = compareLists(head, second_half);

    reverse(&second_half);
    if (fast_ptr != NULL)
    {
        prev_of_slow_ptr->next = midNode;
        midNode->next = second_half;
    }
    else
    {
        prev_of_slow_ptr->next = second_half;
    }
    return res;
}

int main()
{
    Node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    // insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    if (isPalindrome(head))
        cout << "List is Palindrome\n";
    else
        cout << "List is not Palindrome\n";
}
