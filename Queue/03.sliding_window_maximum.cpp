/*
    Given an array of integers A. There is a sliding window of size B which is moving from the very left of the array 
    to the very right. You can only see the w numbers in the window. Each time the sliding window moves rightwards by 
    one position. You have to find the maximum for each window.

    Input:
        A = [1, 3, -1, -3, 5, 3, 6, 7]
        B = 3
    Output:
        C = [3, 3, 5, 5, 6, 7]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    int n = A.size();
    vector<int> res;
    deque<int> dq(B);

    int i = 0;
    while (i < B && i < n)
    {
        while (!dq.empty() && A[dq.back()] <= A[i])
            dq.pop_back();
        dq.push_back(i);
        i++;
    }

    for (; i < n; i++)
    {
        res.push_back(A[dq.front()]);

        while (!dq.empty() && dq.front() <= i - B)
            dq.pop_front();

        while (!dq.empty() && A[dq.back()] <= A[i])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(dq.front());
    return res;
}

int main()
{
    vector<int> A{1, 3, -1, -3, 5, 3, 6, 7};
    int B = 3;

    vector<int> ans = slidingMaximum(A, B);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}