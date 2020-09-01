/*
    Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a 
    given array A of size N.

    If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

    Input 1:
        A = [1, 2, 3]
    Output 1:
        [1, 3, 2]

    Input 2:
        A = [3, 2, 1]
    Output 2:
        [1, 2, 3]
*/

#include <bits/stdc++.h>
using namespace std;

void nextPermutation(int arr[], int n)
{
    int i, j;
    for (i = n - 2; i >= 0; i--)
        if (arr[i] < arr[i + 1])
            break;

    if (i == -1)
    {
        reverse(arr, arr + n);
        return;
    }

    for (j = n - 1; j > i; j--)
        if (arr[j] > arr[i])
            break;

    swap(arr[i], arr[j]);
    reverse(arr + i + 1, arr + n);
}

int main()
{
    int arr[] = {2, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    nextPermutation(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
