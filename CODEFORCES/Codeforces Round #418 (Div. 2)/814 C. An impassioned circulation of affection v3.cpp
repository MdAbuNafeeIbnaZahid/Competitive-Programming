#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
#define SIZE 1509
long long n, q, mi;
char gar[SIZE], ci;
//            whichChar colUsed idxUpto
long long dp[SIZE][SIZE], ansDp[SIZE][SIZE];

long long savedAns[SIZE][SIZE];

void saveAns(char ch)
{
    long long a, b, c, d, e;
    for ( a = 0; a < SIZE; a++ )
    {
        savedAns[a][ ch ] = ansDp[ a ][ n ];
    }
}

void calcDp(char ch)
{
    memset(dp, 0, sizeof(dp));
    memset(ansDp, 0, sizeof(ansDp));
    long long whichChar = 2;
    long long a, b, c, d, e;
    for ( a = 0; a <= n; a++ )
    {
        dp[ a ][ 0 ] = 0;
    }
    for ( a = 1; a <= n; a++ )
    {
        if ( gar[a] == ch )
        {
            dp[0][ a ] = dp[0][ a-1 ] + 1;
        }
        else
        {
            dp[0][ a ] = 0;
        }
        ansDp[a][b] = max(ansDp[a][b], dp[a][b]);
    }
    for (a = 1; a <= n; a++)
    {
        // a=  col used
        for (b = 1; b <= n; b++)
        {
            // b= idx upto
            if ( gar[b] == ch )
            {
                dp[a][b] = dp[a][b-1] + 1;
            }
            else
            {
                dp[a][b] = dp[a-1][b-1] + 1;
            }
        }
    }
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= n; b++)
        {
            ansDp[a][b] = max(ansDp[a][b], dp[a][b]);
            ansDp[a][b] = max(ansDp[a][b], ansDp[a-1][b-1]);
            ansDp[a][b] = max(ansDp[a][b], ansDp[a][b-1]);
            ansDp[a][b] = max(ansDp[a][b], ansDp[a-1][b]);
        }
    }
}
long long charCnt[SIZE][SIZE];
long long ansCnt[SIZE][SIZE];

void calcAns(char ch)
{
    long long a, b, c, d, e, f, colNeed;
    for (a = 1; a <= n; a++)
    {
        for (b = a; b <= n ; b++)
        {
            colNeed = (b-a+1) - ( charCnt[b][ch] - charCnt[a-1][ch] );
            ansCnt[ colNeed ][ ch ] = max( ansCnt[colNeed][ ch ], b-a+1 );
        }
    }
    for (a = 1;  a <= n; a++)
    {
        ansCnt[ a ][ ch ] = max( ansCnt[a][ch], ansCnt[a-1][ch] );
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e ;
    cin >> n;
    scanf("%s", gar+1);
    for (a = 1; a <= n; a++)
    {
        for (b = 'a'; b <= 'z'; b++)
        {
            charCnt[a][b] = charCnt[a-1][b];
        }
        charCnt[a][ gar[a] ]++;
    }


    char ch;
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        calcAns(ch);
    }
    cin >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld %c", &mi, &ci);
        long long ans = ansCnt[mi][ci];
        printf("%lld\n", ans);
    }
    return 0;
}
