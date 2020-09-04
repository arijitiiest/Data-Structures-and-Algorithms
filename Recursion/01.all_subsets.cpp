/*
    Given a collection of integers that might contain duplicates, S, return all possible subsets.

    Note:
        1. Elements in a subset must be in non-descending order.
        2. The solution set must not contain duplicate subsets.
        3. The subsets must be sorted lexicographically.
*/

#include <bits/stdc++.h>
using namespace std;

void allSubsets(int arr[], int n, set<vector<int>> &res, vector<int> &sub, int idx)
{
    if (idx == n)
    {
        res.insert(sub);
        return;
    }

    allSubsets(arr, n, res, sub, idx + 1);

    sub.push_back(arr[idx]);
    allSubsets(arr, n, res, sub, idx + 1);
    sub.pop_back();
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    set<vector<int>> res;
    vector<int> sub;

    allSubsets(arr, n, res, sub, 0);

    for (auto it = res.begin(); it != res.end(); it++)
    {
        for (int j = 0; j < it->size(); j++)
            cout << (*it)[j] << " ";
        cout << "\n";
    }
}
