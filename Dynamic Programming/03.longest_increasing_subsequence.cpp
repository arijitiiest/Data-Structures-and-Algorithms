/*
    Given an 1D integer array A of length N, find the length of longest subsequence which is increasing.

    Input:
        A = [1, 11, 2, 10, 4, 5, 2, 1]
    Output:
        4
*/

#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    return *max_element(lis, lis + n);
}

int main()
{
    int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << LIS(arr, n) << endl;
}
