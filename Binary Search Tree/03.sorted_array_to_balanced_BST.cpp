/*
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node *makeTree(int arr[], int left, int right)
{
    if (left > right)
        return NULL;
    else if (left == right)
        return new Node(arr[left]);
    else
    {
        int mid = (left + right) / 2;
        Node *node = new Node(arr[mid]);
        node->left = makeTree(arr, left, mid - 1);
        node->right = makeTree(arr, mid + 1, right);
        return node;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = makeTree(arr, 0, n - 1);

    printInorder(root);
    cout << endl;
}
