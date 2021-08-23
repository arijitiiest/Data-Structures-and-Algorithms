/*
    You are given a multiset of N integers. Please find such a nonempty subset of it that the sum of the subset's elements is divisible by N. 
    Otherwise, state that this subset doesn't exist.

    Input
        The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
        The first line of each test consists of a single integer N - the size of the multiset.
        The second line of each test contains N single space separated integers - the multiset's elements.

    Output
    For each test case output:
        -1 if the required subset doesn't exist
        If the required subset exists, output two lines. Output the size of the subset on the first line and output the list of indices of the multiset's element that form the required subset. Of course, any number can be taken in the subset no more than once.
        If there are several such subsets, you can output any.

    Example
        Input:
            1
            3
            4 6 10

        Output:
            1
            2

    Problem: https://www.codechef.com/problems/DIVSUBS
*/

#include <bits/stdc++.h>
using namespace std;

void findDivisibleSubsets(int A[], int n)
{
    pair<int, vector<int>> freq[n] = {{0, vector<int>(0)}};
    freq[0].first = 1;
    freq[0].second.push_back(-1);
    long temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += A[i];
        temp %= n;
        freq[temp].first++;
        freq[temp].second.push_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[i].first >= 2)
        {
            cout << freq[i].second[1] - freq[i].second[0] << endl;
            for (int j = freq[i].second[0] + 2; j <= freq[i].second[1] + 1; j++)
                cout << j << " ";
            return;
        }
    }
    cout << "-1\n";
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

        findDivisibleSubsets(A, n);
    }
    return 0;
}