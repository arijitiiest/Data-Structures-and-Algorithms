/* 
    GCD (greatest common divisor) the largest number which is a divisor of both a and b.
    Euclidean Algorithm- 
                        GCD(a, b) = a                   if b==0
                                    = GCD(b, a mod b)     otherwise
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(log min(a,b)) 
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

// Time Complexity - O(log min(a,b))
int gcdNonRecursive(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int a = 6, b = 10;
    cout << gcd(a, b) << endl;
    cout << gcdNonRecursive(a, b) << endl;
    return 0;
}