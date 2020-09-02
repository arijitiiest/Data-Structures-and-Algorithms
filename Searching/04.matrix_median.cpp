/*
    Given a matrix of integers A of size N x M in which each row is sorted.

    Find an return the overall median of the matrix A.

    Note: No extra memory is allowed.

    Note: Rows are numbered from top to bottom and columns are numbered from left to right.

    Input:
        A = [   [1, 3, 5],
                [2, 6, 9],
                [3, 6, 9]   ]
    Output:
        5
*/

#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<vector<int>> vect)
{
    int row = vect.size(), col = vect[0].size();
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < row; i++)
    {
        mn = min(mn, vect[i][0]);
        mx = max(mx, vect[i][col - 1]);
    }

    int idx = (row * col + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int count = 0;
        for (int i = 0; i < row; i++)
            count += upper_bound(vect[i].begin(), vect[i].end(), mid) - vect[i].begin();

        if (count < idx)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}

int main()
{
    vector<vector<int>> vect{{1, 3, 5},
                             {2, 6, 9},
                             {3, 6, 9}};

    cout << findMedian(vect) << endl;
}