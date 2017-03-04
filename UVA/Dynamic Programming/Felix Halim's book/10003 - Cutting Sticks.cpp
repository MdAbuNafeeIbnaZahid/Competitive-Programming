#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long l, n, dp[SIZE][SIZE], cAr[SIZE];
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> l;
        if ( l == 0 ) break;
        memset(dp, 0, sizeof(dp));
        cin >> n;
        cAr[0] = 0;
        for (a = 1; a <= n; a++)
        {
            scanf("%lld", &cAr[a]);
        }
        cAr[n+1] = l;
        for (a = 0; a <= n+1; a++)
        {
            for (b = 0; b <= n+1; b++)
            {
                dp[a][b] = INT_MAX;
                if ( a+1>=b ) dp[a][b] = 0;
            }
        }
        for (a = 2; a <= n+1; a++)
        {
            for (b = 0; b+a <= n+1; b++)
            {
                for (c = b+1; c < b+a; c++)
                {
                    dp[b][b+a] = min( dp[b][b+a], cAr[b+a]-cAr[b]+dp[b][c]+dp[c][b+a] );
                }
            }
        }
        for (a = 0; a <= n+1; a++)
        {
            for (b = 0; b <= n+1; b++)
            {
                //cout << dp[a][b] << " ";
            }
            //cout << endl;
        }
        cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
    }
    return 0;
}
