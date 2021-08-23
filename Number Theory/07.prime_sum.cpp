/*
    Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

    Solution always exist. Read https://en.wikipedia.org/wiki/Goldbach%27s_conjecture

    Input : 4
    Output: 2 + 2 = 4
*/

#include <bits/stdc++.h>
using namespace std;

void findPrimes(int n)
{
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    for (int i = 2; i <= n; i++)
        if (isPrime[i] && isPrime[n - i])
        {
            cout << i << " " << n - i << "\n";
            return;
        }
}

int main()
{
    int n = 4;
    findPrimes(n);
}