/*
    Given a string, find the rank of the string amongst its permutations sorted lexicographically. Assume that no characters are repeated.
    return your answer % 1000003

    Input : 'acb'
    Output : 2

    The order permutations with letters 'a', 'c', and 'b' : 
    abc
    acb
    bac
    bca
    cab
    cba
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003

int fact(int n)
{
    return n <= 1 ? 1 : (n * fact(n - 1)) % MOD;
}

int findRank(string str)
{
    int n = str.length();
    int rank = 1;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
                c++;
        }
        rank = (rank + (c * fact(n - i - 1)) % MOD) % MOD;
    }
    return rank;
}

int main()
{
    string str = "acb";
    cout << findRank(str) << endl;
}
