/*
    Given an array of real numbers greater than zero in form of strings.
    Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .

    Input:
        [0.6, 0.7, 0.8, 1.2, 0.4]
    Outout:
        True
*/

#include <bits/stdc++.h>
using namespace std;

bool isFound(double arr[], int n)
{
    double a = arr[0], b = arr[1], c = arr[2];
    for (int i = 3; i < n; i++)
    {
        if (a + b + c > 1 && a + b + c < 2)
            return true;
        
        double m = (a + b + c) > 2 ? max(a, max(b, c)) : (a + b + c) < 1 ? min(a, min(b, c)) : -1;
        if (a == m)
            a = arr[i];
        else if (b == m)
            b = arr[i];
        else if (c == m)
            c = arr[i];
    }

    if (a + b + c > 1 && a + b + c < 2)
        return true;
    else
        return false;
}

int main()
{
    double arr[] = {0.6, 0.7, 0.8, 1.2, 0.4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << (isFound(arr, n) ? "Found\n" : "Not Found\n");
}
