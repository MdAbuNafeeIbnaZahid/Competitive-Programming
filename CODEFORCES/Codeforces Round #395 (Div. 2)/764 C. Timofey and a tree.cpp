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
#define SIZE 100009
long long n, u, v, isOk;
long long colAr[SIZE];
long long a, b, c , d, e, f, g, subTreeVal, cnt;
vector<long long> gr[SIZE];
struct DSU
{
    long long parentAr[SIZE], total[SIZE];
    DSU()
    {
        long long a, b, c;
        for (a = 0; a < SIZE; a++)
        {
            parentAr[a] = a;
            total[a] = 1;
        }
    }
    long long getParent(long long u)
    {
        if ( u != parentAr[u] )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    long long getTotal(long long u)
    {
        return total[ getParent(u) ];
    }
    void makePair(long long u, long long v)
    {
        if ( getParent(u)==getParent(v) )
        {
            return;
        }
        total[ getParent(v) ] += total[ getParent(u) ];
        parentAr[ getParent(u) ] = getParent(v);
    }
};
struct edge
{
    long long from, to;
    edge(){}
    edge(long long from, long long to)
    {
        this->from = from;
        this->to = to;
    }
    const bool operator < ( const edge B ) const
    {
        if ( from == B.from )
        {
            return to < B.to;
        }
        return from < B.from;
    }
};
map<edge, long long> edgeColCount;

void printEdgeToLLMap(map<edge, long long> toPrint)
{
    long long a, b, c, d, e, f;
    map<edge, long long>::iterator mapIt;
    for ( mapIt = toPrint.begin(); mapIt != toPrint.end(); mapIt++ )
    {
        cout << (mapIt->first).from << " " << (mapIt->first).to << " " << mapIt->second << endl;
    }
}

long long dfs(edge ed)
{
    long long a, b, c, d, e, f, g, u = ed.from, v = ed.to, ret = 0;
//    cout << " ed.from =  " << ed.from << endl;
//    cout << " ed.to =  " << ed.to << endl;
    //if ( edgeColCount[ ed ] !=  )
//    printEdgeToLLMap( edgeColCount );
    map<edge, long long>::iterator mapIt = edgeColCount.find( ed );
//    cout << "find function called" << endl;
//    printEdgeToLLMap( edgeColCount );
    if ( mapIt == edgeColCount.end() )
    {
//        cout << " edgeColCount.find( ed ) == edgeColCount.end() " << endl;
        for ( a = 0; a < gr[ v ].size(); a++ )
        {
            b = gr[v][a];
            if ( b != ed.from )
            {
                ret = ret || dfs( edge(v, b) );
                ret = ret || ( colAr[v] != colAr[b] );
            }
        }
        edgeColCount[ ed ] = ret;
    }
//    cout << " edgeColCount[ ed ] = " <<  edgeColCount[ ed ] << endl;
    return edgeColCount[ ed ];
}
DSU myDsu;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
//    cout << "n = " << n << endl;
    for (a = 1; a < n; a++)
    {
        scanf("%lld %lld", &u, &v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &colAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        for (b = 0; b < gr[a].size(); b++)
        {
            v = gr[a][b];
            if ( colAr[a]==colAr[ v ] /* && myDsu.getParent(a)!=myDsu.getParent(v) */ )
            {
                myDsu.makePair(a, v);
            }
        }
      }
      for (a = 1; a <= n; a++)
      {
          cnt = myDsu.getTotal(a);
          for (b = 0; b < gr[a].size(); b++)
        {
            v = gr[a][b];
            if ( colAr[a]!=colAr[ v ] /* && myDsu.getParent(a)!=myDsu.getParent(v) */ )
            {
                cnt += myDsu.getTotal( v );
            }
        }
        if (cnt == n)
        {
            cout << "YES" << endl << a;
            return 0;
        }
      }
//

    cout << "NO";
    return 0;
}
