#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
double dp[109][SIZE], P, Pj;
long long T, N, Mj;
long long a, b, c, d, e, f, g, h, i, j, ans;
double recF(long long r, long long c)
{
    if ( c <= 0 ) return 0;
    else return dp[r][c];
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        for (b = 0; b <= 103; b++)
        {
            for (c = 0; c < SIZE; c++)
            {
                if ( c == 0 ) dp[b][c] = 0;
                else dp[b][c] = 2;
            }
        }
        cin >> P >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lf", &Mj, &Pj);
            for (c = 1; c < SIZE; c++)
            {
                //if ( c-Mj < 0 || dp[b-1][c-Mj]>=2 ) continue;
                dp[b][c] = min(recF(b-1, c), recF(b-1, c-Mj)+Pj - recF(b-1,c-Mj)*Pj );
            }
        }
        ans = 0;
        for (b = 0; b < 5; b++)
        {
            for (c = 0; c < 10; c++)
            {
                //cout << dp[b][c] << " ";
            }
            //cout << endl;
        }
        //cout << "N = " << N << endl;
        for (b = 10000; b >= 0; b--)
        {
            if ( dp[N][b] < P )
            {
                ans = b;
                break;
            }
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
