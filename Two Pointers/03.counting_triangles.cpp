/*
    You are given an array of N non-negative integers, A0, A1 ,…, AN-1. Considering each array element Ai as the edge length 
    of some line segment, count the number of triangles which you can form using these array values.

    Notes:
        You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.
        
        Return answer modulo 109 + 7.
    
    Example:
        A = [1, 1, 1, 2, 2]
        Return: 4
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int noOfTriangle(int arr[], int n)
{
    sort(arr, arr + n);
    long long res = 0;
    for (int i = n - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;
        while (left < right)
        {
            if (arr[left] + arr[right] > arr[i])
            {
                res += right - left;
                res %= MOD;
                right--;
            }
            else
                left++;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << noOfTriangle(arr, n) << endl;
}