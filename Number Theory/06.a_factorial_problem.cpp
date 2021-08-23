/*
    You are given two integers n and k. You need to find maximum value of x, such that, 
        n! % k^x = 0
    
    Input Format: 
        first line contains no of test cases T. Each test case contains two integers n and k. 

    Constraints:
        1 <= T <= 20,
        1 <= n <= 10^8
        2 <= k <= 10^8

    Output Format: 
        Print the value of x for each test case.

    Example:
        Input:
            2
            5 2
            1000 2
        Output:
            3
            994
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ans = INT_MAX;

        for (int i = 2; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                int occurs = 0;
                while (k % i == 0)
                {
                    occurs++;
                    k /= i;
                }

                int count = 0;
                int p = i;
                
                while (p <= n)
                {
                    count += (n / p);
                    p *= i;
                }

                ans = min(ans, count / occurs);
            }
        }

        if (k != 1)
        {
            int count = 0;
            int p = k;

            while (p <= n)
            {
                count += (n / p);
                p *= k;
            }

            ans = min(ans, count);
        }

        cout << ans << endl;
    }

    return 0;
}