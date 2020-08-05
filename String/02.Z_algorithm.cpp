/*
    Given an string and pattern write a function to print all the occurrences of the pattern in string using KMP algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void buildZ(string str, int n, int z[])
{
    int l, r, k;
    l = r = 0;
    for (int i = 0; i < n; i++)
    {
        // Nothing matches so we will calculate z[i]
        if (r < i)
        {
            l = r = i;
            
            // start checking from 0 th index
            while (r < n && str[r - l] == str[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            k = i - l;
            
            // if z[k] is less than remaining interval 
            // then z[i] will be equal to z[k]. 
            if (z[k] < r - i + 1)
                z[i] = z[k];

            else
            {
                l = i;
                while (r < n && str[r - l] == str[r])
                    r++;

                z[i] = r - l;
                r--;
            }
        }
    }
}

void ZSearch(string text, string pat)
{
    // Considering pattern and text doesnt have $ character
    string str = pat + '$' + text;
    int n = str.length();
    int z[n];
    buildZ(str, n, z);

    int M = pat.length();
    for (int i = M + 1; i < n; i++)
    {
        if (z[i] == M)
            cout << "Pattern found at index : " << i - M - 1 << endl;
    }
}

int main()
{
    string text = "AABAACAADAABAABA";
    string pat = "AABA";

    ZSearch(text, pat);

    return 0;
}