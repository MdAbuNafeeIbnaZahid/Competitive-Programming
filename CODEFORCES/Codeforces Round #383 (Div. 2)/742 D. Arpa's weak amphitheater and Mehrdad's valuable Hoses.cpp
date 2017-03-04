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
#define SIZE 1009
long long n, m, w, xi, yi, ans;
long long wAr[SIZE], bAr[SIZE];
long long wSum[SIZE], bSum[SIZE], dp[SIZE][SIZE], whichCompo[SIZE];
long long a, b, c, d, e, f, g, h;
vector<long long> gr[SIZE], compoNodes[SIZE];
void dfsDecompo(long long u, long long compoIdx)
{
    long long a, b, c,d, e, f;
    if ( whichCompo[u] )
    {
        return;
    }
    whichCompo[u] = compoIdx;
    bSum[compoIdx] += bAr[u];
    wSum[compoIdx] += wAr[u];
    compoNodes[compoIdx].push_back( u );
    for (a = 0; a < gr[u].size(); a++)
    {
        dfsDecompo( gr[u][a], compoIdx );
    }
}
long long valDp(long long compoUpto, long long weightUpto)
{
    if ( compoUpto < 0 || weightUpto < 0 ) return INT_MIN;
    else return dp[compoUpto][weightUpto];
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> w;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &wAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &bAr[a]);
    }
    for (a = 1; a <=m; a++)
    {
        scanf("%lld %lld", &xi, &yi);
        gr[xi].push_back(yi);
        gr[yi].push_back(xi);
    }
    for (a = 1; a <= n; a++)
    {
        dfsDecompo(a, a);
    }
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << ", wSum[a] = " << wSum[a] << endl;
//        cout << "composize = " << compoNodes[a].size() << endl;
    }
    for (a = 1; a <= n; a++)
    {

        for ( b = 1; b <= w; b++ )
        {
            dp[a][b] = max(dp[a-1][b], dp[a][b]);
            dp[a][b] = max(dp[a][b-1], dp[a][b]);
            dp[a][b] = max(dp[a-1][b], dp[a][b]);
            dp[a][b] = max(valDp(a-1, b-wSum[a]) + bSum[a], dp[a][b] );
        }
        for (c = 0; c < compoNodes[a].size(); c++)
        {
            for ( b = 1; b <= w; b++ )
            {
                dp[a][b] = max(dp[a-1][b], dp[a][b]);
                dp[a][b] = max(dp[a][b-1], dp[a][b]);
                dp[a][b] = max(dp[a-1][b], dp[a][b]);
                dp[a][b] = max(valDp(a-1, b-wAr[ compoNodes[a][c] ]) + bAr[ compoNodes[a][c] ], dp[a][b] );
            }
        }
//        cout << "a = " << a << endl;
//        for (b = 0; b <= w; b++)
//        {
//            cout << dp[a][b] << " ";
//        }
//        cout << endl;
    }
    ans = dp[n][w];
    cout << ans ;
    return 0;
}

