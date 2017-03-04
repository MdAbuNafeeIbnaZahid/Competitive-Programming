#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long dp[SIZE][SIZE];
string s, t, lcsString, modifiedS, modifiedT;
long long n, m, k;
long long a, b, c, d, e, f, g, maxB, maxC, currentB, currentC, ans, ansDp[SIZE][SIZE][13];
long long lenS, lenT;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    cin >> s >> t;

    // in dp array we are simply calculating the largest common substring
    memset(dp, 0, sizeof(dp));
    for (b = 1; b <= n; b++)
    {
        for (c = 1; c <= m; c++)
        {
            if ( s[b-1] == t[c-1] )
            {
                dp[b][c] = dp[b-1][c-1]+1;
            }
            else dp[b][c] = 0;
        }
    }
    // largest common substring is processed


    // now let's process the answer
    // it's something like 0-1 knapsack
    // we can take maximum k matched substring
    // ansDp[b][c][a] stands for maximum ans considerings
    //the string s[1...b]
    //the string t[1...c]
    // taking maximum k matches
    // base case : when k == 0
    // dp[b][c][k] = 0
    for (a = 1; a <= k; a++)
    {
        for (b = 1; b <= n; b++)
        {
            for (c = 1; c <= m; c++)
            {
                ansDp[b][c][a] = max( max( ansDp[b][c][a-1],  ansDp[b-dp[b][c] ][c-dp[b][c] ][a-1] + dp[b][c] ),
                                max(ansDp[b][c-1][a], ansDp[b-1][c][a] ) ) ;
            }
        }
    }
    cout << ansDp[n][m][k] << endl;
    return 0;
}
