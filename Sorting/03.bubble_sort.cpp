/*
    Sort the elements of an array using bubble sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (!isSwapped)
            break;
    }
}

int main()
{
    int arr[] = {5, 6, 8, 1, 12, 10, 7, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
