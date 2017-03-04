#include <bits/stdc++.h>
using namespace std;
#define SIZE 19
long long T, m, n;
long long a, b, c, d, e, f, dp[SIZE][SIZE], given[SIZE], ans;
long long recDp(long long nIdx, long long mIdx)
{
    long long a, b, c, d, e;
    if ( nIdx == 1 )
    {
        if (given[mIdx]) return 1;
        else return 0;
    }
    if ( mIdx < 0 || !given[mIdx] ) return 0;
    if ( dp[nIdx][mIdx] == -1 )
    {
        dp[nIdx][mIdx] = 0;
        for (a = mIdx-2; a <= mIdx+2; a++)
        {
            dp[nIdx][mIdx] += recDp(nIdx-1, a);
        }
    }
    return dp[nIdx][mIdx];
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        memset(dp, -1, sizeof(dp));
        memset(given, 0, sizeof(given));
        cin >> m >> n;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld", &c);
            given[c] = 1;
        }
        for (b = 1; b <= n; b++)
        {
            for (c = 0; c <= 9; c++)
            {
                dp[b][c] = recDp(b, c);
            }
        }
        for (c = 0; c <= 9; c++) ans += recDp(n, c);
        cout << "Case " << a << ": " <<ans << endl;
    }
    return 0;
}
