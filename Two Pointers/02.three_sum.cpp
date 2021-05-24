/*
    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
    Return the sum of the three integers.

    Assume that there will only be one solution

    Example:
        S = {-1 2 1 -4}
        target = 1

        The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(int arr[], int n, int target)
{
    if (n < 3)
        return 0;

    sort(arr, arr + n);

    int sum, minDiff = INT_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int temp = arr[i] + arr[left] + arr[right];
            int diff = abs(temp - target);
            if (diff == 0)
                return target;

            if (diff < minDiff)
            {
                minDiff = diff;
                sum = temp;
            }
            if (temp < target)
                left++;
            else
                right--;
        }
    }
    return sum;
}

int main()
{
    int arr[] = {-1, 2, 1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    cout << threeSumClosest(arr, n, target) << endl;
}
