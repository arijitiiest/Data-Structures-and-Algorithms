/*
    Find the lowest common ancestor in an unordered binary tree given two values in the tree.

    Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) 
    is the lowest (i.e. deepest) node that has both v and w as descendants. 

    Example:
           _______3______
          /              \
       ___5__          ___1__
      /      \        /      \
      6      _2_     0        8
            /   \
           7     4
    
    the LCA of nodes 5 and 4 is 5
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

bool find(Node *root, int val)
{
    if (!root)
        return false;
    if (root->key == val)
        return true;
    return (find(root->left, val) || find(root->right, val));
}

Node *lca(Node *root, int val1, int val2)
{
    if (!root)
        return NULL;
    if (root->key == val1 || root->key == val2)
        return root;

    Node *L = lca(root->left, val1, val2);
    Node *R = lca(root->right, val1, val2);
    if (L && R)
        return root;
    return L ? L : R;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    int val1 = 5, val2 = 4;

    if (!find(root, val1) || !find(root, val2))
        cout << "Not found\n";
    else
    {
        Node *ans = lca(root, val1, val2);
        if (!ans)
            cout << "Not found\n";
        else
            cout << ans->key << endl;
    }
}
