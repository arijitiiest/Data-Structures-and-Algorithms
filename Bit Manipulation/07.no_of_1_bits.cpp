/*
    Divide two integers without using multiplication, division and mod operator.
*/

#include <bits/stdc++.h>
using namespace std;

int noOfSetBits(unsigned int x)
{
    unsigned int totalOnes = 0;
    while (x)
    {
        x = x & (x - 1);
        totalOnes++;
    }
    return totalOnes;
}

int main()
{
    cout << noOfSetBits(10) << "\n";
}