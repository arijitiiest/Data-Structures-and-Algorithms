/*
    Given two numbers represented as strings, return multiplication of the numbers as a string.
*/

#include <bits/stdc++.h>
using namespace std;

string mul(string A, char ch)
{
    string str;
    int a, b;
    b = int(ch) - int('0');
    int carry = 0;
    int r = 0;
    for (int i = A.length() - 1; i >= 0; i--)
    {
        int a = int(A[i]) - int('0');
        r = (a * b + carry) % 10;
        carry = (a * b + carry) / 10;
        str.push_back(char(r + int('0')));
    }
    if (carry)
    {
        str.push_back(char(carry + int('0')));
    }
    reverse(str.begin(), str.end());
    return str;
}

string add(string A, string B)
{
    int n = A.size(), m = B.size();
    if (n > m)
    {
        int t = n - m;
        string s;
        while (t--)
        {
            s.push_back('0');
        }
        B.insert(0, s);
    }
    if (m > n)
    {
        int t = m - n;
        string s;
        while (t--)
        {
            s.push_back('0');
        }
        A.insert(0, s);
    }
    string res;
    int r, c = 0;
    for (int i = A.length() - 1; i >= 0; i--)
    {
        r = int(A[i]) - int('0') + int(B[i]) - int('0') + c;
        c = r / 10;
        r = r % 10;
        res.push_back(char(r + int('0')));
    }
    if (c)
    {
        res.push_back(char(c + int('0')));
    }
    reverse(res.begin(), res.end());
    return res;
}

string multiply(string A, string B)
{
    int n = A.length(), m = B.length();
    string res = "0", str;
    int j;
    for (int i = n - 1; i >= 0; i--)
    {
        str = mul(B, A[i]);
        j = 0;
        while (j < n - 1 - i)
        {
            str.push_back('0');
            j++;
        }
        res = add(res, str);
    }
    j = 0;
    while (j < res.length() - 1 && res[j] == '0')
        j++;
    return res.substr(j);
}

int main()
{
    string A = "12", B = "10";
    cout << multiply(A, B) << endl;
}
