/*
    Sort the elements of an array using insertion sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *arr, int n)
{
    int key;
    for(int i=0; i<n; i++) {
        key = arr[i];

        int j=i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {5, 6, 8, 1, 12, 10, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
