/*
    Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

    You have the following 3 operations permitted on a word:
        Insert a character
        Delete a character
        Replace a character

    Example:
        Input:
            A = "Anshuman"
            B = "Antihuman"

        Output:
            2

        Explanation:
            => Operation 1: Replace s with t.
            => Operation 2: Insert i.
*/

#include <bits/stdc++.h>
using namespace std;

int editDistance(string A, string B)
{
    int n = A.length(), m = B.length();
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;

    return dp[n][m];
}

int main()
{
    string A = "Anshuman", B = "Antihuman";

    cout << editDistance(A, B) << endl;
}
