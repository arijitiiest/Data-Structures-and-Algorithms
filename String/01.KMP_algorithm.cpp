/*
    Given an string and pattern write a function to print all the occurrences of the pattern in string using KMP algorithm.

    Link: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
*/

#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < M)
    {
        if (pat[i] == pat[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string str, string pat)
{
    int N = str.length();
    int M = pat.length();

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0, j = 0;
    while (i < N)
    {
        if (str[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            cout << "Pattern found at index : " << i - M << endl;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && str[i] != pat[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    string str = "AABAACAADAABAABA";
    string pat = "AABA";

    KMPSearch(str, pat);

    return 0;
}