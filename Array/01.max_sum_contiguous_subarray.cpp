/*
    Find the contiguous subarray within an array, A of length N which has the largest sum.

    Input:
        A = [1, 2, 3, 4, -10]
    Output:
        10
*/

#include <bits/stdc++.h>
using namespace std;

// Kadane’s Algorithm
int maxSubArray(int arr[], int n)
{
    int maxSum = arr[0], currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum > maxSum)
            maxSum = currentSum;

        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubArray(arr, n) << "\n";
}