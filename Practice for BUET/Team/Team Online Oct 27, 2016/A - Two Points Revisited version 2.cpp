#include <bits/stdc++.h>
using namespace std;
long long T, X1, Y1, X2, Y2;
long long ansx1, ansy1, ansx2, ansy2, dy, dx, S;
long long a, b, c, d, e, f, g;
long long ifOk(long long a, long long b, long long c, long long d, long long s)
{
    if ( a<0 || a>s ) return 0;
    if ( b<0 || b>s ) return 0;
    if ( c<0 || c>s ) return 0;
    if ( d<0 || d>s ) return 0;
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%lld %lld %lld %lld", &X1, &Y1, &X2, &Y2);
        S = max(max(X1, Y1), max(X2, Y2) );
        dy = Y1-Y2;
        dx = X1-X2;


        printf("Case %lld: ", a);
        ansx1 = dy;
        ansy1 = 0;
        ansx2 = 0;
        ansy2 = dx;
        if( ifOk(ansx1, ansy1, ansx2, ansy2, S) )
        {
            printf("%lld %lld %lld %lld\n", ansx1, ansy1, ansx2, ansy2);
            continue;
        }

        ansx1 = -dy;
        ansy1 = 0;
        ansx2 = 0;
        ansy2 = -dx;
        if( ifOk(ansx1, ansy1, ansx2, ansy2, S) )
        {
            printf("%lld %lld %lld %lld\n", ansx1, ansy1, ansx2, ansy2);
            continue;
        }

        ansx1 = S+dy;
        ansy1 = 0;
        ansx2 = S;
        ansy2 = dx;
        if( ifOk(ansx1, ansy1, ansx2, ansy2, S) )
        {
            printf("%lld %lld %lld %lld\n", ansx1, ansy1, ansx2, ansy2);
            continue;
        }

        ansx1 = S-dy;
        ansy1 = 0;
        ansx2 = S;
        ansy2 = -dx;
        if( ifOk(ansx1, ansy1, ansx2, ansy2, S) )
        {
            printf("%lld %lld %lld %lld\n", ansx1, ansy1, ansx2, ansy2);
            continue;
        }
    }
    return 0;
}
