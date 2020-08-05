/*
    You are given N jobs where every job is represented as:
        1.Start Time
        2.Finish Time
        3.Profit Associated
    Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
*/

#include<bits/stdc++.h>
using namespace std;

struct Job {
    int s, f, p;
};

bool compare(Job j1, Job j2) {
    return j1.f <= j2.f;
}

int search(Job arr[], int n, int s) {
    int i=0, j=n-1, mid;
    while(i <= j) {
        mid = (i+j)/2;
        
        if(arr[mid].f == s) {
            return mid;
        } else if(arr[mid].f < s) {
            i = mid+1;
        } else {
            j = mid-1;
        }
    }
    return i-1;
}

int maxProfit(Job arr[], int n) {
    sort(arr, arr+n, compare);
    
    int dp[n], idx;
    dp[0] = arr[0].p;
    
    for(int i=1; i<n; i++) {
        idx = search(arr, i, arr[i].s);
        int prof = arr[i].p;
        if(idx != -1) {
            prof += dp[idx];
        }
        dp[i] = max(prof, dp[i-1]);
    }
    
    return dp[n-1];
}

int main()
{
	int n, x, y, z;
    cin >> n;
    Job arr[n];
    for(int i=0; i<n; i++) {
        cin >> x >> y >> z;
        arr[i] = {x, y, z};
    }
    
    cout << maxProfit(arr, n);
    return 0;
}