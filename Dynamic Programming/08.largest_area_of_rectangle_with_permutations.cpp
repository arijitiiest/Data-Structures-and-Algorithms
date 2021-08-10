/*
    Given a binary grid A of size N x M consisting of 0's and 1's, find the area of the largest rectangle inside the grid such that all the cells inside the chosen rectangle should have 1 in them.

    You are allowed to permutate the columns matrix i.e. you can arrange each of the column in any order in the final grid.

    Example:
        Input:
            A = [  [1, 0, 1]
                    [0, 1 ,0]
                    [1, 0, 0]
                ]
        Output:
            2
*/

#include <bits/stdc++.h>
using namespace std;

int largestAreaOfRectangleWithPermutation(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size();
    vector<vector<int>> B(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        B[0][j] = A[0][j];
        for (int i = 1; i < n; i++)
            if (A[i][j] != 0)
                B[i][j] = B[i - 1][j] + 1;
    }

    int maxArea = 0, area = 0;
    for (int i = 0; i < n; i++)
    {
        sort(B[i].begin(), B[i].end());
        int weight = 1;
        for (int j = m - 1; j >= 0; j--)
        {
            area = B[i][j] * weight;
            weight++;
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main()
{
    vector<vector<int>> A{{1, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    cout << largestAreaOfRectangleWithPermutation(A) << endl;
    return 0;
}
