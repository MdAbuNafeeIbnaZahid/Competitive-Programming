#include <bits/stdc++.h>
using namespace std;
long long T, Ax, Ay, Bx, By;
long long i, j, k, m;
long long gcd(long long a, long long b)
{
    //cout << "a = " << a << ", b = " << b << endl;
    if (a>b) return gcd(b, a);
    if (a==0) return b;
    return gcd(b%a, a);
}
long long myMod(long long a)
{
    return a<0 ? -a : a;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> Ax >> Ay >> Bx >> By;
        cout << "Case " << i << ": " << 1+gcd( myMod(Ax-Bx), myMod(Ay-By) ) << endl;
    }
    return 0;
}
