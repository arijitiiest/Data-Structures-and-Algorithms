/*
    You are given a string, S, and a list of words, L, that are all of the same length.

    Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
    and without any intervening characters.

    Input:
        S: "barfoothefoobarman"
        L: ["foo", "bar"]
    Output:
        [0, 9]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string A, vector<string> &B)
{
    int noOfWords = B.size();
    vector<int> res;
    if (A.size() == 0 || B.size() == 0)
    {
        return res;
    }

    int wordSize = B[0].size();
    unordered_map<string, int> hash;

    for (const auto &b : B)
        ++hash[b];

    auto i = 0;
    while ((i + wordSize * noOfWords - 1) < A.size())
    {
        unordered_map<string, int> tempHash;
        auto j = 0;
        while (j < A.size())
        {
            string word = A.substr(i + j * wordSize, wordSize);
            if (hash.find(word) == hash.end())
                break;
            else
            {
                if (++tempHash[word] > hash[word])
                {
                    break;
                }
                ++j;
            }

            if (j == noOfWords)
                res.emplace_back(i);
        }
        ++i;
    }

    return res;
}

int main()
{
    string A = "barfoothefoobarman";
    vector<string> B{"foo", "bar"};

    vector<int> res = findSubstring(A, B);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}
