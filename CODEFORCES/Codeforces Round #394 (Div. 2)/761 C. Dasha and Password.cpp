#include <bits/stdc++.h>
using namespace std;
#define SIZE 59
#define DIG 0
#define LET 1
#define SPE 2
long long n, m;
char strAr[SIZE][SIZE];
long long dp[SIZE][SIZE];
void dis(long long &dig, long long &let, long long &spe, char *str)
{
    long long a, b, c, d, e, len = strlen(str);
    let = spe = dig = INT_MAX;
    for ( a = 0; a < len; a++ )
    {
        if ( str[a] >= '0' && str[a] <= '9' )
        {
            dig = min(dig, min(a, len-a) );
        }
        else if ( str[a] >= 'a' && str[a] <= 'z' )
        {
            let = min(let, min(a, len-a) );
        }
        else
        {
            spe = min( spe, min(a, len-a) );
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    long long a, b, c, d,e , f;
    for ( a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            dp[a][b] = INT_MAX;
        }
    }
    dp[0][0] = 0;
    cin >> n >> m;
    for ( a = 1; a <= n; a++ )
    {
        scanf("%s", strAr[a]);
    }
    for ( a = 1; a <= n; a++ )
    {
        long long let, dig, spe;
        dis(dig, let, spe, strAr[a]);
        for ( b = 0; b < 8; b++ )
        {
            dp[a][b] = dp[a-1][b];
            //dp[a][ b | (1<<DIG) ] = dp[a-1][b] + dig;
        }
        for ( b = 0; b < 8; b++ )
        {
            //dp[a][b] = dp[a-1][b];
            dp[a][ b | (1<<DIG) ] = min(dp[a-1][b] + dig, dp[a][ b | (1<<DIG) ]);
            dp[a][ b | (1<<LET) ] = min(dp[a-1][b] + let, dp[a][ b | (1<<LET) ]);
            dp[a][ b | (1<<SPE) ] = min(dp[a-1][b] + spe, dp[a][ b | (1<<SPE) ]);
        }
    }
    cout << dp[n][7] << endl;
    return 0;
}
