/*
    Given a string S and a string T, find the minimum window in S which will contain all the 
    characters in T in linear time complexity.

    Input:
        S = "ADOBECODEBANC"
        T = "ABC"
    Output:
        "BANC"
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string A, string B)
{
    unordered_map<char, int> a, b;
    for (auto i : B)
        b[i]++;

    int count = 0, x = -1, mn = INT_MAX;
    for (int left = 0, right = 0; right < A.length(); right++)
    {
        a[A[right]]++;
        if (a[A[right]] <= b[A[right]])
            count++;
        if (count == B.length())
        {
            while (a[A[left]] > b[A[left]])
            {
                a[A[left]]--;
                left++;
            }
            if (mn > right - left + 1)
            {
                mn = right - left + 1;
                x = left;
            }
        }
    }
    return mn < INT_MAX ? A.substr(x, mn) : "";
}

int main()
{
    string S = "ADOBECODEBANC", T = "ABC";
    cout << minWindow(S, T) << endl;
}
