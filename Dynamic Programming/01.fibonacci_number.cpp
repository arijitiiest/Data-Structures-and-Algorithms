/*

*/

#include <bits/stdc++.h>
using namespace std;

int arr[1000];

// Recursion
int fib1(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fib1(n - 1) + fib1(n - 2);
}

// Top-Down DP
int fib2(int n)
{
    if (arr[n] != -1)
        return arr[n];
    arr[n] = fib2(n - 1) + fib2(n - 2);
    return arr[n];
}

// Bottom-Up DP (with space optimization);
int fib3(int n)
{
    if (n == 0)
        return 0;
    int a = 0, b = 1, temp;
    for (int i = 1; i < n; i++)
    {
        temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

void multiply(int F[2][2], int M[2][2])
{
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(int F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

// Matrix Exponentiation
int fib4(int n)
{
    int F[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}

// Binet's Formula   ->  Fn = {[(√5 + 1)/2] ^ n} / √5
// http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormula.html
int fib5(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}

// Codeforces Hack
// https://codeforces.com/blog/entry/14516
// Proof: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/   -> Method 6
const long M = 1000000007; // modulo
map<long, long> F;
long fib6(long n)
{
    if(F.count(n)) return F[n];
    long k = n/2;
    if(n%2 == 0)
        return F[n] = (fib6(k) * fib6(k) + fib6(k - 1) * fib6(k - 1))%M;
    else
        return F[n] = (fib6(k)*fib6(k+1) + fib6(k-1)*fib6(k)) % M;
}

int main()
{
    int n = 10;

    // Recursion
    cout << fib1(n) << endl;

    // Top-Down DP
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    cout << fib2(n) << endl;

    // Bottom-Up DP
    cout << fib3(n) << endl;

    // Matrix Exponentiation
    cout << fib4(n) << endl;

    // Binet's Formula 
    cout << fib5(n) << endl;

    // Codeforces Hack
    long m = 1e19;
    F[0]=F[1] = 1;
    cout << (n == 0 ? 0 : fib6(m - 1)) << endl;
}