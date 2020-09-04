/*
    Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

    Input:
        (1, 1), (2, 2)
    Output:
        2
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int maxPoints(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    if (n <= 1)
    {
        return n;
    }
    int ans = 0;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp.clear();
        int dx, dy, dup = 0, max_c = 0;
        for (int j = i + 1; j < n; j++)
        {

            dy = B[j] - B[i];
            dx = A[j] - A[i];

            if (dx == 0 && dy == 0)
            {
                dup++;
                continue;
            }

            int fact = gcd(dx, dy);
            dy = dy / fact;
            dx = dx / fact;

            string normal = to_string(dy) + "/" + to_string(dx);

            mp[normal]++;

            max_c = max(max_c, mp[normal]);
        }

        ans = max(ans, dup + 1 + max_c);
    }
    return ans;
}

int main()
{
    vector<int> A{1, 2, 1, 1, 1}, B{1, 2, 2, 3, 4};
    cout << maxPoints(A, B) << endl;
}
