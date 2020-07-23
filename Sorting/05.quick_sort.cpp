/*
    Sort the elements of an array using quick sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int left, int right)
{
    int pivot = arr[right];
    int idx = left - 1;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivot)
        {
            idx++;
            swap(arr[idx], arr[i]);
        }
    }
    swap(arr[idx + 1], arr[right]);
    return idx + 1;
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);

        quick_sort(arr, left, pi - 1);
        quick_sort(arr, pi + 1, right);
    }
}

int main()
{
    int arr[] = {5, 6, 8, 1, 12, 10, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
