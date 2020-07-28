/*
    Pre-Order, Post-Order, In-Order traversals in binary tree
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

void printPostorder(Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void printPreorder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal of binary tree is : ";
    printPreorder(root);
    cout << "\n";

    cout << "Inorder traversal of binary tree is : ";
    printInorder(root);
    cout << "\n";

    cout << "Postorder traversal of binary tree is : ";
    printPostorder(root);
    cout << "\n";
    return 0;
}