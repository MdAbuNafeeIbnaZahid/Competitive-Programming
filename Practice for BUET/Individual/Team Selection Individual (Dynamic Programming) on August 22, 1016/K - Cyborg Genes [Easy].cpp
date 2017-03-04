#include <bits/stdc++.h>
using namespace std;
#define SIZE 39
long long T, lcs[SIZE][SIZE], dp[SIZE][SIZE], len1, len2;
long long a, b, c, d, e, f, g, h, x;
string str1, str2;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    getchar();
    for (a = 1; a <= T; a++)
    {
        memset(lcs, 0, sizeof(lcs) );
        memset(dp, 0, sizeof(dp) );
        //cin >> str1 >> str2;
        getline(cin, str1);
        getline(cin, str2);
        //cout << str1 << " " << str2 << endl;
        len1 = str1.size();
        len2 = str2.size();
        for (b = 0; b  < SIZE; b++)
        {
            lcs[b][0] = b;
            lcs[0][b] = b;
        }
        //for (b = 0; b )
        for (b = 1; b <= len1; b++)
        {
            for (c = 1; c <= len2; c++)
            {
                if ( str1[b-1] == str2[c-1] ) lcs[b][c] = 1+lcs[b-1][c-1];
                else
                {
                    lcs[b][c] = 1+( min(lcs[b-1][c], lcs[b][c-1]) );
                }
            }
        }
        for (b = 0; b  < SIZE; b++)
        {
            dp[b][0] = 1;
            dp[0][b] = 1;
        }
        for (b = 1; b <= len1; b++)
        {
            for (c = 1; c <= len2; c++)
            {
                if ( str1[b-1] == str2[c-1] ) dp[b][c] = dp[b-1][c-1];
                else if ( lcs[b-1][c] == lcs[b][c-1] )
                {
                    dp[b][c] = dp[b-1][c] + dp[b][c-1];
                }
                else if( lcs[b-1][c] < lcs[b][c-1] ) dp[b][c] = dp[b-1][c];
                else if (lcs[b][c-1] < lcs[b-1][c] ) dp[b][c] = dp[b][c-1];
            }
        }
        cout << "Case #" << a << ": " << lcs[len1][len2] << " " << dp[len1][len2] ;
        //if (a<T)
            cout << endl;
    }
    return 0;
}
