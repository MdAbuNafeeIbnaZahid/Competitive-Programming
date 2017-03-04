#include <bits/stdc++.h>
using namespace std;
#define SIZE 16
long long T, N;
long long a, b, c, d, e, f, pr[SIZE][SIZE];
long long mask;
long long dp[SIZE][1<<SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> N;
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < N; c++)
            {
                scanf("%lld", &pr[b][c]);
            }
        }
        for (b = 0; b < N; b++)
        {
            dp[0][1<<b] = pr[0][b];
        }
        for (b = 0; b < N-1; b++)
        {
            for (c = 0; c < (1<<(N)); c++ )
            {
                if ( dp[b][c] == -1 ) continue;
                //cout << "b = " << b << ", c = " << c << endl;
                for (d = 0; d < N; d++)
                {
                    mask = (1<<d);
                    //cout << "mask = " << mask << endl;
                    if ( (mask & c) == 0 )
                    {
                        //cout << "b+1 = " << b+1 << endl;
                        //cout << "c|mask = " << (c|mask) << endl;
                        dp[b+1][c|mask] = max(dp[b+1][c|mask], dp[b][c]+pr[b+1][d]);
                    }
                }
            }
        }
        for (b = 0; b <= N; b++)
        {
            for (c = 0; c <  (1<<N+1); c++)
            {
                //cout << dp[b][c] << " ";
            }
            //cout << endl;
        }
        cout << "Case " << a << ": " << dp[N-1][(1<<N)-1] << endl;
    }
    return 0;
}
