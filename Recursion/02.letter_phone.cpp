/*
    Given a digit string, return all possible letter combinations that the number could represent.

    Input: Digit string "23"
    Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

#include <bits/stdc++.h>
using namespace std;

string chars[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void allCombination(string A, vector<string> &res, string str)
{
    if (A.length() == 0)
    {
        res.push_back(str);
        return;
    }
    int idx = A[0] - '0';
    for (int i = 0; i < chars[idx].length(); i++)
    {
        str.push_back(chars[idx][i]);
        allCombination(A.substr(1), res, str);
        str.pop_back();
    }
}

int main()
{
    string A = "23";
    vector<string> res;
    string str;

    allCombination(A, res, str);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}
