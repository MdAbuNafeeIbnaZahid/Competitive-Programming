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
#define FRIEND 1
#define ENEMY 0
#define NO_REL 2
long long n, m;
long long rAr[SIZE], xAr[SIZE], switchNum[SIZE];
vector<long long> rel[SIZE];
struct DSU
{
    long long *parentAr;
    //DSU(){}
    DSU(long long siz=3*SIZE)
    {
        long long a, b, c, d;
        parentAr = new long long[siz+9];
        for ( a = 0; a < siz; a++ )
        {
            parentAr[a] = a;
        }
    }
    long long getParent( long long u)
    {
        if ( parentAr[u] != u )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    void makePair(long long u, long long v)
    {
        parentAr[ getParent(u) ] = getParent(v);
    }
    long long getRel(long long u, long long v)
    {
        if ( getParent(u) == getParent(v) ) return FRIEND;
        else if ( getParent(u) == getParent(v+SIZE) ) return ENEMY;
        return NO_REL;
    }
    long long makeRel(long long u, long long v, long long rel)
    {
        if ( getRel(u, v) == NO_REL )
        {
            if ( rel == FRIEND )
            {
                makePair(u, v);
                makePair(u+SIZE, v+SIZE);
            }
            else if ( rel == ENEMY )
            {
                makePair(u+SIZE, v);
                makePair(u, v+SIZE);
            }
        }
        else if ( getRel(u, v) != rel )
        {
            cout << "NO";
            exit(0);
        }
    }
};
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    DSU myDsu;
    cin >> n >> m;
    for ( a = 1; a <= n; a++ )
    {
        scanf("%lld", &rAr[a]);
    }
    for ( a = 1; a <= m; a++ )
    {
        scanf("%lld", &xAr[a]);
        for ( b = 1; b <= xAr[a]; b++ )
        {
            long long roomNum;
            scanf("%lld", &roomNum);
            rel[ roomNum ].push_back( a );
        }
    }
    for ( a = 1; a <= n; a++ )
    {
        myDsu.makeRel( rel[a][0], rel[a][1], rAr[a] );
    }
    cout << "YES";
    return 0;
}
