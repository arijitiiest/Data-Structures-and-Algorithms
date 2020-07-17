/*
    A Linear Diophantine Equation (in two variables) is an equation of the general form:
            ax+by=c     where a, b, c are given integers, and x, y are unknown integers.
    
    Let gcd(a, b) = g
            a * xg + b * yg = g
            a * xg * c/g + b * yg * c/g = c

    Then,
            x0 = xg * c/g
            y0 = yg * c/g

    c/g should be integer
*/

#include <bits/stdc++.h>
using namespace std;
class Triplet
{
public:
    int x, y, gcd;
};

Triplet extended_euclidean(int a, int b)
{
    if (b == 0)
    {
        Triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    Triplet small_ans = extended_euclidean(b, a % b);
    Triplet ans;
    ans.x = small_ans.y;
    ans.y = small_ans.x - small_ans.y * (a / b);
    ans.gcd = small_ans.gcd;
    return ans;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0)
{
    Triplet ans = extended_euclidean(a, b);
    if (c % ans.gcd)
    {
        return false;
    }

    x0 = ans.x * c / ans.gcd;
    y0 = ans.y * c / ans.gcd;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}

int main()
{
    int a = 15, b = 10, c = 25;
    int x, y;
    if (!find_any_solution(a, b, c, x, y))
    {
        cout << "No solution found\n";
    }
    else
    {
        cout << "One solution is : " << x << " " << y << endl;
    }
    return 0;
}