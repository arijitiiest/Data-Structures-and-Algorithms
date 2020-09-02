/*
    Extended Euclidean Algorithm:
        A modular multiplicative inverse of an integer a is an integer x such that a⋅x is congruent to 1 modular some modulus m.
                a * x === 1 mod m

        moduler inverse exist if,  gcd(a, m) = 1
                a * x + m * y = 1

        Taking modulo m both side,
                a * x = 1 mod m


    Fermat's Little Theorem:
        Fermat's little theorem states that if m is a prime number, then for any integer a, the number a^m − a is an integer 
        multiple of m. In the notation of modular arithmetic, this is expressed as
            a ^ m === a (mod m)
        
        So,
            a ^ m-1 === 1 (mod m)
            a ^ m-2 === a ^ -1 (mod m)

*/

#include <bits/stdc++.h>
using namespace std;
class Triplet
{
public:
    int x, y, gcd;
};

// Modular Multiplicative Inverse using Extended Euclidean Algorithm
Triplet extended_euclidean(int a, int b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    Triplet small_ans = extended_euclidean(b, a % b);
    Triplet ans;
    ans.x = small_ans.y;
    ans.y = small_ans.x - small_ans.y * (a / b);
    ans.gcd = small_ans.gcd;
    return ans;
}

bool modulo_inverse(int a, int m, int &x)
{
    Triplet ans = extended_euclidean(a, m);
    if (ans.gcd != 1)
        return false;

    x = (ans.x % m + m) % m;
    return true;
}

// // Modular Multiplicative Inverse using Fermat's Little Theorem
// int power(int x, int y, int m)
// {
//     if (y == 0)
//         return 1;
//     int p = power(x, y / 2, m) % m;
//     p = (p * p) % m;

//     return (y % 2 == 0) ? p : (x * p) % m;
// }

// bool modulo_inverse(int a, int m, int &x)
// {
//     if (__gcd(a, m) != 1)
//         return false;

//     x = power(a, m - 2, m);
//     return true;
// }

int main()
{
    int a = 5, m = 13;
    int x;
    if (!modulo_inverse(a, m, x))
    {
        cout << "No Solution\n";
    }
    else
    {
        cout << "Modulo Inverse: " << x << endl;
    }

    return 0;
}