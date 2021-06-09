/*
    Given an string and pattern write a function to print all the occurrences of the pattern in string using Boyer Moore Algorithm.
    
    Link: https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
*/

#include <bits/stdc++.h>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(string pat, int size, int badChar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    for (int i = 0; i < size; i++)
        badChar[(int)pat[i]] = i;
}

void BMSearch(string str, string pat)
{
    int n = str.length();
    int m = pat.length();

    int badChar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badChar);

    int s = 0;

    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == str[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            cout << "Pattern occurs at " << s << endl;

            s += (s + m < n) ? m - badChar[(int)str[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[(int)str[s + j]]);
        }
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pat = "AABA";

    BMSearch(text, pat);

    return 0;
}