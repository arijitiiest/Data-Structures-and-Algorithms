/*
    Given n non-negative integers a1, a2, ..., an,
    where each represents a point at coordinate (i, ai).
    'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

    Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Example:
        Input : [1, 5, 4, 3]
        Output : 6

    Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
        So total area = 3 * 2 = 6
*/

#include <bits/stdc++.h>
using namespace std;

int maxArea(int arr[], int n)
{
    int start = 0, end = n - 1;
    int maxVol = 0;
    while (start < end)
    {
        maxVol = max(maxVol, (end - start) * min(arr[start], arr[end]));

        if (arr[start] < arr[end])
            start++;
        else
            end--;
    }
    return maxVol;
}

int main()
{
    int arr[] = {1, 5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxArea(arr, n) << endl;
}
