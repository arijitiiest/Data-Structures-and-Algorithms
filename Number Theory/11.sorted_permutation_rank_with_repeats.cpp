/*
    Given a string, find the rank of the string amongst its permutations sorted lexicographically.
    Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations.

    Input : 'aba'
    Output : 2

    The order permutations with letters 'a', 'a', and 'b' : 
    aab
    aba
    baa
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003

// Factorial Function
long long fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    long long ans = 1;
    while (n > 1)
    {
        ans = (ans * n) % MOD;
        n--;
    }
    return ans;
}

// Calculating Power Under Modulus
long long modPow(long long a, long long n)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

int findRank(string str)
{
    int n = str.length();
    long long ans = 1, repeat, less_num, count;
    for (int i = 0; i < n; i++)
    {
        less_num = 0;
        for (int j = i + 1; j < n; j++)
            if (str[j] < str[i])
                less_num++;

        vector<int> freq(256, 0);

        for (int j = i; j < n; j++)
            freq[str[j]]++;

        repeat = 1;
        for (int j = 0; j < 256; j++)
            repeat = (repeat * fact(freq[j])) % MOD;

        repeat = modPow(repeat, MOD - 2);
        count = (fact(n - i - 1) * less_num) % MOD;
        count = (count * repeat) % MOD;

        ans = (ans + count) % MOD;
    }
    return ans;
}

int main()
{
    string str = "aba";
    cout << findRank(str) << endl;
}
