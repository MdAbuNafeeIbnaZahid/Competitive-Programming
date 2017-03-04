#include <bits/stdc++.h>
using namespace std;
int T, n, m, A[105], C[105];
long long dp[100002];
int i, j, k,  b, x, y, z, idx, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;
        for (j = 1; j <= n; j++) cin >> A[j];
        for (j = 1; j <= n; j++) cin >> C[j];
        for (j = 0; j <= m; j++)
        {
            dp[j] = (j%A[1]==0 && j/A[1]<=C[1]);
            //dp[1][j] = 0;
            //if (j%A[1]==0 && j/A[1]<=C[1]) dp[1][j] = 1;
        }
        for (k = 2; k <= n; k++)
        {
            for (j = 0; j <= m; j++)
            {
                //dp[k][j] = dp[k-1][j];
                for (x = A[k]; x<=A[k]*C[k] && dp[j]!=1; x+=A[k])
                {
                    idx = j-x;
                    if (idx < 0) break;
                    dp[j] |= dp[idx];
                }
            }
        }
        ans = 0;
        for (j = 1; j <= m; j++)
        {
            ans += dp[j];
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
