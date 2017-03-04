#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
long long T, n, K, A[105], C[105];
long long i, j,  x, y, z, idx;
long long dp[105][10009];
int main()
{
    freopen( "input.txt", "r", stdin );
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> n >> K;
        for (j = 1; j <= n; j++) cin >> A[j];
        for (j = 0;  j <=K; j+=A[1]) dp[1][j] = 1;
        for (j = 2; j <= n; j++)
        {
            for (x = 0; x <= K; x++)
            {
                dp[j][x] = dp[j-1][x] % MOD;
                idx = x-A[j];
                if (idx >= 0) dp[j][x] = (dp[j][x]%MOD + dp[j][idx]%MOD )%MOD;
            }
        }
        cout << "Case " << i << ": " << dp[n][K]%MOD << endl;
    }
    return 0;
}
