/*
    We are given an array containg n numbers. All the numbers are present twice except for two numbers which are present only once. 
    Find the unique numbers in linear time without using any extra space.

    Input
        4
        3 1 2 1
    Output
        2 3
*/

#include <bits/stdc++.h>
using namespace std;

int find_last_set_bit(int x)
{
    int res = 0;
    while ((x & 1) == 0)
    {
        res++;
        x >>= 1;
    }
    return res;
}

void find_unique_no_2(int arr[], int n)
{
    int xori = 0;
    for (int i = 0; i < n; i++)
    {
        xori ^= arr[i];
    }

    int pos = find_last_set_bit(xori);
    int mask = 1 << pos;

    int xora = 0, xorb = 0;
    for (int i = 0; i < n; i++)
    {
        if (mask & arr[i])
        {
            xora ^= arr[i];
        }
        else
        {
            xorb ^= arr[i];
        }
    }

    cout << xora << " " << xorb << endl;
}

int main()
{
    int arr[] = {1, 3, 1, 2, 5, 7, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    find_unique_no_2(arr, n);

    return 0;
}