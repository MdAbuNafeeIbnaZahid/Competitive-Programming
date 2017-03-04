#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
int T, V, N;
int i, j, k, m, x, y, z, a, b, Ci, s;
vector<int> C;
int dp[59][SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        memset(dp, -1, sizeof(dp));
        C = vector<int>();
        //cin >> V >> N;
        scanf("%d %d", &V, &N);
        for (j = 1; j <= N; j++)
        {
            //cin >> Ci;
            scanf("%d", &Ci);
            C.push_back(Ci);
        }
        sort(C.begin(), C.end());
        s = C.size();
        for (m = 0; m*C[s-1] < SIZE; m++)
        {
            dp[s-1][ m*C[s-1] ] = m;
        }
        for (k = s-2; k >= 0; k--)
        {
            for (m = 0; m < V+1; m++)
            {
                if ( dp[k+1][m]!=-1 )
                {
                    for (x = 1; m+x*C[k] < V+1; x++)
                    {
                        if ( dp[k+1][m+x*C[k]]==-1 ) dp[k][m+x*C[k]]=dp[k+1][m]+x;
                        else dp[k][m+x*C[k]] = min(dp[k+1][m+x*C[k]] ,dp[k+1][m]+x);
                    }
                }
            }
        }
        cout << dp[0][V] << endl;
    }
    return 0;
}
