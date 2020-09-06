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

void printPostorderIte(Node *node)
{
    stack<Node *> st;

    while (true)
    {
        while (node != NULL)
        {
            st.push(node);
            st.push(node);
            node = node->left;
        }

        if (st.empty())
            return;

        node = st.top();
        st.pop();

        if (!st.empty() && st.top() == node)
            node = node->right;
        else
        {
            cout << node->key << " ";
            node = NULL;
        }
    }
}

void printInorderIte(Node *node)
{
    stack<Node *> st;
    while (node != NULL || !st.empty())
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }

        node = st.top();
        st.pop();

        cout << node->key << " ";

        node = node->right;
    }
}

void printPreorderIte(Node *node)
{
    stack<Node *> st;

    while (!st.empty() || node != NULL)
    {
        while (node != NULL)
        {
            cout << node->key << " ";

            if (node->right)
                st.push(node->right);

            node = node->left;
        }

        if (!st.empty())
        {
            node = st.top();
            st.pop();
        }
    }
}

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
    printPreorderIte(root);
    cout << "\n";

    cout << "Inorder traversal of binary tree is : ";
    printInorderIte(root);
    cout << "\n";

    cout << "Postorder traversal of binary tree is : ";
    printPostorderIte(root);
    cout << "\n";
    return 0;
}