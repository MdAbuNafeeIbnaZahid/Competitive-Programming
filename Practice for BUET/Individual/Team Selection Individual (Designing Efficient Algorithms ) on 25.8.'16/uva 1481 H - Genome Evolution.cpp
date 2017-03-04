#include <bits/stdc++.h>
using namespace std;
#define SIZE 3009
long long n, g1[SIZE], g2[SIZE], idxOfG2[SIZE];
long long a, b, c, d, e, f, g, h, leftMost, ans, rightMost;
int main()
{
    freopen("input.txt", "r", stdin);
    while(cin >> n)
    {
        if (n == 0) return 0;
        ans = 0;
        for (a = 1; a <= n; a++)
        {
            scanf("%lld", &g1[a]);
        }
        for (a = 1; a <= n; a++)
        {
            scanf("%lld", &g2[a]);
            idxOfG2[ g2[a] ] = a;
        }
        for (a = 1; a <= n-1; a++)
        {
            leftMost = idxOfG2[ g1[a] ];
            rightMost = idxOfG2[ g1[a] ];
            for (b = a+1; b <= n; b++)
            {
                leftMost = min(leftMost, idxOfG2[ g1[b] ] );
                rightMost = max(rightMost, idxOfG2[g1[b] ] );
                if ( rightMost - leftMost == b-a ) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
