/*
    You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School 
    and Open matches. For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better 
    than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least 
    one being greater. For each coder i, determine how many coders coder i is better than.

    Sample Input
        8
        1798 1832
        862 700
        1075 1089
        1568 1557
        2575 1984
        1033 950
        1656 1649
        1014 1473
    Sample Output
        6
        0
        2
        4
        7
        1
        5
        1
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_RATING 100001

struct coder
{
    int rating1, rating2, index;
};

bool compare(coder r1, coder r2)
{
    return r1.rating1 == r2.rating1 ? r1.rating2 < r2.rating2 : r1.rating1 < r2.rating1;
}

void update(int *BIT, int x)
{
    for (; x < MAX_RATING; x += x & (-x))
    {
        BIT[x]++;
    }
}

int query(int *BIT, int x)
{
    int ans = 0;
    for (; x > 0; x -= x & (-x))
    {
        ans += BIT[x];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    coder *arr = new coder[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].rating1 >> arr[i].rating2;
        arr[i].index = i;
    }
    sort(arr, arr + n, compare);

    int *BIT = new int[MAX_RATING];
    int *ans = new int[n];
    for (int i = 0; i < n;)
    {
        int endIndex = i;
        while (endIndex < n && arr[i].rating1 == arr[endIndex].rating1 && arr[i].rating2 == arr[endIndex].rating2)
        {
            endIndex++;
        }
        for (int j = i; j < endIndex; j++)
        {
            ans[arr[j].index] = query(BIT, arr[j].rating2);
        }
        for (int j = i; j < endIndex; j++)
        {
            update(BIT, arr[j].rating2);
        }
        i = endIndex;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
