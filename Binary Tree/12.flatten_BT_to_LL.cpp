/*
    Given a binary tree, flatten it to a linked list in-place.

    Example:
             1
            / \
           2   5
          / \   \
         3   4   6
    Output:
       1
        \
         2
          \
           3
            \
             4
              \
               5
                \
                 6
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

Node *flatten(Node *root)
{
    if (!root)
        return root;

    Node *head = root;
    while (root)
    {
        if (root->left)
        {
            Node *rightSubTree = root->left;
            while (rightSubTree->right)
                rightSubTree = rightSubTree->right;
            rightSubTree->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
    return head;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    printInorder(root);
    cout << endl;

    root = flatten(root);

    printInorder(root);
    cout << endl;
}
