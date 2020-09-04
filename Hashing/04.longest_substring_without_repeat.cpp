/*
    Given a string,
    find the length of the longest substring without repeating characters.

    Input:
        "abcabcbb"
    Output:
        "abc"
*/

#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubstr(string str)
{
    int n = str.length();
    int i = -1, j = 0;
    int max_len = 1;
    unordered_map<char, int> mp;
    while (j < n)
    {
        if (mp.find(str[j]) != mp.end())
            i = max(i, mp[str[j]]);

        max_len = max(max_len, j - i);
        mp[str[j]] = j;
        j++;
    }
    return max_len;
}

int main()
{
    string str = "abcabcbb";
    cout << lenOfLongSubstr(str) << endl;
}
