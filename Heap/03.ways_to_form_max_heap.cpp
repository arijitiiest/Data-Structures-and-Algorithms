/*
    Max Heap is a special kind of complete binary tree in which for every node the value present in that 
    node is greater than the value present in it’s children nodes.

    Find the number of distinct Max Heap can be made from A distinct integers.

    In short, you have to ensure the following properties for the max heap :

    Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the 
    last, is completely filled, and all nodes are as far left as possible.)
    
    Every node is greater than all its children.

    NOTE: Return your answer modulo 109 + 7.

    Input:
        10
    Output:
        3360
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

// Calculate nCk % MOD
vector<vector<long long>> calculate_combinations(int n, int k)
{
    vector<vector<long long>> result(n + 1, vector<long long>(k + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                result[i][j] = 1;
            }
            else
            {
                result[i][j] = (result[i - 1][j - 1] % MOD + result[i - 1][j] % MOD) % MOD;
            }
        }
    }

    return result;
}

int left_subtree_elements(int total_elements)
{
    if (total_elements == 1)
    {
        return 0;
    }

    int height = log2(total_elements);
    int max_elements_last = (1 << height);
    int actual_elements_last = total_elements - ((1 << height) - 1);

    // If last level is more than half filled
    if (actual_elements_last >= (max_elements_last / 2))
    {
        return (1 << height) - 1;
    }
    // If last level is less than half filled
    return (1 << height) - 1 - (max_elements_last / 2) + actual_elements_last;
}

int main()
{
    int A = 10;

    vector<vector<long long>> ncr = calculate_combinations(A, A);

    vector<long long> dp(A + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= A; i++)
    {
        int left = left_subtree_elements(i);
        dp[i] = ((ncr[i - 1][left] * dp[left]) % MOD * dp[i - 1 - left]) % MOD;
    }

    cout << dp[A] << endl;
}

/*
    Explanation:
        1. Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among 
            this n distinct element will surely be placed on the root of the heap.

        2. Now there will be remaining (n-1) elements to be arranged.

        3. Now point to be remembered here is that the structure of the heap will remain the same. That is only the values within 
            the node will change however the overall structure remaining the same.

        4. As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) 
            will be fixed. And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality holds .
                L + R = (n-1) 
        
        5. Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L elements 
            among ‘n-1` elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap property.

        6. So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.

        7. So final equation will be as follows :
            (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 
        
        8. So now the question remains only of finding L for given n. It can be found as follows:

        9. Find the height of the heap h = log2(n)

        10. Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2h

        11. Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. p = n - (2h - 1)

        12. Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2h - 1

        13. However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of 
            the last level.

        14. So final equation for L will be as follows :
            L = 2h - 1 if p >= m/2
                            = 2h - 1 - (m/2 - p) if p<(m/2) 
*/
