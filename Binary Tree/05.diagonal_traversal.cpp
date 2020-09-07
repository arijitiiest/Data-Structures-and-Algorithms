/*
    Consider lines of slope -1 passing between nodes.

    Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

    Input:
             1
          /   \
         4      2
        / \      \
       8   5      3
          / \    /
         9   7  6
    Output:
        [1, 2, 3, 4, 5, 7, 6, 8, 9]
    
    Explanation:
        1) Diagonal 1 contains [1, 2, 3]
        2) Diagonal 2 contains [4, 5, 7, 6]
        3) Diagonal 3 contains [8, 9]
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

vector<int> diagonalTraversal(Node *A)
{
    map<int, vector<int>> mp;
    stack<pair<int, Node *>> st;
    st.push({0, A});
    pair<int, Node *> temp;

    while (!st.empty())
    {
        temp = st.top();
        st.pop();

        mp[temp.first].push_back(temp.second->key);

        if (temp.second->right)
            st.push({temp.first, temp.second->right});
        if (temp.second->left)
            st.push({temp.first + 1, temp.second->left});
    }

    vector<int> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i < it->second.size(); i++)
            ans.push_back(it->second[i]);
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(2);
    root->left->left = new Node(8);
    root->left->right = new Node(5);
    root->right->right = new Node(3);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(6);

    vector<int> ans = diagonalTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
