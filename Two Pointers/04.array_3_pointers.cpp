/*
    You are given 3 arrays A, B and C. All 3 of the arrays are sorted.
    Find i, j, k such that :
    max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
    Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

    Example:
        Input : 
            A : [1, 4, 10]
            B : [2, 15, 20]
            C : [10, 12]

        Output : 5 
            With 10 from A, 15 from B and 10 from C. 
*/

#include <bits/stdc++.h>
using namespace std;

int minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c)
{
    int diff = INT_MAX;
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();)
    {
        minimum = min(a[i], min(b[j], c[k]));
        maximum = max(a[i], max(b[j], c[k]));
        diff = min(diff, maximum - minimum);
        if (diff == 0)
            break;
        if (a[i] == minimum)
            i++;
        else if (b[j] == minimum)
            j++;
        else
            k++;
    }
    return diff;
}

int main()
{
    vector<int> A{1, 4, 10}, B{2, 15, 20}, C{10, 12};
    cout << minimize(A, B, C) << endl;
}
