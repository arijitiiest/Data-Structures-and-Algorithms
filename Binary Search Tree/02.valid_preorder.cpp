/*
    You are given a preorder traversal A, of a Binary Search Tree.

    Find if it is a valid preorder traversal of a BST.
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n)
{
    stack<int> st;
    int root = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < root)
            return false;

        while (!st.empty() && st.top() < arr[i])
        {
            root = st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return true;
}

int main()
{
    int arr[] = {40, 30, 35, 80, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isValid(arr, n))
        cout << "Valid Preorder\n";
    else
        cout << "Not Valid Preorder\n";
}
