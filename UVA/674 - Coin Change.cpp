#include <bits/stdc++.h>
using namespace std;
#define INF 999999
int dp[10][300], input[10], value[] = {0, 1, 2, 4, 10, 20, 40};
int i, j, k, m, n, w, x, y, z, ans;
double trans;
int amount;
int main()
{
    freopen("input.txt", "r", stdin);
    while(true)
    {
        memset(dp, INF, sizeof(dp));
        for (i = 1; i <= 6; i++) cin >> input[i];
        for (i = 1; i <= 6; i++) if (input[i] != 0) break;
        if (i > 6) return 0;
        cin >> trans;
        amount = trans / .05;
        for (i = 1; i <= 6; i++) dp[i][0] = 0;
        for (j = 1; j <= input[6]; j++)
        {
            dp[6][ j*value[6] ] = j;
        }
        for (i = 5; i >= 1; i--)
        {
            for (j = 1; j < 250; j++)
            {
                for (k = 1; k <= input[i]; k++)
                {
                    dp[i][j] = min( dp[i+1][j], k + dp[i+1][j - k*value[i]   ]);
                }
            }
        }
        ans = INF;
        for (j = 0; j <= 220-amount; j+=2) ans = min(ans, dp[1][j + amount ] );
        cout.width(3);
        cout << ans << endl;
    }
    return 0;
}
