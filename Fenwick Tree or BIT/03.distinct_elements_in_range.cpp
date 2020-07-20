/*
    Given a sequence of n numbers a1, a2, ..., an. For each query (i, j), 
    you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
    Input:
        5
        1 1 2 1 3
        3
        1 5
        2 4
        3 5
    Output:
        3
        2
        3 
*/

#include <bits/stdc++.h>
using namespace std;

class event
{
public:
    int first, second, index;
};

bool compare(event e1, event e2)
{
    return e1.second < e2.second;
}

void update(int *BIT, int n, int value, int index)
{
    for (; index <= n; index += index & (-index))
        BIT[index] += value;
}

int value(int *BIT, int index)
{
    int count = 0;
    for (; index > 0; index -= index & (-index))
        count += BIT[index];
    return count;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int q;
    cin >> q;
    event *query = new event[q];
    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }
    sort(query, query + q, compare);

    int *BIT = new int[n + 1];
    int *ans = new int[q];
    int total = 0;
    int k = 0;
    int *unique = new int[1000001];
    for (int i = 0; i <= 1000000; i++)
        unique[i] = -1;

    for (int i = 1; i <= n; i++)
    {
        if (unique[arr[i]] != -1)
        {
            update(BIT, n, -1, unique[arr[i]]);
        }
        else
        {
            total++;
        }
        update(BIT, n, 1, i);
        unique[arr[i]] = i;

        while (k < q && query[k].second == i)
        {
            ans[query[k].index] = total - value(BIT, query[k].first - 1);
            k++;
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
    return 0;
}
