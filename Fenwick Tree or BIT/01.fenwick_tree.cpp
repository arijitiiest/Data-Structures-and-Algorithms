/*
    We have an array arr[0 . . . n-1].
        1. Compute the sum of the first i elements.
        2. Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.
*/

#include <bits/stdc++.h>
using namespace std;

void update(int *BIT, int n, int index, int value)
{
    for (; index <= n; index += index & (-index))
        BIT[index] += value;
}

int query(int *BIT, int index)
{
    int ans = 0;
    for (; index > 0; index -= index & (-index))
        ans += BIT[index];
    return ans;
}

int main()
{
    int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *BIT = new int[n + 1]();
    for (int i = 0; i < n; i++)
    {
        update(BIT, n, i + 1, arr[i]); // index starts with 1 for BIT
    }
    cout << query(BIT, 5) << endl;
    cout << query(BIT, 6) - query(BIT, 1) << endl;
    return 0;
}