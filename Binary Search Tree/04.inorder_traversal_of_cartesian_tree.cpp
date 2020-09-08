/*
    Given an inorder traversal of a cartesian tree, construct the tree.

    Cartesian tree : is a heap ordered binary tree, where the root is greater than all the elements in the subtree. 
 
    Note: You may assume that duplicates do not exist in the tree.

    Example:
        Input : [1 2 3]
        Return :   
                3
                /
               2
              /
             1
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

int getMax(int arr[], int left, int right)
{
    int maxi = left;
    for (int i = left; i <= right; i++)
        if (arr[i] > arr[maxi])
            maxi = i;
    return maxi;
}

Node *makeTree(int arr[], int left, int right)
{
    if (left > right)
        return NULL;

    int idx = getMax(arr, left, right);

    Node *node = new Node(arr[idx]);
    node->left = makeTree(arr, left, idx - 1);
    node->right = makeTree(arr, idx + 1, right);
    return node;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = makeTree(arr, 0, n - 1);
    
    printInorder(root);
    cout << endl;
}
