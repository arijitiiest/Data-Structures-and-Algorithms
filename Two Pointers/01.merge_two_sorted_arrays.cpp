/*
    Given two sorted integer arrays A and B, merge B into A as one sorted array.

    Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.

    Input : 
         A : [1 5 8]
         B : [6 9]

    Modified A : [1 5 6 8 9]
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B)
{
    int i = A.size() - 1;
    int j = B.size() - 1;
    int lastPos = A.size() + B.size() - 1;

    A.resize(A.size() + B.size());

    while (j >= 0)
    {
        if (i >= 0 && A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }
}

int main()
{
    vector<int> A{1, 5, 8}, B{6, 9};
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;
    merge(A, B);
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
