#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
int T, n, K, A[105], C[105];
int i, j,  x, y, z, idx;
int dp[105][10009];
int main()
{
    freopen( "input.txt", "r", stdin );
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        getchar();
        scanf("%d %d", &n, &K);
        getchar();
        for (j = 1; j <= n; j++) scanf("%d", &A[j]);
        for (j = 0;  j <=K; j+=A[1]) dp[1][j] = 1;
        for (j = 2; j <= n; j++)
        {
            for (x = 0; x <= K; x++)
            {
                dp[j][x] = dp[j-1][x];
                idx = x-A[j];
                if (idx >= 0) dp[j][x] = (dp[j][x]%MOD + dp[j][idx]%MOD )%MOD;
            }
        }
        printf("Case %d: %d\n", i, dp[n][K]);
    }
    return 0;
}
