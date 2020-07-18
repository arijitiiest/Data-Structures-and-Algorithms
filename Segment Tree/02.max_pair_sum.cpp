/*
    Given an array, find maximum sum pair between a range.
*/

#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, vector<pair<int, int>> &tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = make_pair(arr[start], arr[start]);
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    int firstMax = max(tree[2 * treeNode].first, tree[2 * treeNode + 1].first);
    int secondMax = min(max(tree[2 * treeNode].first, tree[2 * treeNode].second), max(tree[2 * treeNode + 1].first, tree[2 * treeNode + 1].second));
    tree[treeNode] = make_pair(firstMax, secondMax);
}

void updateTree(int *arr, vector<pair<int, int>> &tree, int start, int end, int treeNode, int idx, int value)
{
    if (start == end)
    {
        arr[idx] = value;
        tree[treeNode] = make_pair(arr[start], arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    if (mid >= idx)
        buildTree(arr, tree, start, mid, 2 * treeNode);
    else
        buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    int firstMax = max(tree[2 * treeNode].first, tree[2 * treeNode + 1].first);
    int secondMax = min(max(tree[2 * treeNode].first, tree[2 * treeNode].second), max(tree[2 * treeNode + 1].first, tree[2 * treeNode + 1].second));
    tree[treeNode] = make_pair(firstMax, secondMax);
}

pair<int, int> queryTree(vector<pair<int, int>> tree, int start, int end, int treeNode, int left, int right)
{
    // Completely outside
    if (start > right || end < left)
        return make_pair(INT_MIN, INT_MIN);

    // Completely inside
    if (start >= left && end <= right)
        return tree[treeNode];

    // Partially inside, partially outside
    int mid = (start + end) / 2;
    pair<int, int> ans1 = queryTree(tree, start, mid, 2 * treeNode, left, right);
    pair<int, int> ans2 = queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    int firstMax = max(ans1.first, ans2.first);
    int secondMax = min(max(ans1.first, ans1.second), max(ans2.first, ans2.second));
    return make_pair(firstMax, secondMax);
}

int main()
{
    int arr[] = {5, 2, 7, 1, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<pair<int, int>> tree(4 * n);

    buildTree(arr, tree, 0, n - 1, 1);

    updateTree(arr, tree, 0, n - 1, 1, 2, 10);

    for (int i = 1; i <= 4 * n; i++)
    {
        cout << tree[i].first << " " << tree[i].second << endl;
    }

    pair<int, int> ans = queryTree(tree, 0, n - 1, 1, 2, 4);

    cout << "Ans: " << ans.first << " " << ans.second << endl;

    return 0;
}