#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long  n, k, ci[SIZE], isCapital[SIZE], ans, cumCi[SIZE], cumCiCap[SIZE], id;
long long a, b, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ci[a]);
    }
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &id);
        isCapital[id] = 1;
    }
    for (a = 1; a <= n; a++)
    {
        cumCiCap[a] = isCapital[a] * ci[a];
    }
    for (a = 1; a <= n; a++)
    {
        cumCi[a] = cumCi[a-1] + ci[a];
        cumCiCap[a] += cumCiCap[a-1];
    }
    for (a = 1; a < n; a++)
    {
        if ( isCapital[a] )
        {
            ans += (ci[a] * ( cumCi[n] - cumCi[a] ) );
        }
        else
        {
            ans += (ci[a] * (cumCiCap[n] - cumCiCap[a]) );
            if ( !isCapital[a+1] ) ans += ( ci[a] * ci[a+1] );
        }
    }
    if ( !isCapital[1] && !isCapital[n] ) ans += ( ci[1] * ci[n] );
    cout << ans << endl;
    return 0;
}
