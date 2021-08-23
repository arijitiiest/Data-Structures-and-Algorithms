/*
    Given a number n, print all primes smaller than n. Here n is very large.

    Primes smaller than 100:
        2 3 5 7 11 13 17 19 23 29 31 37 41
        43 47 53 59 61 67 71 73 79 83 89 97
*/

#include <bits/stdc++.h>
using namespace std;

void seive(int limit, vector<long long int> &primes)
{
    vector<bool> p(limit + 1, true);

    for (long long int i = 2; i < limit; i++)
    {
        if (p[i] == true)
        {
            primes.push_back(i);
            cout << i << " ";
            for (long long int j = i * i; j < limit; j += i)
            {
                p[i] = false;
            }
        }
    }
}

// Space Complexity: O(sqrt(n))
void segmented_sieve(long long int n)
{
    long long int limit = floor(sqrt(n)) + 1;
    vector<long long int> primes;
    primes.reserve(limit);

    seive(limit, primes);

    long long int low = limit, high = 2 * limit;

    while (low < n)
    {
        if (high >= n)
            high = n;

        vector<bool> p(limit + 1, true);

        for (long long int i = 0; i < primes.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            long long int loLim = floor(low / primes[i]) * primes[i];
            if (loLim < low)
                loLim += primes[i];

            for (long long int j = loLim; j <= high; j += primes[i])
                p[j - low] = false;
        }

        for (long long int j = low; j < high; j++)
            if (p[j - low] == true)
                cout << j << " ";

        low += limit;
        high += limit;
    }
}

int main()
{
    long long int n = 10000;

    cout << "Primes smaller than " << n << " is " << endl;
    segmented_sieve(n);

    return 0;
}
