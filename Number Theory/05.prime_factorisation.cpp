/*
    Prime Factorization for multiple queries
*/

#include <bits/stdc++.h>
using namespace std;

const int RANGE = 1000000;

vector<int> sieve()
{
    int p[RANGE + 1] = {0};
    vector<int> primes;

    for (long long int i = 2; i <= RANGE; i++)
    {
        if (p[i] == 0)
        {
            primes.push_back(i);
            for (long long int j = i * i; j <= RANGE; j += i)
                p[j] = 1;
        }
    }
    return primes;
}

vector<int> factorize(int no, vector<int> primes)
{
    vector<int> factors;

    for (int i = 0; primes[i] * primes[i] <= no; i++)
    {
        if (no % primes[i] == 0)
        {
            factors.push_back(primes[i]);
            while (no % primes[i] == 0)
            {
                no /= primes[i];
            }
        }
    }

    if (no != 1)
        factors.push_back(no);
    return factors;
}

int main()
{
    vector<int> primes = sieve();

    int t;
    cin >> t;

    while (t--)
    {
        int no;
        cin >> no;

        vector<int> factors = factorize(no, primes);

        for (auto f : factors)
            cout << f << endl;
    }

    return 0;
}
