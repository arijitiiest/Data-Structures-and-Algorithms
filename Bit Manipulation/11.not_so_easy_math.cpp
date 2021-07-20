/*
    After the release of Avengers, Ironman and Thor got into a fight and Ironman challenged Thor to find out the number of numbers between 1 and n 
    which are divisible by any of the prime numbers less than 20. Ironman being great at maths quickly answered the question but then Thor asked him 
    to write a program for it. Ironman however found it quite difficult as he did not wanted to write so many lines of code. he knows that you are 
    smart and can code this up easily. Can you do it?

    Example:
        Input:
            5
            5
            10
            12
            15
            18
        Output
            4
            9
            11
            14
            17
*/

#include <bits/stdc++.h>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

int countNos(int n)
{
    int l = sizeof(primes) / sizeof(primes[0]);

    int ans = 0;
    for (int i = 1; i < (1 << l); i++)
    {
        int denom = 1;
        for (int j = 0; j < l; j++)
            if (i & (1 << j))
                denom *= primes[j];

        int setBits = __builtin_popcount(i);
        if (setBits & 1)
            ans += (n / denom);
        else
            ans -= (n / denom);
    }
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << countNos(n) << endl;
    }
    return 0;
}
