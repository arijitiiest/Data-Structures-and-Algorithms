/*
    Given a binary tree, invert the binary tree and return it.

    Input:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    Output:
             1
           /   \
          3     2
         / \   / \
        7   6 5   4
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

Node *invertTree(Node *root)
{
    if (!root)
        return root;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    printInorder(root);
    cout << endl;

    root = invertTree(root);

    printInorder(root);
    cout << endl;
}
