/*
    Find value of f(n) where f(n) is defined as
        F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
    Base Cases :
        F(0) = 0, F(1) = 1, F(2) = 1

    Details: https://www.geeksforgeeks.org/matrix-exponentiation/
*/

#include <bits/stdc++.h>
using namespace std;

void multiply(int A[3][3], int B[3][3])
{
    int mul[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += A[i][k] * B[k][j];
        }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            A[i][j] = mul[i][j];
}

int power(int F[3][3], int p)
{
    int M[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

    // Multiply it with initial values i.e with
    // F(0) = 0, F(1) = 1, F(2) = 1
    if (p == 1)
        return F[0][0] + F[0][1];

    power(F, p / 2);

    multiply(F, F);

    if (p & 1)
        multiply(F, M);

    return F[0][0] + F[0][1];
}

int findNthTerm(int n)
{
    int M[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return power(M, n - 2);
}

int main()
{
    int n = 10;

    cout << findNthTerm(n) << endl;

    return 0;
}
