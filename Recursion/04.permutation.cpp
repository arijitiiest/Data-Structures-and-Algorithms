/*
    Given a collection of numbers, return all possible permutations.

    Input:
        [1,2,3]
    Output:
        [1,2,3]
        [1,3,2]
        [2,1,3] 
        [2,3,1] 
        [3,1,2]
        [3,2,1]
*/

#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &A, vector<vector<int>> &res, int idx)
{
    if (idx == A.size())
    {
        res.push_back(A);
        return;
    }

    for (int i = idx; i < A.size(); i++)
    {
        swap(A[i], A[idx]);
        permutation(A, res, idx + 1);
        swap(A[i], A[idx]);
    }
}

int main()
{
    vector<int> A{1, 2, 3};
    vector<vector<int>> res;

    permutation(A, res, 0);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
}
