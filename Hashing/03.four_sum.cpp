/*

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &A, int B)
{
    int N = A.size();
    unordered_map<int, vector<pair<int, int>>> mp;
    vector<vector<int>> Ans;

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            int Sum = A[i] + A[j];

            if (mp.find(B - Sum) != mp.end())
            {
                vector<pair<int, int>> vec = mp[B - Sum];

                for (int k = 0; k < vec.size(); k++)
                {
                    if (vec[k].first != i && vec[k].first != j && vec[k].second != i && vec[k].second != j)
                    {
                        vector<int> ans;
                        ans.push_back(A[vec[k].first]);
                        ans.push_back(A[vec[k].second]);
                        ans.push_back(A[i]);
                        ans.push_back(A[j]);

                        sort(ans.begin(), ans.end());
                        if (find(Ans.begin(), Ans.end(), ans) == Ans.end())
                            Ans.push_back(ans);
                    }
                }
            }
            mp[Sum].push_back(make_pair(i, j));
        }
    }

    sort(Ans.begin(), Ans.end());
    return Ans;
}

int main()
{
    vector<int> A{1, 0, -1, 0, -2, 2};
    int B = 0;
    vector<vector<int>> ans = fourSum(A, B);

    for(int i=0; i<ans.size(); i++)
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << "\n";
}
