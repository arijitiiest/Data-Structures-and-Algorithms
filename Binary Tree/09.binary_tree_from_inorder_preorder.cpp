/*
    Given preorder and inorder traversal of a tree, construct the binary tree.

    Note: You may assume that duplicates do not exist in the tree.

    Example :
        Input :
                Preorder : [1, 2, 3]
                Inorder  : [2, 1, 3]
        Return :
                1
               / \
              2   3
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

void printPreorder(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

Node *makeTree(int pre[], int in[], int left, int right, int &k)
{
    if (left > right)
        return NULL;
    int p;
    for (p = left; p <= right; p++)
        if (in[p] == pre[k])
            break;

    k++;
    Node *node = new Node(in[p]);
    node->left = makeTree(pre, in, left, p - 1, k);
    node->right = makeTree(pre, in, p + 1, right, k);
    return node;
}

int main()
{
    int pre[] = {1, 2, 3};
    int in[] = {2, 1, 3};
    int n = sizeof(in) / sizeof(in[0]);

    int k = 0;
    Node *root = makeTree(pre, in, 0, n - 1, k);

    printPreorder(root);
    cout << endl;
    printInorder(root);
    cout << endl;
}
