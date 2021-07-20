/*
    Exponentiation/Power using bitmasking

    Input:
        a = 6, 
        b = 2
    Output:
        a^b = 6^2 = 36
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n)
int power(int a, int b)
{
    int res = 1;
    while (b--)
    {
        res *= a;
    }
    return res;
}

// Time Complexity - O(log(n))       // As no of set bits n is at max log(n)
int power_optimized(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout << power(6, 2) << endl;
    cout << power_optimized(6, 2) << endl;

    return 0;
}
