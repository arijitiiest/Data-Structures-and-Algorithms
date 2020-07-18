/*
    Given a array of n, you are given queries of update at an index and sum of a given range.
*/

#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int value)
{
    if (start == end)
    {
        arr[idx] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (mid >= idx)
    {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, value);
    }
    else
    {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    }

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int queryTree(int *tree, int start, int end, int treeNode, int left, int right)
{
    // Completely outside
    if (start > right || end < left)
        return 0;

    // Completely inside
    if (start >= left && end <= right)
        return tree[treeNode];

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    int ans1 = queryTree(tree, start, mid, 2 * treeNode, left, right);
    int ans2 = queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);
    return ans1 + ans2;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tree[4 * n];

    buildTree(arr, tree, 0, n - 1, 1);

    updateTree(arr, tree, 0, n - 1, 1, 2, 10);

    for (int i = 1; i <= 4 * n; i++)
        cout << tree[i] << " ";
    cout << endl;

    cout << queryTree(tree, 0, n - 1, 1, 2, 4) << endl;
}