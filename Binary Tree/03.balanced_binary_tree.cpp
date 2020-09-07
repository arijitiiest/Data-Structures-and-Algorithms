/*
    Given a binary tree, determine if it is height-balanced.

    Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1
*/

#include <bits/stdc++.h>
using namespace std;

bool ans;

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

int height(Node *root, int d)
{
    if (root == NULL)
        return d - 1;

    int l = height(root->left, d + 1);
    int r = height(root->right, d + 1);

    if (abs(l - r) > 1)
    {
        ans = false;
        return 0;
    }
    return max(l, r);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    /*
           10
       11      9
    7       15    8
    */

    ans = true;
    int k = height(root, 0);

    if (ans)
        cout << "Height Balanced\n";
    else
        cout << "Not Height Balanced\n";
}
