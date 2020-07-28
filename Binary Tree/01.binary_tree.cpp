/*
    Implement Binary Tree.

    Insert: insert a key into the binary tree at first position available in level order.
    Deletion: delete a node from it by making sure that tree shrinks from the bottom (i.e. the deleted node is 
              replaced by bottom most and rightmost node), As order doesn't matter.
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

void insert(Node *node, int key)
{
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (!node->left)
        {
            node->left = new Node(key);
            break;
        }
        else
        {
            q.push(node->left);
        }

        if (!node->right)
        {
            node->right = new Node(key);
            break;
        }
        else
        {
            q.push(node->right);
        }
    }
}

void deletDeepest(Node *node, Node *d_node)
{
    queue<Node *> q;
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (node == d_node)
        {
            node = NULL;
            delete (d_node);
            return;
        }

        if (node->right)
        {
            if (node->right == d_node)
            {
                node->right = NULL;
                delete d_node;
                return;
            }
            else
                q.push(node->right);
        }

        if (node->left)
        {
            if (node->left == d_node)
            {
                node->left = NULL;
                delete d_node;
                return;
            }
            else
                q.push(node->left);
        }
    }
}

Node *deletion(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->key == key)
            return NULL;
        else
            return root;
    }

    // Find the deepest node and the key node
    Node *temp, *key_node = NULL;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->key == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        key_node->key = temp->key;
        deletDeepest(root, temp);
    }

    return root;
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder traversal before insertion:";
    inorder(root);
    cout << endl;

    int key = 12;
    insert(root, key);

    cout << "Inorder traversal after insertion:";
    inorder(root);
    cout << endl;

    root = deletion(root, key);

    cout << "Inorder traversal after deletion :";
    inorder(root);
    cout << endl;

    return 0;
}
