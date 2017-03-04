#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long dp[SIZE][SIZE];
long long T, len;
long long a, b, c, d, e, f;
string str;
long long recDp(long long i, long long j)
{
    long long a, b, c, d, ret = INT_MAX;
    if ( i >= j ) return 0;
    if (i < 0 || i >= len || j < 0 || j >= len) return 0;
    if ( dp[i][j] != -1 ) return dp[i][j];
    if ( str[i] == str[j] ) return recDp(i+1, j-1);
    else
    {
        ret = min(ret, recDp(i+1, j-1)+2);
        ret = min(ret, recDp(i+1, j)+1);
        ret = min(ret, recDp(i, j-1)+1);
        dp[i][j] = ret;
        return ret;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(dp, -1, sizeof(dp));
        cin >> str;
        len = str.size();
        for (b = 1; b < len; b++)
        {
            for (c = 0; c < len; c++)
            {
                if( c+b >= len ) break;
                dp[c][c+b] = recDp(c, c+b);
            }
        }
        cout << "Case " << a << ": " << recDp(0, len-1) << endl;
    }
    return 0;
}
