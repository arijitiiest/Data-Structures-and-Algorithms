/*
    Find the largest continuous sequence in a array which sums to zero.

    Input:  {1 ,2 ,-2 ,4 ,-4}
    Output: {2 ,-2 ,4 ,-4}
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> getLSZero(vector<int> &A)
{
    int n = A.size();
    unordered_map<int, int> mp;
    mp[0] = -1;
    int mn = -1, mx = -1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (mp.find(sum) != mp.end())
        {
            if (mx - mn < i - mp[sum])
            {
                mx = i;
                mn = mp[sum]+1;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }

    vector<int> res;
    if (mx - mn == 0)
        return res;
    for (int i = mn; i <= mx; i++)
        res.push_back(A[i]);

    return res;
}

int main()
{
    vector<int> A{1, 2, -2, 4, -4};
    vector<int> res = getLSZero(A);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}
