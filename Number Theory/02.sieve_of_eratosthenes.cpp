// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] using O(nloglogn) operations.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    cout << "Prime nos are: ";
    for (int i = 1; i <= n; i++)
    {
        if(isPrime[i])
            cout << i << " ";
    }

    return 0;
}