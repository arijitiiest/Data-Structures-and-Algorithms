/*
    Given an array of non-negative integers of size N. The task is to find the maximum possible xor between two numbers present in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode *root, int n)
{
    TrieNode *current = root;
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
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
}

int find_max_xor_pair(TrieNode *root, int *A, int n)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        TrieNode *current = root;
        int curr_xor = 0;

        for (int j = 31; j >= 0; j--)
        {
            if (A[i] & (1 << j))
            {
                if (current->left == NULL)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                    curr_xor += pow(2, j);
                }
            }
            else
            {
                if (current->right == NULL)
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                    curr_xor += pow(2, j);
                }
            }
        }

        if (max_xor < curr_xor)
        {
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

int main()
{
    int A[] = {25, 10, 2, 8, 5, 3};
    int n = sizeof(A) / sizeof(A[0]);

    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++)
        insert(root, A[i]);

    cout << find_max_xor_pair(root, A, n) << endl;
    return 0;
}