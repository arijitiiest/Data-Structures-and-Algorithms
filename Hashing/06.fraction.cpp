/*
    Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

    If the fractional part is repeating, enclose the repeating part in parentheses.

    Example:
        Given numerator = 1, denominator = 2, return "0.5"
        Given numerator = 2, denominator = 1, return "2"
        Given numerator = 2, denominator = 3, return "0.(6)"
*/

#include <bits/stdc++.h>
using namespace std;

string fractionToDecimal(int A, int B)
{
    if (A == 0)
        return "0";
    if (B == 0)
        return "";

    string res = "";
    if (A < 0 ^ B < 0)
        res += '-';

    res += to_string(A / B);
    int rem = A % B;

    if (rem == 0)
        return res;

    res += ".";

    unordered_map<int, int> mp;
    for (; rem; rem %= B)
    {
        if (mp.find(rem) != mp.end())
        {
            res.insert(mp[rem], 1, '(');
            res.push_back(')');
            return res;
        }
        mp[rem] = res.size();
        rem *= 10;
        res.push_back('0' + rem / B);
    }
    return res;
}

int main()
{
    int A = 2, B = 3;
    cout << fractionToDecimal(A, B) << endl;
}
