/*
    You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all 
    windows of size B.

    Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence 
        Ai, Ai+1 ,..., Ai+B-1.

    NOTE: if B > N, return an empty array.

    Input:
        A = [1, 2, 1, 3, 4, 3]
        B = 3
    Output:
        [2, 3, 3, 2]
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B)
{
    assert(B <= A.size());
    int n = A.size();
    vector<int> ret;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        //increase key
        m[A[i]]++;
        if (i - B + 1 >= 0)
        {

            //decrease key
            ret.push_back(m.size());
            m[A[i - B + 1]]--;

            //remove if count becomes 0
            if (m[A[i - B + 1]] == 0)
                m.erase(A[i - B + 1]);
        }
    }
    return ret;
}

int main()
{
    vector<int> A{1, 2, 1, 3, 4, 3};
    int B = 3;

    vector<int> res = dNums(A, B);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}
