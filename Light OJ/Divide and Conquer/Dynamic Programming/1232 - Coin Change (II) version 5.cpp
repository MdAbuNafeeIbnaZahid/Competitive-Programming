#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
long long T, n, K, A[105], C[105];
long long i, j,  x, y, z, idx;
long long dp[10009];
int main()
{
    freopen( "input.txt", "r", stdin );
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> K;
        for (j = 1; j <= n; j++) cin >> A[j];
        for (j = 0;  j <=K; j+=A[1]) dp[j] = 1;
        for (j = 2; j <= n; j++)
        {
            for (x = 0; x <= K; x++)
            {
                //dp[j][x] = dp[j-1][x] % MOD;
                idx = x-A[j];
                if (idx >= 0) dp[x] = (dp[x]%MOD + dp[idx]%MOD )%MOD;
            }
        }
        cout << "Case " << i << ": " << dp[K]%MOD << endl;
    }
    return 0;
}

