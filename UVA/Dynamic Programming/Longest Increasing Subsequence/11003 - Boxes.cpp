#include <bits/stdc++.h>
using namespace std;
#define SIZE 6009
long long N, weight[SIZE], maxLoad[SIZE], dp[SIZE][SIZE];
long long a, b, c, d, e, i, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        memset(dp, 0, sizeof(dp));
        ans = 0;
        cin >> N;
        if (N==0) return 0;
        for (i = 1; i <= N; i++)
        {
            scanf("%lld %lld", &weight[i], &maxLoad[i]);
        }
        for (a = N; a >= 1; a--)
        {
            for (b = 0; b < SIZE; b++)
            {
                if ( b-weight[a] < 0 ) dp[a][b] = dp[a+1][b];
                else
                {
                    dp[a][b] = max( dp[a+1][b], 1+dp[a+1][ min(maxLoad[a], b-weight[a] ) ] );
                }
            }
        }
        for (b = 0; b < SIZE; b++)
        {
            ans = max(ans, dp[1][b]);
        }
        cout << ans << endl;
    }
    return 0;
}
