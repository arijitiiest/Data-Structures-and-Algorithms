/*
    Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

    Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.

    Input:
                 1
               /   \
              2    3
             / \  / \
            4   5 6  7
           /
          8 
    Output:
        [1, 3, 7, 8]
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

vector<int> rightView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<int> ans;

    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *root = q.front();
            q.pop();
            nodeCount--;

            if (nodeCount == 0)
                ans.push_back(root->key);

            if (root->left)
                q.push(root->left);

            if (root->right)
                q.push(root->right);
        }
    }
    return ans;
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
    root->left->left->left = new Node(8);

    vector<int> ans = rightView(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}
