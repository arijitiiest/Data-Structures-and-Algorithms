/*
    Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random 
    bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

    Find the maximum number of chocolates that kid can eat in A units of time.

    NOTE:
        floor() function returns the largest integer less than or equal to a given number.
        Return your answer modulo 109+7
    
    Input:
        A = 5
        b = [2, 4, 6, 8, 10]
    Output:
        33
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int

int nchoc(int A, vector<int> &B)
{
    priority_queue<ll> pq;
    for (int i = 0; i < B.size(); i++)
    {
        pq.push(B[i]);
    }
    ll res = 0, v;
    while (A--)
    {
        if (!pq.empty())
        {
            v = pq.top();
            res = (res + v) % MOD;
            pq.pop();
            v /= 2;
            if (v > 0)
                pq.push(v);
        }
        else
        {
            break;
        }
    }
    return res;
}

int main()
{
    int A = 5;
    vector<int> B{2, 4, 6, 8, 10};

    cout << nchoc(A, B) << endl;
}
