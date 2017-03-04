#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, cAr[SIZE], ansAr[3][SIZE];
long long a, b, c, d, e, f, g;
string s[SIZE], sRev[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &cAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        cin >> s[a];
        sRev[a] = s[a];
        reverse( sRev[a].begin(), sRev[a].end() );
    }
    memset(ansAr, -1, sizeof(ansAr));
    for (a = 0; a < SIZE; a++)
    {
        ansAr[0][a] = ansAr[1][a] = ansAr[2][a] = ( (long long) 1<<55) ;
    }
    //cout << ansAr[0][1] << endl;
    ansAr[0][1] = 0;
    ansAr[1][1] = cAr[1];
    for (a = 2; a <= n; a++)
    {
        if ( s[a] >= s[a-1] )
        {
            ansAr[0][a] = min( ansAr[0][a], ansAr[0][a-1]);
        }
        if ( s[a] >= sRev[a-1] )
        {
            ansAr[0][a] = min ( ansAr[0][a], ansAr[1][a-1] );
        }
        if ( sRev[a] >= s[a-1] )
        {
            ansAr[1][a] = min( ansAr[1][a],  ansAr[0][a-1] + cAr[a] ) ;
        }
        if ( sRev[a] >= sRev[a-1] )
        {
            ansAr[1][a] = min( ansAr[1][a], ansAr[1][a-1] + cAr[a] );
        }
    }
    if ( min(ansAr[0][n], ansAr[1][n]) >= ( (long long) 1<<54) ) cout << -1;
    else cout << min(ansAr[0][n], ansAr[1][n]);
    return 0;
}

