/*
    You are given N elements, a1,a2,a3….aN. Find the number of good sub-arrays.
    A good sub-array is a sub-array [ai,ai+1,ai+2….aj] such that (ai+ai+1+ai+2+….+aj) is divisible by N.

    Input Format:
        The first line contains the number of test cases T. First line of each test case contains an integer N denoting 
        the number of elements. Second line of each test case contains N integers, a1, a2, a3….aN, where ai denotes the 
        ith element of the array.

    Constraints:
        1<=T<=10
        1<=N<=10^5
        |ai|<=10^9

    Output Format:
        Output a single integer denoting the number of good sub-arrays.

    Sample Input
        2
        5
        1 1 1 1 1
        5
        5 5 5 5 5
    Sample Output
        1
        15
*/

#include <bits/stdc++.h>
using namespace std;

int findNoOfGoodSubArrays(int A[], int n)
{
    int freq[5] = {0};
    int temp = 0;
    freq[0] = 1;
    for (int i = 0; i < n; i++)
    {
        temp = (temp + A[i]) % 5;
        freq[temp]++;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res += freq[i] * (freq[i] - 1) / 2;

    return res;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        cout << findNoOfGoodSubArrays(A, n) << endl;
    }
}
