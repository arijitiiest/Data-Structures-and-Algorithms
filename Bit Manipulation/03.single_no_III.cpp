/*
    Given an array of integers, every element appears thrice except for one which occurs once.

    Find that element which does not appear thrice.

    Input:
        A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
    Output:
        4
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(int arr[], int n)
{
    int count[32] = {0};
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < n; j++)
            if ((arr[j] >> i) & 1)
                count[i]++;
        result |= ((count[i] % 3) << i);
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << singleNumber(arr, n) << "\n";
}