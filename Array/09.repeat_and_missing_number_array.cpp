/*
    You are given a read only array of n integers from 1 to n.
    Each integer appears exactly once except A which appears twice and B which is missing.
    Return A and B.

    Input:[3 1 2 5 3] 
    Output:[3, 4] 
*/

#include <bits/stdc++.h>
using namespace std;

void findNumbers(int arr[], int n)
{
    long long sum = 0, sq_sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sq_sum += arr[i] * arr[i];
    }

    long long ab = sum - (n * (n + 1)) / 2;                  // a - b
    long long a2b2 = sq_sum - n * (n + 1) * (2 * n + 1) / 6; // a^2 - b^2

    long long a = (ab + (a2b2 / ab)) / 2;
    long long b = (a2b2 / ab) - a;

    cout << a << " " << b << "\n";
}

// // Another method
// void findNumbers(int arr[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         if (arr[i] != arr[arr[i] - 1])
//         {
//             swap(arr[i], arr[arr[i] - 1]);
//             i--;
//         }

//     for (i = 0; i < n; i++)
//         if (arr[i] != i + 1)
//             break;

//     cout << arr[i] << " " << i + 1 << "\n";
// }

int main()
{
    int arr[] = {3, 1, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    findNumbers(arr, n);
}