#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long dp[SIZE][SIZE][SIZE], cAr[SIZE], pAr[SIZE][SIZE], ans;
long long minVal[SIZE][SIZE][9], minIdx[SIZE][SIZE][9];
long long n, m, k;
long long a, b, c, d, e, f, g, h;
const long long myMAX =  ((long long) 1 )<< 53;
int main()
{
//    freopen("input.txt", "r", stdin);
    //cout << myMAX << endl;

    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            for (c = 0; c < SIZE; c++)
            {
                dp[a][b][c] = myMAX;
                //if (a==0 && b==0) dp[a][b][c] = 0;
            }
            for (c = 0; c < 9; c++)
            {
                //minVal[a][b][c] = myMAX;
                minIdx[a][b][c] = 0;
            }
        }
    }
    cin >> n >> m >> k;
//    cout << "n = " << n << ", m = " << m << ", k = " << k << endl;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &cAr[a]);
    }
//    cout << "cAr" << endl;
//    for (a = 1; a<= n; a++)
//    {
//        cout << cAr[a] << " ";
//    }
//    cout << endl;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            scanf("%lld", &pAr[a][b]);
            if ( cAr[a] )
            {
                if (b == cAr[a] ) pAr[a][b] = 0;
                else pAr[a][b] = myMAX;
            }
        }
    }

//    for (a = 1; a <= n; a++)
//    {
//        for (b = 1; b <= m; b++)
//        {
//            cout << pAr[a][b] << " ";
//        }
//        cout << endl;
//    }
    for (c = 1; c <= m; c++)
    {
        dp[1][1][c] = pAr[1][c];
    }
    for (a = 2; a <= n; a++) // tree upto
    {
        for (b = 1; b <= k; b++) // partition
        {
            for (c = 1; c <= m; c++)
            {
                if ( dp[a-1][b-1][c] < dp[a-1][b-1][ minIdx[a-1][b-1][1] ] )
                {
                    minIdx[a-1][b-1][2] = minIdx[a-1][b-1][1];
                    minIdx[a-1][b-1][1] = c;
                }
                else if ( dp[a-1][b-1][c] < dp[a-1][b-1][ minIdx[a-1][b-1][2] ] )
                {
                    minIdx[a-1][b-1][2] = c;
                }
            }
//            cout << "a-1 = " << a-1 << ", b-1 = " << b-1 << ", minIdx = " << minIdx[a-1][b-1][1];
//            cout << ", " << minIdx[a-1][b-1][2] << endl;

            for (c = 1; c <= m; c++) // color
            {
                dp[a][b][c] = min(dp[a][b][c], dp[a-1][b][c]+pAr[a][c]);
                if ( minIdx[a-1][b-1][1] == c )
                {
                    dp[a][b][c] = min(dp[a][b][c], dp[a-1][b-1][ minIdx[a-1][b-1][2] ]+pAr[a][c]);
                }
                else
                {
                    dp[a][b][c] = min(dp[a][b][c], dp[a-1][b-1][ minIdx[a-1][b-1][1] ]+pAr[a][c]);
                }

//                for (d = 1; d <= m; d++)
//                {
//                    if ( d == c ) continue;
//                    dp[a][b][c] = min(dp[a][b][c], dp[a-1][b-1][d]+ pAr[a][c]);
//                }
//                cout << "a = " << a << ", b = " << b << ", c = " << c << ", dp = ";
//                cout << dp[a][b][c] << endl;
            }

        }
    }
    ans = 4*myMAX;
    for (a = 1; a <= m; a++)
    {
        ans = min(ans, dp[n][k][a]);
    }
    if (ans >= myMAX/2) cout  << -1;
    else cout << ans ;
    return 0;
}
