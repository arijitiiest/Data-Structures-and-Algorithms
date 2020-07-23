/*
    Sort the elements of an array using selection sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[i], arr[min_idx]);
    }
}

int main()
{
    int arr[] = {5, 6, 8, 1, 12, 10, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
