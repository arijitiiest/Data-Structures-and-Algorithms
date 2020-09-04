/*
    Given an array of integers, every element appears twice except for one. Find that single one.

    Input:
        A = [1, 2, 2, 3, 1]
    Output:
        3
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(int arr[], int n)
{
    int xori = 0;
    for (int i = 0; i < n; i++)
        xori ^= arr[i];
    return xori;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << singleNumber(arr, n) << "\n";
}