/*
    Given an string str. The only operation allowed is to insert characters in the beginning of the string.

    Find how many minimum characters are needed to be inserted to make the string a palindrome string.

    Example:
        Input:
            str = "AACECAAAA"
        Output:
            2
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "AACECAAAA";

    int start = 0, end = str.length() - 1;
    int temp_end = end;
    while (start <= temp_end)
    {
        if (str[start] == str[temp_end])
        {
            start++;
            temp_end--;
        }
        else
        {
            start = 0;
            temp_end = --end;
        }
    }

    cout << str.length() - (end + 1) << endl;
}
