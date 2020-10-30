/*
    Given A, B, C, find whether C is formed by the interleaving of A and B.

    Example:
        Input:
            A = "aabcc"
            B = "dbbca"
            C = "aadbbcbcac"

        Output:
            1

        Explanation:
            "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)
*/

#include <bits/stdc++.h>
using namespace std;

bool interleavingString(string A, string B, string C)
{
    int n = A.length(), m = B.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (i > 0 && dp[i - 1][j] == 1 && A[i - 1] == C[i + j - 1])
                    dp[i][j] = 1;
                if (j > 0 && dp[i][j - 1] == 1 && B[j - 1] == C[i + j - 1])
                    dp[i][j] = 1;
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string A = "aabcc", B = "dbbca", C = "aadbbcbcac";

    if (interleavingString(A, B, C))
        cout << "C is a Interleaving String of A and B\n";
    else
        cout << "C is not a Interleaving String of A and B\n";
}
