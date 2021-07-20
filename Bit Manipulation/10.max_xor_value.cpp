#include <bits/stdc++.h>
using namespace std;

int find_max_xor_pair(int *A, int n)
{
    int mask = 0, max_xor = 0;

    set<int> st;

    for (int i = 30; i >= 0; i--)
    {
        mask |= (1 << i);

        for (int j = 0; j < n; j++)
        {
            st.insert(A[j] & mask);
        }

        int new_max_xor = max_xor | (1 << i);

        for (int val : st)
        {
            if (st.count(new_max_xor ^ val))
            {
                max_xor = new_max_xor;
                break;
            }
        }

        st.clear();
    }
    return max_xor;
}

int main()
{
    int A[] = {25, 10, 2, 8, 5, 3};
    int n = sizeof(A) / sizeof(A[0]);

    cout << find_max_xor_pair(A, n) << endl;
    return 0;
}
