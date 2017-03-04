#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
int T, n, K, A[55], C[55];
int i, j, k, x, y, z, idx;
int dp[55][1009];
int main()
{
    freopen( "input.txt", "r", stdin );
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        for (j = 0; j < 55; j++)
            for (x = 0; x < 1009; x++) dp[j][x] = 0;
        cin >> n >> K;
        for (j = 1; j <= n; j++) cin >> A[j];
        for (j = 1; j <= n; j++) cin >> C[j];
        for (j = 0; j <= C[1]*A[1]; j+=A[1]) dp[1][j] = 1;
        for (j = 2; j <= n; j++)
        {
            for (x = 0; x <= K; x++)
            {
                for (y = 0; y <= C[j]*A[j]; y+=A[j])
                {
                    idx = x - y;
                    if (idx >= 0) dp[j][x] = (dp[j][x]%MOD + dp[j-1][idx]%MOD)%MOD;
                }
            }
        }
        cout << "Case " << i << ": " << dp[n][K] << "\n";
    }
    return 0;
}
