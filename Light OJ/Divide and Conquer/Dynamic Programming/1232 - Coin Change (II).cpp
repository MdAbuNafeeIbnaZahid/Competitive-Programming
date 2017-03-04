#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007
int T, n, K, A[105], C[105];
int i, j, k, x, y, z, idx;
int dp[105][3];
int main()
{
    freopen( "input.txt", "r", stdin );
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> n >> K;
        for (j = 0; j < 3; j++)
            for (x = 0; x <= K; x++) dp[j][x] = 0;

        for (j = 1; j <= n; j++) cin >> A[j];
        //for (j = 1; j <= n; j++)  C[j] = K;
        for (j = 0; j <=K; j+=A[1]) dp[1][j] = 1;

        for (x = 0; x <= K; x++) cout << dp[1%2][x] << " ";
        cout << "\n";
        for (j = 2; j <= n; j++)
        {
            cout << "\n" << j%2 << "\n";
            for (x = 0; x <= K; x++)
            {
                for (y = 0;  y <= K; y+=A[j])
                {
                    idx = x - y;
                    if (idx >= 0) dp[j%2][x] = (dp[j%2][x]%MOD + dp[(j-1)%2][idx]%MOD)%MOD;
                    //cout << dp[j%2][x] << " ";
                }
                cout << dp[j%2][x] << " ";
            }
            cout << "\n";
        }
        cout << "Case " << i << ": " << dp[n%2][K] << "\n";
    }
    return 0;
}
