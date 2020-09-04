/*
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

    Input:
        n = 3
    Output:
        "((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <bits/stdc++.h>
using namespace std;

void allSubsets(int n, vector<string> &res, string &str, int leftP, int rightP)
{
    if (leftP == n && rightP == n)
    {
        res.push_back(str);
        return;
    }

    if (leftP > n || rightP > n)
        return;

    if (leftP < n)
    {
        str.push_back('(');
        allSubsets(n, res, str, leftP + 1, rightP);
        str.pop_back();
    }

    if (leftP > rightP)
    {
        str.push_back(')');
        allSubsets(n, res, str, leftP, rightP + 1);
        str.pop_back();
    }
}

int main()
{
    int n = 3;
    vector<string> res;
    string str = "";

    allSubsets(n, res, str, 0, 0);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << "\n";
}
