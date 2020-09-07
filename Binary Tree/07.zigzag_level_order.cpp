/*
    Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, 
    then right to left for the next level and alternate between).

    Input:
                 1
               /   \
              2    3
             / \  / \
            4   5 6  7
           /
          8 
    Output:
        [
            [1],
            [3, 2],
            [4, 5, 6, 7],
            [8]
        ]
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

vector<vector<int>> levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    bool startLeft = true;

    while (!q.empty())
    {
        vector<int> level;
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            Node *root = q.front();
            q.pop();
            nodeCount--;

            level.push_back(root->key);

            if (root->left)
                q.push(root->left);

            if (root->right)
                q.push(root->right);
        }
        if (!startLeft)
            reverse(level.begin(), level.end());

        ans.push_back(level);
        startLeft = !startLeft;
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

    vector<vector<int>> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";

        cout << "\n";
    }
}
