/*
    Sort the elements of an array using heap sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[] = {5, 6, 8, 1, 12, 10, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
