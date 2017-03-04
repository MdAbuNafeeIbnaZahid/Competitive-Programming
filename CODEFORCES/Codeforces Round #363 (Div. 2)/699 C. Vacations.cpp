#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, dp[SIZE][5], aAr[SIZE], ai, ans;
long long b, c, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (b = 1; b <= n; b++)
    {
        scanf("%lld", &aAr[b]);
        ai = aAr[b];
        dp[b][0] = dp[b][1] = max(dp[b-1][0], dp[b-1][1]);
        if (ai == 1)
        {
            dp[b][0] = max(dp[b][0], dp[b-1][1]+1);
        }
        else if (ai == 2)
        {
            dp[b][1] = max(dp[b][1], dp[b-1][0]+1);
        }
        else if (ai == 3)
        {
            dp[b][0] = max(dp[b][0], dp[b-1][1]+1);
            dp[b][1] = max(dp[b][1], dp[b-1][0]+1);
        }
    }
    ans = n - max(dp[n][0], dp[n][1]);
        cout << ans;
    return 0;
}
