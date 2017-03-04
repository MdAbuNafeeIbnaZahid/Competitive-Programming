#include <bits/stdc++.h>
using namespace std;
#define SIZE (1<<19)
long long T, N;
long long helAr[SIZE];
char grid[19][19];
vector<long long> bitNum[SIZE];
long long dp[SIZE];
void handle(long long num)
{
//    cout << "num = " << num << endl;
    long long a, b, c, d, e;
    vector<long long> one, zero;
    for ( a = 0; a < N; a++ )
    {
        if ( (num>>a) & 1 )
        {
            one.push_back( a );
//            cout << "one = " << a << endl;
        }
        else
        {
            zero.push_back( a );
//            cout << "zero = " << a << endl;
        }
    }
//    cout << "dp[num] = " << dp[num] << endl;
    for ( a = 0; a < zero.size(); a++ )
    {
        long long bestShot = 1;
        for ( b =  0; b < one.size(); b++ )
        {
            bestShot = max(bestShot, (long long) (grid[ one[b] ][ zero[a] ] - '0') );
        }
        long long nextNum = num | (1<<zero[a]);
        long long shotNeeded = ceil( (helAr[ zero[a] ]*1.0)/bestShot );
        dp[ nextNum ] = min(dp[num]+shotNeeded,
                                    dp[ nextNum ]);
    }
//    cout << endl;
}
void solve()
{
    long long a, b, c, d, e;
    for ( a = 0; a < (1<<N)+9; a++ )
    {
        dp[a] = INT_MAX;
    }
    dp[0] = 0;
    for ( b = 0; b < N; b++ )
    {
        long long cur;
        for (c = 0; c < bitNum[b].size(); c++)
        {
            cur = bitNum[b][c];
            handle(cur);
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c,d , e;
    cin >> T;
    for ( a =1; a <= T; a++ )
    {
        cin >> N;
        for ( b = 0; b < N; b++ )
        {
            scanf("%lld", &helAr[b]);
        }
        for ( b = 0; b < N; b++ )
        {
            scanf("%s", grid[b]);
        }
        for ( b = 0; b <= N; b++ )
        {
            bitNum[b] = vector<long long>();
        }
        for ( b = 0; b < (1<<N); b++ )
        {
            bitNum[ __builtin_popcount(b) ].push_back( b );
        }
//        for ( b = 0; b <= N; b++ )
//        {
//            cout << "b = " << b << endl;
//            for (c = 0; c< bitNum[b].size(); c++)
//            {
//                cout << bitNum[b][c] << " ";
//            }
//            cout << endl;
//        }
        solve();
        long long ans = dp[ (1<<N)-1 ];
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
