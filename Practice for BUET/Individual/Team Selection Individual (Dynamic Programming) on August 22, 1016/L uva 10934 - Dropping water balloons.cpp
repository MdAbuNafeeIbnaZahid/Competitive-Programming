#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long dp[SIZE][SIZE];
long long a, b, c, d, e, f, g, h, t, n, ans, k;
long long maxH(long long b, long long t)
{
    long long lowerH, higherH;
    if( dp[b][t] == -1 )
    {
        if(b<=0 || t<=0) dp[b][t] = 0;
        else
        {
            lowerH = maxH(b-1, t-1);
            higherH = maxH(b, t-1);
            dp[b][t] = lowerH + 1 + higherH;
        }
    }
    return dp[b][t];
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(dp, -1, sizeof(dp) );
    for (b = 0; a < SIZE; a++)
    {
        for (t = 0; t <= 69; t++)
        {
            maxH(b, t);
        }
    }
    while(1)
    {
        scanf("%lld %lld", &k, &n);
        if(k==0) break;
        for (ans = 0; ans <= 63; ans++)
        {
            if( maxH(k, ans) >= n ) break;
        }
        if(ans > 63) cout << "More than 63 trials needed." << endl;
        else cout << ans << endl;
    }
    return 0;
}
