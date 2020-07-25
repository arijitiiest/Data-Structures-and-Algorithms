/*
    Sort the elements of an array using selection sort algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

void bucket_sort(float *arr, int n)
{
    vector<float> bucket[n];

    for(int i=0; i<n; i++) {
        int bi = arr[i]*n;
        bucket[bi].push_back(arr[i]);
    }

    for(int i=0; i<n; i++)
        sort(bucket[i].begin(), bucket[i].end());

    int index = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<bucket[i].size(); j++)
            arr[index++] = bucket[i][j];
}

int main()
{
    float arr[] = {0.12, 0.8, 0.17, 0.568, 0.255, 0.1234, 0.4862};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
