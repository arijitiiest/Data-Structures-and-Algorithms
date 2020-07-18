/*
    Given an array, find maximum subarray sum pair between a range.
*/

#include <bits/stdc++.h>
using namespace std;

struct attrs
{
    int max_sum;
    int total_sum;
    int best_prefix_sum;
    int best_suffix_sum;
};

void buildTree(int *arr, attrs *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].max_sum = arr[start];
        tree[treeNode].total_sum = arr[start];
        tree[treeNode].best_prefix_sum = arr[start];
        tree[treeNode].best_suffix_sum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    attrs left = tree[2 * treeNode];
    attrs right = tree[2 * treeNode + 1];

    tree[treeNode].total_sum = left.total_sum + right.total_sum;
    tree[treeNode].max_sum = max(left.max_sum,
                                 max(right.max_sum,
                                     max(left.total_sum + right.best_prefix_sum,
                                         max(left.best_suffix_sum + right.total_sum, left.best_suffix_sum + right.best_prefix_sum))));
    tree[treeNode].best_prefix_sum = max(left.total_sum + right.best_prefix_sum, left.best_prefix_sum);
    tree[treeNode].best_suffix_sum = max(left.best_suffix_sum + right.total_sum, right.best_suffix_sum);
}

attrs queryTree(attrs *tree, int start, int end, int treeNode, int left, int right)
{
    // Completely outside
    if (start > right || end < left)
    {
        attrs ans;
        ans.total_sum = 0;
        ans.max_sum = 0;
        ans.best_prefix_sum = 0;
        ans.best_suffix_sum = 0;
        return ans;
    }

    // Completely inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }

    // Partially inside, partially outside
    int mid = (start + end) / 2;
    attrs ans1 = queryTree(tree, start, mid, 2 * treeNode, left, right);
    attrs ans2 = queryTree(tree, mid + 1, end, 2 * treeNode + 1, left, right);

    attrs ans;
    ans.total_sum = ans1.total_sum + ans2.total_sum;
    ans.max_sum = max(ans1.max_sum,
                      max(ans2.max_sum,
                          max(ans1.total_sum + ans2.best_prefix_sum,
                              max(ans1.best_suffix_sum + ans2.total_sum, ans1.best_suffix_sum + ans2.best_prefix_sum))));
    ans.best_prefix_sum = max(ans1.total_sum + ans2.best_prefix_sum, ans1.best_prefix_sum);
    ans.best_suffix_sum = max(ans1.best_suffix_sum + ans2.total_sum, ans2.best_suffix_sum);
    return ans;
}

int main()
{
    int arr[] = {1, -4, 3, 9, -5, 6, 5, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    attrs *tree = new attrs[4 * n];

    buildTree(arr, tree, 0, n - 1, 1);

    attrs ans =  queryTree(tree, 0, n - 1, 1, 2, 4);
    cout << ans.max_sum << endl;
    return 0;
}
