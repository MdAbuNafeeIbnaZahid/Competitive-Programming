#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
int dp[10][1000], input[10], value[] = {0, 1, 2, 4, 10, 20, 40};
int i, j, k, m, n, w, x, y, z, ans;
int getNeeded(int row, int column)
{
    if (row < 1 || row > 6 || column < 0 || column > 298) return INF;
    return dp[row][column];
}
int myMin(int a, int b, int c)
{
    return (a<b? (a<c?a:c) : (b<c?b:c) );
}
double trans;
int amount;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(true)
    {
        //memset(dp, -1, sizeof(dp));
        for (i = 0; i < 10; i++)
            for (j = 0; j < 1000; j++) dp[i][j] = INF;
        //for (i = 1; i <= 6; i++)
        //{
            //for (j = 0; j <= 21; j++) cout << dp[i][j] << " ";
            //cout << endl;
        //}
        for (i = 1; i <= 6; i++) cin >> input[i];
        for (i = 1; i <= 6; i++) if (input[i] != 0) break;
        if (i > 6) return 0;
        //cout << endl;
        cin >> trans;
        amount = round(trans / .05);
        //cout << "amount = " << amount << endl;
        for (i = 1; i <= 6; i++) dp[i][500] = 0;
        for (j = 1; j <= input[1]; j++)
        {
            dp[1][ 500 + j*value[1] ]  =  j;
        }
        for (j = 1; ; j++)
        {
            if (500 -j*value[1] < 0) break;
            dp[1][500 -j*value[1] ] = j;
        }
        for (i = 2; i <= 6; i++)
        {
            for (j = 0; j < 600; j++)
            {
                for (k = 0; k <= input[i]; k++)
                {
                    if ( j+k*value[i] < 600 )
                    {
                        dp[i][j+k*value[i]] = myMin( dp[i][j+k*value[i]], dp[i-1][j]+k, dp[i-1][j+k*value[i]] );
                    }
                    //if ( j-k*value[i] >= 0 )
                    //{
                        //if ( dp[i][j-k*value[i]] == -1 ) dp[i][j-k*value[i]] = INF;
                        //dp[i][j-k*value[i]] = myMin( dp[i][j-k*value[i]], dp[i-1][j]+k, dp[i-1][j-k*value[i]] );
                    //}
                }
                for (k = 0; ; k++)
                {
                    if ( j-k*value[i] >= 0 )
                    {
                        //if ( dp[i][j-k*value[i]] == -1 ) dp[i][j-k*value[i]] = INF;
                        dp[i][j-k*value[i]] = myMin( dp[i][j-k*value[i]], dp[i-1][j]+k, dp[i-1][j-k*value[i]] );
                    }
                    else break;
                }
            }
        }
        for (i = 1; i <= 6; i++)
        {
            //for (j = 0; j <= 21; j++) cout << dp[i][j] << " ";
            //cout << endl;
        }
        ans = dp[6][amount+500];
        //for (j = amo; j <= 220-amount; j+=2) ans = min(ans, dp[1][j + amount ] );
        cout.width(3);
        cout << ans << endl ;
    }
    return 0;
}
