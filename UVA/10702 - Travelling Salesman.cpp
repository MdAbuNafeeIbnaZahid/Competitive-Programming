#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define INF 999999999
int C, S, E, T;
int i, j, k, m, n, a, b, x, y, z;
int profit[SIZE][SIZE];
int dp[1009][109];
int termination[109], maxProfit, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> C >> S >> E >> T;
        if (C+S+E+T==0) return 0;
        for (i = 1; i <= C; i++)
            for (j = 1; j <= C; j++) cin >> profit[i][j];
        for (i = 1; i <= E; i++) cin >> termination[i];
        for (i = 0; i <= T; i++)
            for (j = 1; j <= C; j++) dp[i][j] = -INF;
        dp[0][S] = 0;
        for (i = 1; i <= T; i++)
            for (j = 1; j <= C; j++)
            {
                for (k = 1; k <= C; k++) dp[i][j] = max(dp[i][j], dp[i-1][k]+profit[k][j]);
            }
        ans = -INF;
        for (i = 1; i <= E; i++) ans = max(ans, dp[T][termination[i]]);
        cout << ans << endl;
    }
    return 0;
}
