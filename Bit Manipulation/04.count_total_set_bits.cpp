/*
    Given a positive integer A, the task is to count the total number of set bits in the binary representation of all the numbers from 1 to A.
    Return the count modulo 10^9 + 7.

    Input: 
        3
    Output: 
        4
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long leftMost(long long n)
{
    long long pos = 0;
    while (n > 1)
    {
        pos++;
        n = n >> 1;
    }
    return pos;
}

long long countBits(long long n)
{
    if (n == 0)
        return 0;
    long long m = leftMost(n);

    if (n == ((1 << (m + 1)) - 1)) // if number is of form 2^b-1 return directly
        return ((m + 1) * (1 << m));

    n = n - (1 << m);                                     // if not all bits are set
    return (n + 1) + (m * (1 << (m - 1))) + countBits(n); //recursively calling for the rest of the bits
}

int count_set_bits_of_a_number(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    cout << countBits(5) % MOD << endl;

    cout << count_set_bits_of_a_number(6) << endl;
}
