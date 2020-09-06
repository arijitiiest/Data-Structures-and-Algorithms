/*
    Given two arrays A & B of size N each.
    Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

    Input:
        N = 4
        a[]={1,4,2,3}
        b[]={2,5,1,6}
    Output:
        10   (4+6), 
        9    (3+6),
        9    (4+5),
        8    (2+6)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nPairs(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;

    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    st.insert({n - 1, n - 1});

    vector<int> ans;
    for (int p = 0; p < n; p++)
    {
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);

        int i = temp.second.first;
        int j = temp.second.second;

        pair<int, int> temp1 = {i - 1, j};
        if (st.find(temp1) == st.end())
        {
            pq.push({A[i - 1] + B[j], temp1});
            st.insert(temp1);
        }

        temp1 = {i, j - 1};
        if (st.find(temp1) == st.end())
        {
            pq.push({A[i] + B[j - 1], temp1});
            st.insert(temp1);
        }
    }
    return ans;
}

int main()
{
    vector<int> A{1, 4, 2, 3}, B{2, 5, 1, 6};

    vector<int> ans = nPairs(A, B);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
