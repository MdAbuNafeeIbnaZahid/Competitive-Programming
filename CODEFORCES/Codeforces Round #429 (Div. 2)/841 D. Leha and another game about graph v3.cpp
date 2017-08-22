
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

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

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


/******   END OF HEADER *********/
#define SIZE 300009
struct edge
{
    LL to, num;
    edge(){}
    edge(LL to, LL num)
    {
        this->to = to;
        this->num = num;
    }
};

LL n, m;
LL dAr[SIZE];
LL lastMin, bit = 0;

vector<edge> gr[SIZE], ST[SIZE];
vector<LL> ansVec;


LL parentAr[SIZE], parentEdgeAr[SIZE];
stack<LL> stak;

void bfs( LL u )
{
//    cout << "start of bfs" << endl;
    queue<LL> Q;
    Q.push( u );
    stak.push( u );
    SET( parentAr );
    parentAr[ u ] = 0;
    while( Q.size() )
    {
        LL cur = Q.front();
//        DBG(cur);
        Q.pop();
        for (auto it : gr[cur])
        {
            LL to = it.to;
//            DBG( to );
            LL num = it.num;
//            DBG( num );
            if ( parentAr[to] != -1 )
            {
//                cout << "to already pushed in queue" << endl;
                continue;
            }
            parentAr[ to ] = cur;
            parentEdgeAr[ to ] = num;
            Q.push( to );
            stak.push( to );
        }
    }
}

vector<LL> getAnsVect()
{
    vector<LL> ret;
    while( stak.size() )
    {
        LL cur = stak.top();
        stak.pop();
        if ( dAr[cur] )
        {
//            DBG( cur );
//            DBG( parentEdgeAr[cur] );
            ret.PUB( parentEdgeAr[cur] );
            dAr[ parentAr[cur] ] ^= 1;
        }
    }
    return ret;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> m;
//    DBG(n);
//    DBG(m);
    bit = 0;
    lastMin = 0;
    FOR(a,1,n+1)
    {
        scanf("%lld", &dAr[a]);
        if ( dAr[a] == -1 )
        {
            dAr[a] = 0;
            lastMin = a;
        }
        bit ^= dAr[a];
    }
    if ( bit )
    {
        if ( lastMin <= 0 )
        {
            cout << -1;
            return 0;
        }
        dAr[ lastMin ] = 1;
    }
    FOR(a,1,m+1)
    {
        LL u, v;
        scanf("%lld %lld", &u, &v);
        gr[ u ].PUB( edge(v, a) );
        gr[ v ].PUB( edge(u, a) );
    }

    bfs(1);

    ansVec = getAnsVect();
    cout << ansVec.size() << endl;;
    printVecLL( ansVec );



    return 0;
}

