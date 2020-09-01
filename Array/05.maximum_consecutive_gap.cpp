/*
    Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

    Try to solve it in linear time/space

    Input : [1, 10, 5]
    Output : 5 
*/

#include <bits/stdc++.h>
using namespace std;

int findConsecutiveGap(int arr[], int n)
{
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, arr[i]);
        minVal = min(minVal, arr[i]);
    }

    int gap = (maxVal - minVal) / (n - 1);

    if (gap == 0)
        return maxVal - minVal;

    vector<int> forMin(n, INT_MAX);
    vector<int> forMax(n, INT_MIN);

    for (int i = 0; i < n; i++)
    {
        int bucket = (int)((arr[i] - minVal) / gap);
        forMax[bucket] = max(forMax[bucket], arr[i]);
        forMin[bucket] = min(forMin[bucket], arr[i]);
    }

    int max_diff = 0, idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (forMax[i] > 0)
        {
            max_diff = max(max_diff, forMin[i] - forMax[idx]);
            idx = i;
        }
    }

    return max_diff;
}

int main()
{
    int arr[] = {1, 10, 5, 7, 12, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findConsecutiveGap(arr, n) << "\n";
}