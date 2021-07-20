/*
    Hamming distance between two non-negative integers is defined as the number of positions 
    at which the corresponding bits are different.

    Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers 
    in the array. Return the answer modulo 1000000007.

    Input:
        A = [2, 4, 6]
    Output:
        8
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int hammingDiatance(int arr[], int n)
{
    long long ans = 0, count;
    for (int i = 0; i < 31; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
                count++;
        }
        ans = (ans + count * (n - count) * 2) % MOD;
    }
    return ans;
}

int main()
{
    int arr[] = {2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << hammingDiatance(arr, n) << endl;
}
