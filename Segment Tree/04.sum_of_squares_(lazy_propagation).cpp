/*
    Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), 
    and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
    The sum of squares over a range with range updates of 2 types:
        1) increment in a range
        2) set all numbers the same in a range.
    Input
        There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
        The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
        2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).
        1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
        0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
    Output
        For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. 
        Intermediate overflow will not occur with proper use of 64-bit signed integer.
    Input:
        2
        4 5
        1 2 3 4
        2 1 4
        0 3 4 1
        2 1 4
        1 3 4 1
        2 1 4
        1 1
        1
        2 1 1
    Output:
        Case 1:
        30
        7
        13
        Case 2:
        1 
*/

#include <bits/stdc++.h>
using namespace std;

struct tree_attrs
{
    int sum_of_squares;
    int sum;
};

struct lazy_attrs
{
    int setter = 0;
    int incrementor = 0;
};

void buildTree(int *arr, tree_attrs *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].sum_of_squares = arr[start] * arr[start];
        tree[treeNode].sum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
    tree[treeNode].sum_of_squares = tree[2 * treeNode].sum_of_squares + tree[2 * treeNode + 1].sum_of_squares;
}

void update_setter(tree_attrs *tree, lazy_attrs *lazy, int start, int end, int treeNode, int left, int right, int val)
{
    // Lazy work
    if (start > end)
    {
        return;
    }

    if (lazy[treeNode].incrementor != 0)
    {
        tree[treeNode].sum_of_squares += 2 * lazy[treeNode].incrementor * tree[treeNode].sum + lazy[treeNode].incrementor * lazy[treeNode].incrementor * (right - left + 1);
        tree[treeNode].sum += lazy[treeNode].incrementor * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].incrementor += lazy[treeNode].incrementor;
            lazy[2 * treeNode + 1].incrementor += lazy[treeNode].incrementor;
        }
        lazy[treeNode].incrementor = 0;
    }
    else if (lazy[treeNode].setter != 0)
    {
        tree[treeNode].sum_of_squares = lazy[treeNode].setter * lazy[treeNode].setter * (right - left + 1);
        tree[treeNode].sum = lazy[treeNode].setter * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].setter += lazy[treeNode].setter;
            lazy[2 * treeNode + 1].setter += lazy[treeNode].setter;
        }
        lazy[treeNode].setter = 0;
    }

    // Completely outside
    if (start > right || end < left)
    {
        return;
    }

    //Completely inside
    if (start >= left && end <= right)
    {
        tree[treeNode].sum_of_squares = (right - left + 1) * val * val;
        tree[treeNode].sum = (right - left + 1) * val;
        if (start != end)
        {
            lazy[2 * treeNode].setter += val;
            lazy[2 * treeNode + 1].setter += val;
        }
        return;
    }
    // Partial overlap
    int mid = (start + end) / 2;
    update_setter(tree, lazy, start, mid, 2 * treeNode, left, right, val);
    update_setter(tree, lazy, mid + 1, end, 2 * treeNode + 1, left, right, val);
    tree[treeNode].sum_of_squares = tree[2 * treeNode].sum_of_squares + tree[2 * treeNode + 1].sum_of_squares;
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
}

