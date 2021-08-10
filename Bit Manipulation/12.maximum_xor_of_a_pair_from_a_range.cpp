/*

*/

#include<bits/stdc++.h>
using namespace std;

int getLastSetBitPos(int n)
{
    int count = 0;
    while(n) {
        count++;
        n >>= 1;
    }
    return count;
}

int getMaxXORInRange(int left, int right)
{
    int xori = left^right;

    int pos = getLastSetBitPos(xori);

    return (1 << pos) - 1;
}

int main()
{
    int L = 8;
    int R = 20;

    cout << getMaxXORInRange(L, R) << endl;
    return 0;
}