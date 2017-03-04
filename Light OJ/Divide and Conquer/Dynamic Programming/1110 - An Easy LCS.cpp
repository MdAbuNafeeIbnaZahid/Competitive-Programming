#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T;
string dp[SIZE][SIZE];
char s1[SIZE], s2[SIZE];
string whichStr(string a, string b)
{
    if ( a.size() > b.size() ) return a;
    else if ( b.size() > a.size() ) return b;
    return min(a, b);
}
void solve()
{
    long long a, b, c, d, e, f;
    long long len1 = strlen(s1+1), len2 = strlen(s2+1);
    for ( a = 1; a <= len1; a++ )
    {
        for ( b = 1; b <= len2; b++ )
        {
            dp[a][b] = "";
            if ( s1[a] == s2[b] )
            {
//                cout << "a = " << a << ", b = " << b << endl;
                dp[a][b] = dp[a-1][b-1] + s1[a];
            }
//            else if ( dp[a-1][b].size() > dp[a][b-1].size() ||
//                  (dp[a-1][b].size() == dp[a][b-1].size() &&
//                  dp[a-1][b] < dp[a][b-1])  )
//                  {
//                    dp[a][b] =
//                  }
            else
            {
                dp[a][b] = whichStr(dp[a-1][b], dp[a][b-1]);
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> T;
    for ( a = 1; a <= T; a++ )
    {
        scanf("%s", s1+1);
//        cout << s1+1 << endl;
        scanf("%s", s2+1);
//        cout << s2+1 << endl;
        solve();
        long long len1 = strlen(s1+1);
        long long len2 = strlen(s2+1);
        string ans = dp[ len1 ][ len2 ];
        if ( ans == "" )
        {
            ans = ":(";
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
