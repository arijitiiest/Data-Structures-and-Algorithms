/*
    Extended Euclidean Algorithm finds a way to represent GCD in terms of a and b
        a.x + b.y = gcd(a, b)

    Algo:
        Euclidean algo ends a = g and b = 0, For that the coefficients are (x, y) = (1, 0)
                g.1 + 0.0 = g
        All we need to do is to figure out how the coefficients x and y change during the transition from (a,b) to (b,a mod b)

        Let us assume we found the coefficients (x1,y1) for (b,amodb):
                b⋅x1 + (a mod b)⋅y1 = g

        we want to find (x,y)  for (a,b)
                a⋅x + b⋅y = g

        we can represent
                a mod b = a − ⌊a/b⌋⋅b
            
                g = b⋅x1 + (a mod b)⋅y1 = b⋅x1 + (a − ⌊a/b⌋⋅b)⋅y1
                g = a.x + b.y

        We found the values of x and y:
                x = y1
                y = x1−y1⋅⌊a/b⌋
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

int main()
{
    Triplet ans = extended_euclidean(15, 10);
    cout << ans.x << endl
         << ans.y << endl
         << ans.gcd << endl;
    return 0;
}