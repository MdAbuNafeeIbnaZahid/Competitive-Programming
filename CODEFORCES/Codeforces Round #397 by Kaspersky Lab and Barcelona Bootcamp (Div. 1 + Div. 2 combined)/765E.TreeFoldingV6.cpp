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
long long n, u, v, ans = INT_MAX;
long long posAns;
set<long long > gr[SIZE], dis[SIZE];
void bfs()
{
    long long a, b, c, d, e, f, cur, nex;
    queue<long long> Q;
    for ( a = 1; a <= n; a++)
    {
        if ( gr[a].size() == 1 )
        {
//            cout << " leaf node " << a << endl;
            Q.push(a);
            dis[a].insert(0);
        }
    }
    while( Q.size() )
    {
        cur = Q.front();
        Q.pop();
//        cout << "cur = " << cur << endl;
        for ( set<long long>::iterator setLLIt = gr[cur].begin(); setLLIt != gr[cur].end(); setLLIt++ )
        {
            nex = *setLLIt;
            gr[nex].erase( cur );
            dis[nex].insert( *dis[cur].begin() + 1 );
            if ( gr[nex].size() == 1 && dis[nex].size()==1 )
            {
                Q.push( nex );
            }
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f; // for loop
    cin >> n;
//    cout << "n = " << n << endl;
    for ( a = 1; a < n; a++ )
    {
        scanf("%lld %lld", &u, &v);
        gr[u].insert(v);
        gr[v].insert(u);
    }
    bfs();
    for ( a = 1; a <= n; a++ )
    {
        if ( gr[a].size() )
        {
            continue;
        }
//        cout << "a = " << a << endl;
        if ( dis[a].size() == 1 )
        {
            posAns = *dis[a].begin();
        }
        else if ( dis[a].size() == 2 )
        {
            posAns = *dis[a].begin() + *dis[a].rbegin();
        }
        else
        {
            cout << -1;
            return 0;
        }
//        cout << "posAns = " << posAns << endl;
        while ( posAns &&  ( !(posAns&1) ) )
        {
            posAns >>= 1;
        }
        ans = min(posAns, ans);
    }
    if ( ans >= INT_MAX )
    {
        ans = -1;
    }
    cout << ans;
    return 0;
}
