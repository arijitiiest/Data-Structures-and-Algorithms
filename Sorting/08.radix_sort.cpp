/*
    Sort the elements of an character array using radix sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

int getMax(int *arr, int n)
{
    int m = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > m)
            m = arr[i];
    return m;
}

void counting_sort(int *arr, int n, int exp)
{
    int output[n], count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int *arr, int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);
}

int main()
{
    int arr[] = {45, 155, 700, 14, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    radix_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
