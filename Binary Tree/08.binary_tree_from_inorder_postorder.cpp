/*
    Given inorder and postorder traversal of a tree, construct the binary tree.

    Note: You may assume that duplicates do not exist in the tree.

    Example :
        Input : 
            Inorder : [2, 1, 3]
            Postorder : [2, 3, 1]
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

void printPostorder(Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

Node *makeTree(int in[], int post[], unordered_map<int, int> mp, int left, int right, int &curr)
{
    if (left > right)
        return NULL;
    int num = post[curr];
    curr--;
    Node *node = new Node(num);
    int pos = mp[num];
    node->right = makeTree(in, post, mp, pos + 1, right, curr);
    node->left = makeTree(in, post, mp, left, pos - 1, curr);
    return node;
}

int main()
{
    int in[] = {2, 1, 3};
    int post[] = {2, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[in[i]] = i;

    int curr = n - 1;
    Node *root = makeTree(in, post, mp, 0, n - 1, curr);

    printInorder(root);
    cout << endl;
    printPostorder(root);
    cout << endl;
}
