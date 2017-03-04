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
#define SIZE 200009
long long n, ai[SIZE], ui, vi;
vector<long long> gr[SIZE];
long long plSum[SIZE], maxPl[SIZE], vis[SIZE];
long long a, b, c, d, e, f, g, h, ans = -(1LL<<60);
struct max2
{
    long long big, small;
    max2()
    {
        big = -(1LL<<60);
        small = -(1LL<<60);
    }
    long long getSum()
    {
        return big+small;
    }
    void add(long long num)
    {
        if ( num > big )
        {
            small = big;
            big = num;
        }
        else if ( num > small )
        {
            small = num;
        }
    }
};
void dfsPlSum(long long u)
{
    long long a, b, c, d, e, f, g, h;
    if ( vis[u] )
    {
        return;
    }
    vis[u] = 1;
    plSum[u] = ai[u];
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( vis[ gr[u][a] ] )
        {
            continue;
        }
        dfsPlSum( gr[u][a] );
        plSum[u] += plSum[ gr[u][a] ];
    }
}
void dfsMaxPl(long long u)
{
    long long a, b, c, d, e, f, g, h;
    if ( vis[u] )
    {
        return;
    }
    vis[u] = 1;
    maxPl[u] = plSum[u];
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( vis[ gr[u][a] ] )
        {
            continue;
        }
        dfsMaxPl( gr[u][a] );
        maxPl[u] = max( maxPl[u], maxPl[ gr[u][a] ] );
    }
}
void dfsAns(long long u)
{
    long long a, b, c, d, e, f, g, h;
    if ( vis[u] )
    {
        return;
    }
//    cout << "inside dfsAns u = " << u << endl;
    vis[u] = 1;
    max2 m;
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( vis[ gr[u][a] ] )
        {
            continue;
        }
        dfsAns( gr[u][a] );
        m.add( maxPl[ gr[u][a] ] );
    }
    ans = max(ans, m.getSum() );
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    cout << ans << endl;
    for (a = 0; a < SIZE; a++)
    {
        maxPl[a] = INT_MIN;
    }
    cin >> n;
//    cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ai[a]);
    }
//    for (a = 1; a <= n; a++)
//    {
//        cout << "a = " << a << " ai = " << ai[a] << endl;
//    }
    for (a = 1; a < n; a++)
    {
        scanf("%lld %lld", &ui, &vi);
        gr[ui].push_back(vi);
        gr[vi].push_back(ui);
    }
    dfsPlSum(1);
//    for (a = 1; a <= n; a++)
//    {
//        cout << "a = " << a << ", plSum = " << plSum[a] << endl;
//    }
    memset(vis, 0, sizeof(vis) );
    dfsMaxPl(1);
//    for (a = 1; a <= n; a++)
//    {
//        cout << "a = " << a << ", maxPl = " << maxPl[a] << endl;
//    }
    memset(vis, 0, sizeof(vis) );
    dfsAns(1);
//    for (a = 1; a <= n; a++)
//    {
//        max2 m;
//        for (b = 0; b < gr[a].size(); b++)
//        {
//            m.add( maxPl[gr[a][b] ] );
//        }
//        ans = max(ans, m.getSum());
//    }
    if ( ans < -(1LL<<57) )
    {
        cout << "Impossible";
    }
    else
    {
        cout << ans;
    }
    return 0;
}

