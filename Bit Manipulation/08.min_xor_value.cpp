/*
    Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.
    Input:
        A = [0, 2, 5, 7]
    Output :
        2
*/

#include <bits/stdc++.h>
using namespace std;

int findXor(int arr[], int n)
{
    sort(arr, arr + n);
    int minXor = INT_MAX;

    for (int i = 0; i < n - 1; i++)
        minXor = min(minXor, arr[i] ^ arr[i + 1]);

    return minXor;
}

int main()
{
    int arr[] = {0, 2, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findXor(arr, n) << "\n";
}