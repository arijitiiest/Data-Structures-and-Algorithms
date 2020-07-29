/*
    Binary Search Tree, is a node-based binary tree data structure which has the following properties:
        1. The left subtree of a node contains only nodes with keys lesser than the node’s key.
        2. The right subtree of a node contains only nodes with keys greater than the node’s key.
        3. The left and right subtree each must also be a binary search tree.

        There must be no duplicate nodes.

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

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return new Node(data);

    if (node->data > data)
        node->left = insert(node->left, data);
    else if (node->data < data)
        node->right = insert(node->right, data);

    return node;
}

Node *deleteNode(Node *node, int key)
{
    if (node == NULL)
        return node;

    if (node->data > key)
        node->left = deleteNode(node->left, key);

    else if (node->data < key)
        node->right = deleteNode(node->right, key);

    else
    {
        // Node has only right child or no child
        if (node->left == NULL)
        {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        // Node has only left child
        else if (node->right == NULL)
        {
            Node *temp = node->left;
            free(node);
            return temp;
        }
        // Node has both child
        else
        {
            Node *temp = node->right;
            // get the inorder successor
            while (temp->left != NULL)
                temp = temp->left;

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }
    }

    return node;
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inserted elements : ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 20);
    cout << "Elements after inserting 20 : ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 30);
    cout << "Elements after inserting 30 : ";
    inorder(root);
    cout << "\n";

    root = deleteNode(root, 50);
    cout << "Elements after inserting 50 : ";
    inorder(root);
    cout << "\n";

    return 0;
}
