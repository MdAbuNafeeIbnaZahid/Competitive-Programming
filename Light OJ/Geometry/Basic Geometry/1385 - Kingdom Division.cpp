#include <bits/stdc++.h>
using namespace std;
long long T;
double a, b, c, d;
long long i, j, k;
double p, q;
int main()
{
    freopen("input.txt", "r",stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lf %lf %lf", &a, &b, &c);
        if ( b == 0 )
        {
            cout << "Case " << i << ": " << -1 << endl;
            continue;
        }
        p = (c*a)/b;
        if ( b == p )
        {
            cout << "Case " << i << ": " << -1 << endl;
            continue;
        }
        q = ( (p+a)*(p+c) )/(b-p);
        if ( q < 0 )
        {
            cout << "Case " << i << ": " << -1 << endl;
            continue;
        }
        d = p+q;
        if (d<0) d = -1;
        printf("Case %lld: %0.9lf\n", i, d);
    }
    return 0;
}
