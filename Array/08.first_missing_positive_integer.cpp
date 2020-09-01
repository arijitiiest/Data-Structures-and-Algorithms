/*
    Given an unsorted integer array, find the first missing positive integer.

    Given,
        [1,2,0] return 3,

        [3,4,-1,1] return 2,

        [-8, -7, -6] returns 1

    Your algorithm should run in O(n) time and use constant space.
*/

#include <bits/stdc++.h>
using namespace std;

int firstMissingInt(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
            i--;
        }
    }

    for (int i = 0; i < n; i++)
        if (arr[i] != i + 1)
            return i + 1;

    return n + 1;
}

int main()
{
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstMissingInt(arr, n) << endl;
}
