/*
    Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, 
    compute how much water it is able to trap after raining.

    Input:
        A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    Output:
        6
*/

#include <bits/stdc++.h>
using namespace std;

// int trap(int arr[], int n)
// {
//     int left[n], right[n];

//     left[0] = arr[0];
//     for (int i = 1; i < n; i++)
//     {
//         left[i] = max(left[i - 1], arr[i]);
//     }

//     right[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         right[i] = max(right[i + 1], arr[i]);
//     }

//     int water = 0;
//     for (int i = 0; i < n; i++)
//     {
//         water += min(left[i], right[i]) - arr[i];
//     }

//     return water;
// }

// Space Optimized
int trap(int arr[], int n)
{
    int left = 0, right = n - 1;
    int water = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] >= maxLeft)
                maxLeft = arr[left];
            else
                water += maxLeft - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= maxRight)
                maxRight = arr[right];
            else
                water += maxRight - arr[right];
            right--;
        }
    }
    return water;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << trap(arr, n) << endl;
}
