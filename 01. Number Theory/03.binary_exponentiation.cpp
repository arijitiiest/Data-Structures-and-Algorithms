/*
    Binary exponentiation (also known as exponentiation by squaring) is a trick which allows to calculate an using only O(logn) 
    multiplications (instead of O(n) multiplications required by the naive approach). 
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)
int pow(int n, int r)
{
    int res = 1;
    while (r > 0)
    {
        res *= n;
        r--;
    }
    return res;
}

// Time Complexity - O(logn)
// Recursive Approach
int binPowRecursive(int n, int r)
{
    if (r == 0)
        return 1;
    int res = binPowRecursive(n, r / 2);

    if (r % 2)
    {
        return res * res * n;
    }
    else
    {
        return res * res;
    }
}

// Time Complexity - O(logn)
// Iterative Approach
int binPowIterative(int n, int r)
{
    int res = 1;
    while (r > 0)
    {
        if (r & 1)
        {
            res = res * n;
        }
        n = n * n;
        r = r >> 1;
    }
    return res;
}

int main()
{
    int n = 2, r = 10;
    cout << pow(n, r) << endl;
    cout << binPowRecursive(n, r) << endl;
    cout << binPowIterative(n, r) << endl;
    return 0;
}