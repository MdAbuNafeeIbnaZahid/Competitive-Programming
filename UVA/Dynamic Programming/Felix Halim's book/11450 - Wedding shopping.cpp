#include <bits/stdc++.h>
using namespace std;
#define  SIZE 209
long long N, M, C, K, x;
long long a,b, d, e, f, g, len;
long long dp[SIZE][SIZE];
vector<long long> input[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        memset(dp, 0, sizeof(dp));
        cin >> M >> C;
        for(b = 1; b <= C; b++)
        {
            input[b] = vector<long long>();
        }
        for (b = 1; b <= C; b++)
        {
            scanf("%lld",&K);
            for (d = 1; d <= K; d++)
            {
                scanf("%lld", &x);
                input[b].push_back(x);
            }
        }
        dp[0][0] = 1;
        for (b = 0; b <= C-1; b++)
        {
            for (d = 0; d < M; d++)
            {
                if ( dp[b][d] )
                {
                    len = input[b+1].size();
                    for (e = 0; e < len; e++)
                    {
                        if ( d+input[b+1][e] <= M ) dp[b+1][ d+input[b+1][e] ] = 1;
                    }
                }
            }
        }
        for (b = M; b >= 0; b-- ) if ( dp[C][b] ) break;
        if ( b==-1 ) cout << "no solution" << endl;
        else cout << b << endl;
    }
    return 0;
}