void update_incrementor(tree_attrs *tree, lazy_attrs *lazy, int start, int end, int treeNode, int left, int right, int val)
{
    // Lazy work
    if (start > end)
        return;

    if (lazy[treeNode].incrementor != 0)
    {
        tree[treeNode].sum_of_squares += 2 * lazy[treeNode].incrementor * tree[treeNode].sum + lazy[treeNode].incrementor * lazy[treeNode].incrementor * (right - left + 1);
        tree[treeNode].sum += lazy[treeNode].incrementor * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].incrementor += lazy[treeNode].incrementor;
            lazy[2 * treeNode + 1].incrementor += lazy[treeNode].incrementor;
        }
        lazy[treeNode].incrementor = 0;
    }
    else if (lazy[treeNode].setter != 0)
    {
        tree[treeNode].sum_of_squares = lazy[treeNode].setter * lazy[treeNode].setter * (right - left + 1);
        tree[treeNode].sum = lazy[treeNode].setter * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].setter += lazy[treeNode].setter;
            lazy[2 * treeNode + 1].setter += lazy[treeNode].setter;
        }
        lazy[treeNode].setter = 0;
    }

    // Completely outside
    if (start > right || end < left)
        return;
    

    //Completely inside
    if (start >= left && end <= right)
    {
        tree[treeNode].sum_of_squares += (right - left + 1) * val * val + 2 * val * tree[treeNode].sum;
        tree[treeNode].sum += (right - left + 1) * val;
        if (start != end)
        {
            lazy[2 * treeNode].incrementor += val;
            lazy[2 * treeNode + 1].incrementor += val;
        }
        return;
    }
    // Partial overlap
    int mid = (start + end) / 2;
    update_incrementor(tree, lazy, start, mid, 2 * treeNode, left, right, val);
    update_incrementor(tree, lazy, mid + 1, end, 2 * treeNode + 1, left, right, val);
    tree[treeNode].sum_of_squares = tree[2 * treeNode].sum_of_squares + tree[2 * treeNode + 1].sum_of_squares;
    tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
}

tree_attrs query(tree_attrs *tree, lazy_attrs *lazy, int start, int end, int treeNode, int left, int right)
{
    // Lazy work
    if (start > end)
    {
        return {0, 0};
    }
    if (lazy[treeNode].incrementor != 0)
    {
        tree[treeNode].sum_of_squares += 2 * lazy[treeNode].incrementor * tree[treeNode].sum + lazy[treeNode].incrementor * lazy[treeNode].incrementor * (right - left + 1);
        tree[treeNode].sum += lazy[treeNode].incrementor * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].incrementor += lazy[treeNode].incrementor;
            lazy[2 * treeNode + 1].incrementor += lazy[treeNode].incrementor;
        }
        lazy[treeNode].incrementor = 0;
    }
    else if (lazy[treeNode].setter != 0)
    {
        tree[treeNode].sum_of_squares = lazy[treeNode].setter * lazy[treeNode].setter * (right - left + 1);
        tree[treeNode].sum = lazy[treeNode].setter * (right - left + 1);
        if (start != end)
        {
            lazy[2 * treeNode].setter += lazy[treeNode].setter;
            lazy[2 * treeNode + 1].setter += lazy[treeNode].setter;
        }
        lazy[treeNode].setter = 0;
    }

    // Completely Outside
    if (start > right || end < left)
    {
        return {0, 0};
    }

    // Completely Inside
    if (start >= left && end <= right)
    {
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end) / 2;
    tree_attrs left_ans = query(tree, lazy, start, mid, 2 * treeNode, left, right);
    tree_attrs right_ans = query(tree, lazy, mid + 1, end, 2 * treeNode, left, right);
    tree_attrs ans;
    ans.sum_of_squares = left_ans.sum_of_squares + right_ans.sum_of_squares;
    ans.sum = left_ans.sum + right_ans.sum;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int case_no = 1;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        tree_attrs *tree = new tree_attrs[4 * n]();
        lazy_attrs *lazy = new lazy_attrs[4 * n]();
        buildTree(arr, tree, 0, n - 1, 1);

        cout << "Case " << case_no << ":\n"; 
        case_no++;
        while (q--)
        {
            int type_of_operation;
            cin >> type_of_operation;
            if (type_of_operation == 0)
            {
                int left, right, val;
                cin >> left >> right >> val;
                update_setter(tree, lazy, 0, n - 1, 1, left-1, right-1, val);
            }
            else if (type_of_operation == 1)
            {
                int left, right, val;
                cin >> left >> right >> val;
                update_incrementor(tree, lazy, 0, n - 1, 1, left-1, right-1, val);
            }
            else
            {
                int left, right;
                cin >> left >> right;
                cout << query(tree, lazy, 0, n - 1, 1, left-1, right-1).sum_of_squares << endl;
            }
        }
    }
    return 0;
}