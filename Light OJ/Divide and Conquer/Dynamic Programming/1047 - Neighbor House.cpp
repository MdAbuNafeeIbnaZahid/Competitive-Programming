#include <bits/stdc++.h>
using namespace std;
#define SIZE 29
long long T, n;
long long a, b, c, d, input[SIZE][9], dp[SIZE][9], ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            for (c = 1; c <= 3; c++)
            {
                scanf("%lld", &input[b][c]);
                dp[b][c] = INT_MAX;
            }
        }
        for (c = 1; c <= 3; c++)
        {
            dp[0][c] = 0;
        }
        for(b = 1; b<= n; b++)
        {
            for (c = 1; c <= 3; c++)
            {
                for (d = 1; d <= 3; d++)
                {
                    if (c!=d)
                    {
                        dp[b][c] = min(dp[b][c], dp[b-1][d]+input[b][c]);
                    }
                }
            }
        }
        ans = min(min(dp[n][1], dp[n][2]), dp[n][3]);
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
