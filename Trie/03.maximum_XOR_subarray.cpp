/*
    Given an array of n integers, find subarray whose xor is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    int val;
    TrieNode *left, *right;
    TrieNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode *root, int val)
{
    TrieNode *current = root;
    for (int i = 31; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            if (current->right == NULL)
                current->right = new TrieNode();
            current = current->right;
        }
        else
        {
            if (current->left == NULL)
                current->left = new TrieNode();
            current = current->left;
        }
    }
    current->val = val;
}

int find(TrieNode *root, int val)
{
    TrieNode *current = root;
    for (int i = 31; i >= 0; i--)
    {
        if (val & (1 << i))
        {
            if (current->left != NULL)
                current = current->left;
            else
                current = current->right;
        }
        else
        {
            if (current->right != NULL)
                current = current->right;
            else
                current = current->left;
        }
    }
    return val ^ current->val;
}

int main()
{
    int A[] = {8, 1, 2, 12};
    int n = sizeof(A) / sizeof(A[0]);

    TrieNode *root = new TrieNode();
    insert(root, 0);
    int max_xor = INT_MIN, xori = 0;
    for (int i = 0; i < n; i++)
    {
        xori ^= A[i];
        insert(root, xori);
        int curr_max = find(root, xori);

        if (max_xor < curr_max)
            max_xor = curr_max;
    }

    cout << max_xor << endl;
}