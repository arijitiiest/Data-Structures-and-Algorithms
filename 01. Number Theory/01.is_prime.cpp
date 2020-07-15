// Check whether a no is a prime or not

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int countFactors = 0;
    for (int i = 1; i * i < n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                countFactors += 1;
            else
                countFactors += 2;
        }
    }

    if (countFactors == 2)
        return true;

    return false;
}

int main()
{
    int n = 41;
    if (isPrime(n))
    {
        cout << n << " is a Prime no\n";
    }
    else
    {
        cout << n << " is not a Prime no\n";
    }
}