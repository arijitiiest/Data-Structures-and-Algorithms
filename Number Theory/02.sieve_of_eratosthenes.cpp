// Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] using O(nloglogn) operations.

#include <bits/stdc++.h>
using namespace std;

int MAX = 10000000;

// Optimized seive - Time complexity O(N loglogN)
void prime_seive(int *p, int n)
{
    p[0] = p[1] = 0;
    p[2] = 1;
    for (int i = 3; i <= n; i += 2)
        p[i] = 1;

    for (int i = 3; i * i <= n; i += 2)
        if (p[i] == 1)
            for (int j = i * i; j <= n; j += i)
                p[j] = 0;

    cout << "Prime nos are: ";
    for (int i = 1; i <= n; i++)
        if (p[i] == 1)
            cout << i << " ";
    cout << endl;
}

void prime_seive_space_optimized(vector<int> &primes)
{
    bitset<10000005> b;

    b.set();

    b[0] = b[1] = 0;

    for (long long int i = 2; i <= MAX; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (long long int j = i * i; j <= MAX; j += i)
                b[j] = 0;
        }
    }
}

int main()
{
    int n = 100;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // Sieve of Eratosthenes
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    cout << "Prime nos are: ";
    for (int i = 1; i <= n; i++)
        if (isPrime[i])
            cout << i << " ";
    cout << endl;

    int p[n + 1] = {0};
    prime_seive(p, n);

    vector<int> primes;
    prime_seive_space_optimized(primes);

    cout << "First " << n << " Prime nos are: ";
    for (int i = 0; i < n; i++)
        cout << primes[i] << " ";
    cout << endl;

    return 0;
}