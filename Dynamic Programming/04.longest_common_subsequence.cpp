/*  
    Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in 
    both the strings.

    You need to return the length of such longest common subsequence.

    Example:
        Input:
            A = "abbcdgf"
            B = "bbadcgf"
        Output:
            5
*/

#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B)
{
    int n = A.length(), m = B.length();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i - 1] == B[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i][j - 1], dp[i - 1][j]));
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    return dp[n][m];
}

int main()
{
    string A = "abbcdgf", B = "bbadcgf";

    cout << LCS(A, B) << endl;
}