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
#define SIZE 109
long long n, crushAr[SIZE];
long long a, b, c, d, e, f, g, nodeCount, ifVisited[SIZE], ans = 1;
vector<long long> backCrush[SIZE];
long long hcf(long long u, long long v)
{
    if ( u > v )
    {
        swap(u, v);
    }
    if (u==0)
    {
        return v;
    }
    return hcf(v%u, u);
}
long long lcm(long long u, long long v)
{
    return (u*v)/hcf(u,v);
}
void dfs(long long u)
{
    if ( ifVisited[u] )
    {
        return;
    }
    ifVisited[u] = 1;
    nodeCount++;
    dfs( crushAr[u] );
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
//    cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        cin >> crushAr[a];
        backCrush[ crushAr[a] ].push_back( a );
    }
//    cout << "input taken" << endl;
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        if ( backCrush[a].size() != 1 )
        {
            cout << -1;
            return 0;
        }
    }
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        if ( backCrush[a].size() != 1 )
        {
            cout << -1;
            return 0;
        }
        memset(ifVisited, 0, sizeof(ifVisited) );
        dfs(a);
        if ( ifVisited[ backCrush[a][0] ] == 0 )
        {
            cout << -1;
            return 0;
        }
    }
    for (a = 1; a <= n; a++)
    {
        memset(ifVisited, 0, sizeof(ifVisited) );
        nodeCount = 0;
        dfs(a);
        if ( nodeCount%2 )
        {
            ans = lcm(ans, nodeCount);
        }
        else
        {
            ans = lcm(ans, nodeCount/2);
        }
    }
    cout << ans;
    return 0;
}
