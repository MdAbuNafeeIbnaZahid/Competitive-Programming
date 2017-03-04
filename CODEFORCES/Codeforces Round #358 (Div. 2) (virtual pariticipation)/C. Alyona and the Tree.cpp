#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
#define WHITE 0
#define GREY 1
#define BLACK 2
long long n, a[SIZE], p[SIZE], c[SIZE], ans;
long long i, j, k, d, e, f, color[SIZE], maxDist[SIZE], len, subTreeSize[SIZE];
vector<long long> topSorted, gr[SIZE];
void dfs1(long long u)
{
    if (color[u] != WHITE) return;
    color[u] = GREY;
    dfs1( p[u] );
    color[u] = BLACK;
    topSorted.push_back(u);
}
long long dfs2(long long u)
{
    long long len, a, b, c, d, addee, ret = 0;
    len = gr[u].size();
    for (a = 0; a < len; a++)
    {
        ret += dfs2( gr[u][a] );
    }
    subTreeSize[u] = ret+1;
    return subTreeSize[u];
}
long long dfs3(long long u)
{
    long long b, c, d, len = gr[u].size(), ret = 0;
    if ( maxDist[u] > a[u] ) return subTreeSize[u];
    for ( b = 0; b < len; b++ )
    {
        ret += dfs3( gr[u][b] );
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (i = 2; i <= n; i++)
    {
        scanf("%lld %lld", &p[i], &c[i]);
        gr[ p[i] ].push_back( i );
    }
    for (i = n; i >= 1; i--)
    {
        dfs1(i);
    }
    len = topSorted.size();
    for (i = 1; i <= n; i++) maxDist[i] = INT_MIN;
    maxDist[1] = 0;
    for (i = 1; i < len; i++)
    {
        maxDist[ topSorted[i] ] = max( c[ topSorted[i] ],
                                      maxDist[ p[ topSorted[i] ] ] + c[ topSorted[i] ] );
    }
    memset(color, 0, sizeof(color));
    dfs2(1);
    ans = dfs3(1);
    cout << ans << endl;
    return 0;
}
