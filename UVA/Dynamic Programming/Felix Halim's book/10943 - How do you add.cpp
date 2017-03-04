#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define MOD 1000000
long long N, K, dp[SIZE][SIZE];
long long a, b, c, d, e, f;
long long recDp(long long a, long long b)
{
    if ( a<0 || b<0  ) return 0;
    return dp[a][b];
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> N >> K;
        if (N+K==0) break;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (a = 1; a <= K; a++)
        {
            for (b = 0; b <= N; b++)
            {
                for (c = 0; c <= b; c++)
                {
                    dp[a][b] = (dp[a-1][b-c]%MOD + dp[a][b]%MOD)%MOD;
                }
            }
        }
        cout << dp[K][N] << endl;
    }
    return 0;
}
