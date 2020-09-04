/*
    Given an array of integers, find two numbers such that they add up to a specific target number.

    Input: [2, 7, 11, 15], target=9
    Output: index1 = 1, index2 = 2
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &A, int B)
{
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < A.size(); i++)
    {
        if (mp.find(B - A[i]) != mp.end())
        {
            res.push_back(mp[B - A[i]]);
            res.push_back(i + 1);
            return res;
        }
        else
        {
            mp[A[i]] = i + 1;
        }
    }
}

int main()
{
    vector<int> A{2, 7, 11, 15};
    int B = 9;

    vector<int> res = twoSum(A, B);

    cout << res[0] << " " << res[1] << "\n";
}
