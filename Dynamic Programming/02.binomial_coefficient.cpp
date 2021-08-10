/*

*/

#include<bits/stdc++.h>
using namespace std;

// Recursion
// Time - O(2^n)
// Space - O(n)
int binomialCoeff01(int n, int k)
{
    if(k > n)
        return 0;
    if(k == n || k == 0)
        return 1;

    return binomialCoeff01(n-1, k-1) + binomialCoeff01(n-1, k);
}

// Top-Down DP
// Time - O(n*k)
// Space - O(n*k)
int binomialCoeff02(int n, int k, int** dp)
{
    if(dp[n][k] != -1)
        return dp[n][k];
    
    if(k == 0 || k == n)
        return dp[n][k] = 1;

    return dp[n][k] = binomialCoeff02(n-1, k-1, dp) + binomialCoeff02(n-1, k, dp);
}

// Bottom-UP DP
// Time - O(n*k)
// Space - O(n*k)
int binomialCoeff03(int n, int k)
{
    int dp[n+ 1][k + 1];
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=min(i, k); j++) {
            if(j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

// Bottom-UP DP (space optimized)
// Time - O(n*k)
// Space - O(k)
int binomialCoeff04(int n, int k)
{
    int dp[k+1];

    for(int i=0; i<=n; i++) {
        for(int j=min(i, k); j >=0; j--) {
            if(j == 0 || j == i)
                dp[j] = 1;
            else
                dp[j] = dp[j] + dp[j-1];
        }
    }
    return dp[k];
}

// Using nnumerator and denominator
// Time - O(k)
// Space - O(1)
int binomialCoeff05(int n, int k){
    if(n-k < k)
        k = n-k;

    int res = 1;

    for(int i=0; i<k; i++) {
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

int main()
{
    int n = 5, k = 2;

    // Recursion
    cout << binomialCoeff01(n, k) << endl;

    // Top-Down DP
    int **dp;
    dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[k+1];
        for(int j=0; j<=k; j++)
            dp[i][j] = -1;
    }
    cout << binomialCoeff02(n, k, dp) << endl;

    // Bottom-UP DP
    cout << binomialCoeff03(n, k) << endl;

    // Bottom-UP DP (space optimized)
    cout << binomialCoeff04(n, k) << endl;

    // Using nnumerator and denominator
    cout << binomialCoeff05(n, k) << endl;

    return 0;
}