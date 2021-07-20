/*
    Divide two integers without using multiplication, division and mod operator.

    Return the floor of the result of the division.

    Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*/

#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    int sign = 1;
    if (dividend<0){sign = -sign;}
    if (divisor<0){sign = -sign;}
     
    unsigned long long temp1 = abs((long long)dividend);
    unsigned long long temp2 = abs((long long)divisor);
     
    long long res = 0, t = 0;
    for(int i=31; i>=0; i--) {
        if(t + (temp2<<i) <= temp1) {
            t += (temp2 << i);
            res |= 1LL << i;
        }
    }
     
    return (sign*res >= INT_MAX ||  sign*res < INT_MIN) ? INT_MAX : sign*res;
}

int main()
{
    cout << divide(5, 2) << "\n";
}