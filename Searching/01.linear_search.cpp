/*
    Given an array of n elements, search an element x in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int linear_search(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = linear_search(arr, n, 6);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not Found\n";

    return 0;
}