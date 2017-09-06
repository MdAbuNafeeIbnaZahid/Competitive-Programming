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
#define LLMAX ( (unsigned long long) -1LL >> 1LL )


void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


void printSetLL(set<long long> setLLToPr)
{
    long long a, b, c;
    set<long long>::iterator setLLIt;
    for (setLLIt = setLLToPr.begin(); setLLIt != setLLToPr.end(); setLLIt++)
    {
        cout << *setLLIt << " ";
    }
    cout << endl;
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

LL getGcd(LL u, LL v)
{
    if ( u > v )
    {
        swap(u, v);
    }
    if ( u == 0 )
    {
        return v;
    }
    return getGcd(v%u, u);
}


struct DSU
{
    LL *parentAr, *countAr;
    LL siz;
    DSU(LL siz)
    {
        LL a, b, c,d ;
        this->siz = siz;
        parentAr = new LL[siz];
        countAr = new LL[siz];
        FOR(a,0,siz)
        {
            parentAr[a] = a;
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
        if ( getParent(u) == getParent(v) )
        {
            return ;
        }
        countAr[ getParent(v) ] += countAr[ getParent(u) ];
        parentAr[ getParent(u) ] = getParent( v );
    }
    LL getCount( LL u )
    {
        return countAr[ getParent(u) ];
    }
};


struct BIT
{
    LL *treeAr;
    LL siz;
    BIT(){}
    BIT(LL siz)
    {
        this->siz = siz;
        treeAr = new long long[siz+9];
        RESET( treeAr);
    }
    long long read(long long idx)
    {
        long long sum = 0;
        while(idx > 0)
        {
            sum += treeAr[ idx ];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(long long idx, long long val)
    {
        while(idx<=siz)
        {
            treeAr[idx] += val;
            idx += (idx & -idx);
        }
    }
};


struct Triple
{
    LL u, v, w;
    Triple(){}
    Triple(long long u, long long v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator < (const Triple B) const
    {
        if ( u == B.u )
        {
            if ( v == B.v )
            {
                return w < B.w;
            }
            return v < B.v;
        }
        return u < B.u;
    }
};



/******   END OF HEADER *********/
#define SIZE 59
#define eps (1e-8)
LL n, m, x;

struct edge
{
    LL to, resCap, resBear, transIdx;
    edge(){}
    edge(LL to, LL resCap, LL resBear, LL transIdx)
    {
        this->to = to;
        this->resCap = resCap;
        this->resBear = resBear;
        this->transIdx = transIdx;
    }
};

vector< edge > gr[SIZE];

LL levelAr[SIZE], visitedAr[SIZE];

void printGraph()
{
    LL a, b, c, d;
    FOR(a,1,1+n)
    {
        DBG(a);
        for (auto it : gr[a])
        {
            DBG4(it.to, it.resCap, it.resBear, it.transIdx);
        }
    }
}


bool bfs(LL s, LL t)
{
    LL a, b, c, d, e;
    FOR(a,0,SIZE)
    {
        levelAr[a] = INT_MAX;
    }
    levelAr[s] = 0;
    queue<LL> Q;
    Q.push( s );
    while( Q.size() )
    {
        LL cur = Q.front();
        Q.pop();
        for (auto it : gr[cur])
        {
            if ( it.resBear > 0 && levelAr[ it.to ] >= INT_MAX )
            {
                levelAr[ it.to ] = levelAr[cur] + 1;
                Q.push( it.to );
            }
        }
    }
    return levelAr[t] < INT_MAX;
}

// it is dfs based function
LL sendFlow(LL u, LL flow, LL t)
{
    LL a, b, c, d,e;
//    cout << "in sendFlow" << endl;
//    DBG3(u, flow, t);
    if (u == t)
    {
//        cout << "destination reached " << endl;
//        cout << "returning " << flow << endl;
        return flow;
    }
    for (auto &it : gr[u])
    {
        if ( levelAr[it.to] == levelAr[u]+1 && it.resBear > 0 )
        {
            LL curFlow = min(flow, it.resBear);
            LL tempFlow = sendFlow(it.to, curFlow, t);
            if ( tempFlow > 0 )
            {
                it.resBear -= tempFlow;
                gr[ it.to ][ it.transIdx ].resBear += tempFlow;
//                cout << "returing " << tempFlow << endl;
                return tempFlow;
            }
        }
    }
//    cout << "returing 0" << endl;
    return 0;
}

LL dinicMaxFlow(LL s, LL t)
{
    if (s==t)
    {
        return INT_MAX;
    }
    LL total = 0;
    while( bfs(s, t) == true )
    {
//        cout << "starting the bfs while loop " << endl;
//        cout << "levelAr " << endl;
//        printLLArray( levelAr, 1, n );
        while( LL flow = sendFlow(s, LLMAX, t) )
        {
//            cout << "starting of sendFlow while loop" << endl;
            total += flow;
//            DBG( total );
        }
    }
    return total;
}

void transformGraph(double w)
{
    LL a, b, c, d, e, f;
//    w /= x;
    FOR(a,0,SIZE)
    {
        for (auto &it : gr[a])
        {
            it.resBear = it.resCap * x / w;
        }
    }
}

double binSearch(double low, double high)
{
//    cout << "in binSearch" << endl;
    LL a, b, c, d, e;
    double mid = (low+high)/2;
//    DBG3(low, mid, high);
    if ( abs(high-low) <= eps )
    {
        return high;
    }
    transformGraph( mid );

//    printGraph();


    LL maxFlowVal = dinicMaxFlow(1, n);
//    DBG(maxFlowVal);

    if ( maxFlowVal >= x )
    {
        return binSearch(mid, high);
    }
    else
    {
        return binSearch(low, mid);
    }
}



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    cin >> n >> m >> x;
//    DBG3(n, m, x);
    FOR(a,1,1+m)
    {
        LL ai, bi, ci;
        ILL3(ai, bi, ci);

        LL aiSiz = gr[ai].size();
        LL biSiz = gr[bi].size();

        gr[ai].PUB( edge(bi, ci, 0, biSiz) );
        gr[bi].PUB( edge(ai, 0, 0, aiSiz) );
    }

    double ans = binSearch(0, INT_MAX);
//    double ans = oneBear * x;

    printf("%0.10lf\n", ans);

    return 0;
}


