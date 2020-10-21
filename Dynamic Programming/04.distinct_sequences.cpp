/*
    Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to 
    the sequence B.

    Example:
        Input:
            A = "rabbbit" 
            B = "rabbit"
        Output:
            3

        Explanation:
                => A = "ra_bbit" 
                => A = "rab_bit" 
                => A = "rabb_it"
*/

#include <bits/stdc++.h>
using namespace std;

int distinctSeq(string A, string B)
{
    int n = A.length(), m = B.length();
    if (m > n)
        return 0;

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][m];
}

int main()
{
    string A = "rabbbit", B = "rabbit";

    cout << distinctSeq(A, B) << endl;
}
