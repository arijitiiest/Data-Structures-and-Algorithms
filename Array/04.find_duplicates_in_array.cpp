/*
    Given a read only array of n + 1 integers between 1 and n, find one number that repeats.
    If there are multiple possible answers, output any one.

    Input:
        [3 4 1 4 1]
    Output:
        1
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicates(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            return arr[i];
    }
    return -1;
}

// // Another approach
// int findDuplicates(int arr[], int n)
// {
//     int slow = arr[0];
//     int fast = arr[arr[0]];
//     while (slow != fast)
//     {
//         slow = arr[slow];
//         fast = arr[arr[fast]];
//     }

//     fast = 0;
//     while (slow != fast)
//     {
//         slow = arr[slow];
//         fast = arr[fast];
//     }
//     if (slow == 0)
//         return -1;
//     return slow;
// }

int main()
{
    int arr[] = {3, 4, 1, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findDuplicates(arr, n) << "\n";
}