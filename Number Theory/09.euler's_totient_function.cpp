/*
    Euler's totient function, also known as phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are coprime to n.
        ϕ(n) = n * (1 - 1/p1) * (1 - 1/p2) ... (1 - 1/pk)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

int main()
{
    int n = 10;
    vector<int> phi = phi_1_to_n(n);
    for (int i = 1; i <= n; i++)
        cout << phi[i] << " ";
    cout << "\n";
    return 0;
}