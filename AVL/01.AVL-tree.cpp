/*
    Implement AVL tree
*/

#include <bits/stdc++.h>
using namespace std;

// AVL tree Node
class Node
{
public:
    int key;
    Node *left, *right;
    int height;
    Node(int x)
    {
        key = x;
        left = right = NULL;
        height = 1;
    }
};

int getHeight(Node *node)
{
    return node == NULL ? 0 : node->height;
}

int getBalance(Node *node)
{
    return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *node)
{
    Node *x = node->left;
    Node *y = x->right;

    // Perform Rotation
    x->right = node;
    node->left = y;

    // Update Height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *node)
{
    Node *x = node->right;
    Node *y = x->left;

    // Perform Rotation
    x->left = node;
    node->right = y;

    // Update Height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return (new Node(key));

    if (node->key > key)
        node->left = insert(node->left, key);
    else if (node->key < key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Preorder traversal
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the AVL tree is : ";
    preorder(root);
    cout << "\n";

    return 0;
}
