#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>


#define SIZE 100009
#define SYN 1
#define ANT 2
#define NON 3


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




// disjoint set library

struct DSU
{
    long long *parentAr, *total;
    long long siz;
    DSU()
    {

    }
    DSU(long long siz)
    {
        long long a, b, c;
        this->siz = siz;
        parentAr = new long long[siz];
        total = new long long[siz];
        for (a = 0; a < siz; a++)
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

 struct myString
 {
    char str[29];
    myString(char *str)
    {
        strcpy(this->str, str);
    }
    bool operator < (const myString B) const
    {
        return strcmp(str, B.str) < 0;
    }
 };

// disjoint set library end

long long n, m, q, t;
long long u, v;
long long a, b, c, d, e, f;
char ai[29], xi[29], yi[29];

map< myString, long long > myMap;

struct mahDSU
{
    DSU dsu = DSU(3*SIZE);
    long long getRelation(long long u, long long v)
    {
        if ( dsu.getParent(u) == dsu.getParent(v) )
        {
            return 1;
        }
        else if ( dsu.getParent(u) == dsu.getParent(v+SIZE)
            || dsu.getParent(v) == dsu.getParent(u+SIZE) )
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
    char *makeRelation(long long typ, long long u, long long v)
    {
        char *ret;
        if ( typ == SYN )
        {
            ret = makeSyn(u, v);
        }
        else
        {
            ret = makeAnt(u, v);
        }
        return ret;
    }
    char* makeSyn(long long u, long long v)
    {
        if ( getRelation(u, v) == ANT )
        {
            return "NO";
        }
        dsu.makePair(u, v);
        dsu.makePair(u+SIZE, v+SIZE);
        return "YES";
    }
    char* makeAnt(long long u, long long v)
    {
        if ( getRelation(u, v) == SYN )
        {
            return "NO";
        }
        dsu.makePair(u, v+SIZE);
        dsu.makePair(u+SIZE, v);
        return "YES";
    }
};

int main()
{
//    freopen("input.txt", "r", stdin);
    mahDSU myMahDsu;
    cin >> n >> m >> q;
    for ( a = 1; a <= n; a++ )
    {
        scanf("%s", ai);
        myMap[ myString(ai) ] = a;
    }
//    cout << myMap.size() << endl;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %s %s", &t, xi, yi);
        u = myMap[ myString(xi) ];
        v = myMap[ myString(yi) ];
        char *ret = myMahDsu.makeRelation(t, u, v);
        printf("%s\n", ret);
    }
    for (a = 1; a <= q; a++)
    {
        scanf("%s %s", xi, yi);
        u = myMap[ myString(xi) ];
        v = myMap[ myString(yi) ];
        long long prin = myMahDsu.getRelation(u, v);
        printf("%lld\n", prin);
    }
    return 0;
}

