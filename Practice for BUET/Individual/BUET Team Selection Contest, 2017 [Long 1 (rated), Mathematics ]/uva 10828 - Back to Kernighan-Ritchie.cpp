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


#define LL 			long long
#define PairLL		pair<long long, long long>


#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MP              make_pair
#define PUB				push_back
#define POB				pop_back

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)

#define DBG(x) cout<<#x<<" : "<<x<<endl
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define SPRIME 10007
#define BPRIME 1000000007


void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


void printMapLLLL( map<LL, LL> mapToPr )
{
    LL a, b, c, d, e;
    map<LL, LL>::iterator mapIt;
    cout << endl;
    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
    {
        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
    }
    cout << endl;
}


void printLLArray( LL *ar, LL si, LL ei )
{
    LL a, b, c, d, e;
    FOR(a, si, ei+1)
    {
        printf("ar[ %lld ] = %lld\n\n", a, ar[a]);
    }
}


void  printSetPair( set<PairLL> givenSetPair )
{
    for ( auto it : givenSetPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;
}

void printVecPair( vector<PairLL> givenVecPair )
{
    for ( auto it : givenVecPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;
}



void ILL(LL &u)
{
    LL a, b, c, d;
    scanf("%lld", &u);
}

void ILL2(LL &u, LL &v)
{
    LL a, b, c, d, e;
    scanf("%lld %lld", &u, &v);
}

void ILL3(LL &u, LL &v, LL &w)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld", &u, &v, &w);
}



LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};


LL bigMod(LL a, LL b, LL M)
{
    if ( b == 0 ) return 1%M;
    LL x = bigMod(a, b/2, M);
    x = (x*x)%M;
    if ( b&1LL )
    {
        x = (x*a)%M;
    }
    return x;
}




/******   END OF HEADER *********/
#define SIZE 109
#define WHITE 0
#define GRAY 1
#define BLACK 2


double gausAr[SIZE][SIZE];
void printGausAr(LL siz)
{
    LL a, b, c, d, e, f;
    FOR(a,1,1+siz)
    {
        FOR(b,1,2+siz)
        {
            cout << gausAr[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void populateGausAr(LL siz)
{
    LL a, b, c, d, e, f;
    FOR(a,1,1+siz) // itearate rows
    {
        FOR(b,1,2+siz) // iterate columns
        {
            gausAr[a][b] = rand()%5;
        }
    }
}

void solveGaus(LL siz)
{
    LL a, b, c, d, e, f, g;
    FOR(a,1,1+siz) // row number
    {
        LL maxRow = a;
//        double maxRowVal = gausAr[a][a];
        FOR(b,a+1,1+siz)
        {
            if ( abs(gausAr[b][ a ] ) > abs( gausAr[maxRow][a] ) )
            {
                maxRow = b;
            }
        }
        // now swap
        if ( maxRow != a )
        {
            FOR(b,1,2+siz) // iterating column
            {
                swap( gausAr[a][ b ], gausAr[ maxRow ][b] );
            }
        }
        double div = gausAr[a][a];
        FOR(b,1,2+siz) // iterate the columns, make 1 in the target column
        {
            gausAr[a][ b ] /= div;
        }
        FOR(b,1,1+siz) // iterate rows
        {
            if ( b == a )
            {
                continue;
            }
            double mul = gausAr[ b ][a];
            FOR(c,1,2+siz) // iterate columns
            {
                gausAr[b][ c ] -= gausAr[a][c]*mul;
            }
        }
    }
}

vector<LL> incoming[SIZE], outgoing[SIZE], SCCin[SIZE], SCCout[SIZE];
LL n;
LL newNode[SIZE];

struct DSU
{
    LL parentAr*, *countAr;
    LL siz;
    DSU(LL siz)
    {
        LL a, b, c,d ;
        this->siz = siz;
        parentAr = new LL[siz];
        countAr = new LL[siz];
        FOR(a,0,siz)
        {
            ar[a] = a;
            countAr[a] = 1;
        }
    }
    LL getParent( LL u )
    {
        LL ret;
        if ( parentAr[u] != u )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    void makePair(LL u, LL v)
    {
        countAr[ getParent(v) ] += countAr[ getParent(u) ];
        parentAr[ getParent(u) ] = getParent( v );
    }
};

LL colorAr[SIZE];
double ansAr[SIZE];
vector<LL> sortedNode;
void dfs1( LL u, vector<LL> &sorN, LL *colAr )
{
    LL a, b, c, d, e, f, g;
    if ( colAr[u] )
    {
        return;
    }
    colAr[u] = 1;
    for ( auto it : outgoing[u] )
    {
        dfs1( it );
    }
    sorN.push_back( u );
}

void dfs2( LL u, LL compo, LL *colAr, DSU &dsu )
{
    LL a, b, c, d, e, f;
    if ( colAr[u] )
    {
        return;
    }
    colAr[u] = 1;
    for (auto it : incoming[u] )
    {
        dfs2(it, compo, dsu);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

//    while(1)
//    {
//        getchar();
//        getchar();
//        populateGausAr(4);
//        printGausAr(4);
//        solveGaus(4);
//        printGausAr(4);
//    }
    LL a, b, c, d, e, f;
    while(1)
    {
        ILL(n);
        if ( n == 0 )
        {
            return 0;
        }
        FOR(a,0,SIZE)
        {
            incoming[a] = vector<LL>();
            outgoing[a] = vector<LL>();
            SCCin[a] = vector<LL>();
            SCCout[a] = vector<LL>();
            ansAr[ a ] = 1;
        }
        while(1)
        {
            LL u, v;
            ILL2(u, v);
            if (  u == 0)
            {
                break;
            }
            outgoing[u].PUB( v );
            incoming[v].PUB( u );
        }
        RESET( colorAr );
        dfs1(1, sorN, colorAr);
        FOR(a,1,1+n)
        {
            if ( colorAr[ a ] == 0 )
            {
                ansAr[a] = 0;
            }
        }
        RESET( colorAr );
        DSU dfu( SIZE );
        REV( sortedNode );
        for (auto it : sortedNode)
        {
            if ( !colorAr[it] )
            {
                dfs2(it, it, dfu);
            }
        }
        FOR(a,1,1+n)
        {
            for (auto it : outgoing[a])
            {
                SCCout[ dfu.getParent(a) ].push_back( dfu.getParent(it) );
                SCCin[ dfu.getParent(it) ].push_back( dfu.getParent(a) );
            }
        }
        FOR(a,1,1+n)
        {
            if (  )
        }
    }


    return 0;
}
