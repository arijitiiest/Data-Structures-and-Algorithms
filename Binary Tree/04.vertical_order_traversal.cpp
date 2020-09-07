/*
    Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

    NOTE:
        1. If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal 
        of tree comes first in the output.
        
        2. Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be 
        the nodes on the rightmost vertical line.

    Input:
             6
           /   \
          3     7
         / \     \
        2   5     9
    Output:
        [
            [2],
            [3],
            [6, 5],
            [7],
            [9]
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

vector<vector<int>> verticalOrderTraversal(Node *A)
{
    vector<vector<int>> v;
    if (A == NULL)
        return v;

    queue<pair<Node *, int>> q;
    q.push({A, 0});

    map<int, vector<int>> mp;
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        if (temp.first->left)
            q.push({temp.first->left, temp.second - 1});

        if (temp.first->right)
            q.push({temp.first->right, temp.second + 1});

        mp[temp.second].push_back(temp.first->key);
    }

    for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++)
        v.push_back(it->second);

    return v;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right = new Node(7);
    root->right->right = new Node(9);

    vector<vector<int>> ans = verticalOrderTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
