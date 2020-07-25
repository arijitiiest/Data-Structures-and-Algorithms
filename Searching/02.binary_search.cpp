/*
    Given an array of n elements, search an element x in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int l, int r, int x)
{
    if (l < r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, l, mid, x);
        return binary_search(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = binary_search(arr, 0, n - 1, 6);
    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not Found\n";

    return 0;
}