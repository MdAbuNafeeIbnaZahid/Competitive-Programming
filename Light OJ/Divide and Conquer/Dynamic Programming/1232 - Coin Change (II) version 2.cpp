#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
int T, n, K, A[105], C[105];
int i, j,  x, y, z, idx;
int dp[105][10009];
int main()
{
    //freopen( "input.txt", "r", stdin );
    //cin >> T;
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        //for (j = 0; j < 105; j++)
            //for (x = 0; x < 10009; x++) dp[j][x] = 0;
        //cin >> n >> K;
        getchar();
        scanf("%d %d", &n, &K);
        getchar();
        for (j = 1; j <= n; j++) scanf("%d", &A[j]);//cin >> A[j];
        //for (j = 1; j <= n; j++)  C[j] = K;

        //printf("\n n = %d, K = %d\n", n, K );
        //for (j = 1; j <= n; j++) printf("%d ", A[j]);//cin >> A[j];
        //printf("\n");

        for (j = 0; /*j <= C[1]*A[1] &&*/ j <=K; j+=A[1]) dp[1][j] = 1;
        for (j = 2; j <= n; j++)
        {
            for (x = 0; x <= K; x++)
            {
                dp[j][x] = dp[j-1][x];
                idx = x-A[j];
                if (idx >= 0) dp[j][x] = (dp[j][x]%MOD + dp[j][idx]%MOD )%MOD;

                //for (y = 0; /*y <= C[j]*A[j] && j*/ y <= K; y+=A[j])
                //{
                    //idx = x - y;
                    //if (idx < 0) break;
                    //dp[j][x] = (dp[j][x]%MOD + dp[j-1][idx]%MOD)%MOD;
                //}
            }
        }

        //for (j = 1; j <= n; j++)
        //{
            //for (x = 0; x <= K; x++) printf("%d ", dp[j][x]);
            //printf("\n");
        //}

        printf("Case %d: %d\n", i, dp[n][K]);
        //cout << "Case " << i << ": " << dp[n][K] << "\n";
    }
    return 0;
}
