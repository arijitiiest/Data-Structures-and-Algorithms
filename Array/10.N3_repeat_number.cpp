/*
    You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

    If so, return the integer. If not, return -1.

    If there are multiple solutions, return any one.

    Input : [1 2 3 1 1]
    Output : 1 
*/

#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(int arr[], int n)
{
    int m1 = 0, m2 = 0, num1 = arr[0], num2 = arr[1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
            m1++;
        else if (arr[i] == num2)
            m2++;
        else if (m1 == 0)
        {
            num1 = arr[i];
            m1 = 1;
        }
        else if (m2 == 0)
        {
            num2 = arr[i];
            m2 = 1;
        }
        else
        {
            m1--;
            m2--;
        }
    }

    int freq1 = 0, freq2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
            freq1++;
        if (arr[i] == num2)
            freq2++;
    }
    if (freq1 > n / 3)
        return num1;
    if (freq2 > n / 3)
        return num2;
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << repeatedNumber(arr, n) << endl;
}
