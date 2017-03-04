#include <bits/stdc++.h>
using namespace std;
long long twoPow16 = (1<<16);
long long T, base, k;
long long len, dp[(1<<17)][20], powAr[29], charToNumAr[29];
char str[29];
long long charToNum(char ch)
{
    long long ret = ch>='0'&&ch<='9' ? ch-'0' : ch-'A'+10;
    return ret;
}
void myClear()
{
    long long a, b, c,  d, e;
    for ( a = 0; a < ( 1 << len ); a++ )
    {
        //memset( dp[a], 0, sizeof( dp[a] ) );
        for ( b = 0; b < k; b++ )
        {
            dp[a][b] = 0;
        }
    }
    for ( a = 0; a < ( 1 << len ); a++ )
    {
        //memset( dp[a], 0, sizeof( dp[a] ) );
        for ( b = 0; b < k; b++ )
        {
            if ( dp[a][b] )
            {
                cout << "Not ok" << endl;
                return;
            }
        }
    }
    dp[0][0] = 1;
}
vector<long long> numVec[29];
void buildNumVec()
{
    long long a, b, c, d,e;
    for ( a = 0; a <= 19; a++ )
    {
        numVec[a] = vector<long long>();
    }
    for ( a = 0; a <= (1<<len); a++ )
    {
//        cout << "a = " << a << endl;
        numVec[ __builtin_popcount( a ) ].push_back( a );
    }
}
void solve()
{
    long long a, b, c, d, e, curNum, modVal, nextNum;
    for ( a = 0; a <= len; a++ )
    {
        for ( b = 0; b < numVec[a].size(); b++ )
        {
            curNum = numVec[a][b];
            for ( c = 0;  c < len; c++ )
            {
                if ( (curNum>>c) & 1 )
                {
                    continue;
                }
                modVal = ( (powAr[ a ]%k) * ( charToNumAr[ c ] %k ) ) % k;
                nextNum = curNum | (1<<c);
                for ( d = 0; d < k; d++ )
                {
                    dp[nextNum][ (d + modVal)%k ] += dp[curNum][ d ];
                }
            }
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;

    cin >> T;
//    cout << "T = " << T << endl;
    for ( a = 1; a <= T; a++ )
    {
        //memset(dp, -1, sizeof(dp) );
//        cout << "a = " << a << endl;
        scanf("%lld %lld", &base, &k);
        scanf("%s", str);
        len = strlen( str );
        buildNumVec();
        for ( b = 0; b < len; b++ )
        {
            charToNumAr[b] = charToNum( str[b] );
        }
        powAr[0] = 1%k;
        for ( b = 1; b < 19; b++ )
        {
            powAr[b] = ( (powAr[b-1]%k) * ( base%k ) ) % k;
        }
        //memset(dp, 0, sizeof() );
        myClear();
//        cout << "cleared " << endl;
        solve();
        long long ans = dp[ (1<<len)-1 ][ 0 ];
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
