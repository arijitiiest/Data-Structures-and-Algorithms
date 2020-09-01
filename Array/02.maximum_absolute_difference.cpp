/*
    You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
    f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

    Example:
        A=[1, 3, -1]

        f(1, 1) = f(2, 2) = f(3, 3) = 0
        f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
        f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
        f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

        So, we return 5.


    Solve:
        |A[i] - A[j]| + |i - j| is
            Case 1: A[i] > A[j] and i > j
                    |A[i] - A[j]| = A[i] - A[j]
                    |i -j| = i - j
                    hence, f(i, j) = (A[i] + i) - (A[j] + j)

            Case 2: A[i] < A[j] and i < j
                    |A[i] - A[j]| = -(A[i]) + A[j]
                    |i -j| = -(i) + j
                    hence, f(i, j) = -(A[i] + i) + (A[j] + j)

            Case 3: A[i] > A[j] and i < j
                    |A[i] - A[j]| = A[i] - A[j]
                    |i -j| = -(i) + j
                    hence, f(i, j) = (A[i] - i) - (A[j] - j)

            Case 4: A[i] < A[j] and i > j
                    |A[i] - A[j]| = -(A[i]) + A[j]
                    |i -j| = i - j
                    hence, f(i, j) = -(A[i] - i) + (A[j] - j)

*/

#include <bits/stdc++.h>
using namespace std;

int maxAbsDiff(int arr[], int n)
{
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        max1 = max(max1, arr[i] + i);
        max2 = max(max2, arr[i] - i);
        min1 = min(min1, arr[i] + i);
        min2 = min(min2, arr[i] - i);
    }
    return max((max1 - min1), (max2 - min2));
}

int main()
{
    int arr[] = {55, -8, 43, 52, 8, 59, -91, -79, -18, -94};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxAbsDiff(arr, n) << "\n";
}
