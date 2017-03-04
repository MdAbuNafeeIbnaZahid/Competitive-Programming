#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, N, amGold[SIZE],  rem;
long long a, b, c,  d, e;
double dp[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &amGold[b]);
            dp[b] = amGold[b];
        }
        dp[N] = amGold[N];
        for (b = N-1; b>= 1; b--)
        {
            rem = N-b;
            for (c = 1; c <= min(rem, (long long)6) ; c++)
            {
                dp[b] += ((double)dp[b+c]/min(rem, (long long)6));
            }
        }
        //cout << "Case " << a << ": " << dp[1] << endl;
        printf("Case %lld: %0.8lf\n", a, dp[1]);
    }
    return 0;
}
