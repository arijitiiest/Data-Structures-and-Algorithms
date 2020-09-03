/*
    Given an array of integers A of size N and an integer B. 
    College library has N bags,the ith book has A[i] number of pages.
    You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.

    A book will be allocated to exactly one student.
    Each student has to be allocated at least one book.
    Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

    Calculate and return that minimum possible number.
    NOTE: Return -1 if a valid assignment is not possible.

    Input:
        A = [12, 34, 67, 90]
        B = 2
    Output:
        113
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> A, int mid, int B) {
    int n = A.size();
    int p = 1, total = 0;
    for(int i=0; i<n; i++) {
        total += A[i];
        if(total > mid) {
            total = A[i];
            p++;
        }
        if(p>B || A[i] > mid)
            return false;
    }
    return true;
}

int books(vector<int> &A, int B) {
    int n = A.size();
    if(n<B) return -1;
    int mn = INT_MAX, mx = INT_MIN;
    for(int i=0; i<n; i++){
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    mx = mx*(n/B+1);
    while(mn < mx) {
        int mid = mn + (mx-mn)/2;
        if(isPossible(A, mid, B)) {
            mx = mid;
        }else {
            mn = mid+1;
        }
    }
    return mn;
}

int main()
{
    vector<int> A = {12, 34, 67, 90};
    int B = 2;
    cout << books(A, B) << endl;
}