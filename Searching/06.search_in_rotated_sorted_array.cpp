/*
    Given an array of integers A of size N and an integer B. Array A is rotated at some pivot unknown to you beforehand.
    You are given a target value B to search. If found in the array, return its index, otherwise return -1.
    You may assume no duplicate exists in the array.

    Input 1:
        A = [4, 5, 6, 7, 0, 1, 2, 3]
        B = 4
    Output 1:
        0

    Algorithm:
        1) Find middle point mid = (l + h)/2
        2) If key is present at middle point, return mid.
        3) Else If arr[l..mid] is sorted
            a) If key to be searched lies in range from arr[l]
            to arr[mid], recur for arr[l..mid].
            b) Else recur for arr[mid+1..h]
        4) Else (arr[mid+1..h] must be sorted)
            a) If key to be searched lies in range from arr[mid+1]
            to arr[h], recur for arr[mid+1..h].
            b) Else recur for arr[l..mid]
*/
#include<bits/stdc++.h>
using namespace std;

int search(const vector<int> &A, int B) {
    int n = A.size();
    int mn = 0, mx = n-1;
    while(mn <= mx) {
        int mid = mn + (mx-mn)/2;
        if(A[mid] == B) {
            return mid;
        }
        
        if(A[mn] <= A[mid]) {
            if(A[mid]>=B && A[mn]<=B) {
                mx = mid;
            } else {
                mn = mid+1;
            }
        } else {
            if(A[mid]<=B && A[mx]>=B) {
                mn = mid;
            } else {
                mx = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> A{4, 5, 6, 7, 0, 1, 2, 3};
    int B = 4;
    cout << search(A, B) << endl;
}