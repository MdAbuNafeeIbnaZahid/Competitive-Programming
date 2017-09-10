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

// Generic Pair with stream inserter
template<class Typ1, class Typ2> class Pair
{
public:
    Typ1 first;
    Typ2 second;
    Pair(Typ1 first, Typ2 second)
    {
        this->first = first;
        this->second = second;
    }
    bool operator < ( const Pair B ) const
    {
        if ( first == B.first )
        {
            return second < B.second;
        }
        return first < B.first;
    }

};
template<class Typ1, class Typ2>
ostream &operator << (ostream &stream, const Pair<Typ1, Typ2> pr)
{
    stream << " (" << pr.first << ", " << pr.second << ") ";
    return stream;
}


// Generic Triple with stream inserter
template<class Typ1, class Typ2, class Typ3> class Triple
{
public:
    Typ1 first;
    Typ2 second;
    Typ3 third;
    Triple(Typ1 first, Typ2 second, Typ3 third)
    {
        this->first = first;
        this->second = second;
        this->third = third;
    }
    bool operator < ( const Triple B ) const
    {
        if ( first == B.first )
        {
            if ( second == B.second )
            {
                return third < B.third;
            }
            return second < B.second;
        }
        return first < B.first;
    }

};
template<class Typ1, class Typ2, class Typ3>
ostream &operator << (ostream &stream, const Triple<Typ1, Typ2, Typ3> tr)
{
    stream << " (" << tr.first << ", " << tr.second << ", " << tr.third << ") ";
    return stream;
}


#define LL 			long long
#define PairLL		Pair<long long, long long>
#define TripleLL    Triple<long long, long long, long long>



#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MP              make_pair
#define PUB				push_back
#define POB				pop_back
#define PUF             push_front
#define POF             pop_front


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


template<typename typ>
void prVec( vector<typ> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename typ>
void prSet( set<typ> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename T1, typename T2>
void prMap( map<T1, T2> toPr )
{
    for (auto it : toPr)
    {
        cout << " [ " << it.first << " ] = " << it.second << endl;
    }
    cout << endl;
}

template<typename T1>
void prAr(  T1 *ar , LL si, LL ei)
{
    long long a, b, c;
    for (a = si; a <= ei; a++)
    {
        cout << "ar [ " << a << " ] = " << *(ar+a) << endl;
    }
}

template<typename T1>
void prMulSet( multiset<T1> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename T1>
void prQ( queue<T1> toPr )
{
    while( toPr.size() )
    {
        cout << toPr.front() << " , " << endl;
        toPr.pop();
    }
    cout << endl;
}

template<typename T1>
void prDQ( deque<T1> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
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

void ILL4(LL &u, LL &v, LL &w, LL &x)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld %lld", &u, &v, &w, &x);
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

LL getLcm(LL u, LL v)
{
    LL g = getGcd(u, v);
    return (u/g) * v;
}

template<typename T1, typename T2>
T1 aMin(T1 &u, T2 v)
{
    if ( v < u )
    {
        u = v;
    }
    return u;
}


template<typename T1, typename T2>
T1 aMax(T1 &u, T2 v)
{
    if ( v > u )
    {
        u = v;
    }
    return u;
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

LL checkBit(LL num, LL pos)
{
    return (num>>pos) & 1LL;
}

LL setBit(LL num , LL pos)
{
    return num | (1LL<<pos);
}

LL resetBit(LL num, LL pos)
{
    return num & ( ~( 1LL<<pos ) );
}



/******   END OF HEADER *********/
#define SIZE 109
// to, dis
vector< PairLL > gr[SIZE], errand;
LL t, n, m, b;
// source, desti
LL spAr[SIZE][SIZE];

LL dpAr[1<<14][SIZE];

LL homeCity, z;

vector<LL> workNode;

void dijkstra(LL s, LL *disAr)
{
//    cout << "in dijkstra " << endl;
//    DBG( s );
    LL a, b, c, d, e;
    FOR(a,0,SIZE)
    {
        disAr[a] = INT_MAX;
    }
    disAr[s] = 0;
    // dis, destination
    set< PairLL > minSet;
    minSet.insert( PairLL(0, s) );
    while( minSet.size() )
    {
        PairLL cur = *minSet.begin();
        minSet.erase( minSet.begin() );
        LL curDis = cur.first;
        LL curNode = cur.second;

//        DBG( cur );

        if( disAr[curNode] < curDis )
        {
            continue;
        }
        for (auto it : gr[curNode])
        {
            LL nextNode = it.first;
            LL nextDis = it.second;
            if ( curDis+nextDis < disAr[nextNode]  )
            {
                disAr[ nextNode ] = curDis + nextDis;
                minSet.insert( PairLL(disAr[ nextNode ], nextNode) );
            }
        }
    }
}


void makeDp(LL erCnt, LL wnCnt)
{
    vector<LL> bitAr[SIZE];
    LL a, b, c, d, e;
    FOR( a, 0, (1<<erCnt) )
    {
        bitAr[ __builtin_popcountll(a) ].push_back( a );
        FOR(b,0,wnCnt)
        {
            dpAr[a][b] = INT_MAX;
            if (a==0)
            {
                dpAr[a][b] = spAr[homeCity][ workNode[b] ];
            }
        }
    }
    FOR(a,1,SIZE)
    {
        for (auto it : bitAr[a]) // all possible binary num state
        {
            for (auto it2 : workNode) // all possible work node
            {
//                dpAr
            }
        }
    }
}


void makeDp2()
{
    vector<LL> bitAr[SIZE];
    LL a, b, c, d, e;
    LL erCnt = errand.size();
    FOR( a, 0, (1<< erCnt ) )
    {
        bitAr[ __builtin_popcountll(a) ].push_back( a );
        FOR(b,1,1+n)
        {
            dpAr[a][b] = INT_MAX;
            if (a==0)
            {
                dpAr[a][b] = spAr[homeCity][ b ];
            }
        }
    }
    FOR(a,0,erCnt+1)
    {
        for (auto it : bitAr[a])
        {
            FOR(b,1,1+n)
            {
                FOR(c,0,erCnt)
                {
                    if ( checkBit(it, c)==0 )
                    {
                        aMin( dpAr[ setBit(it, c) ][ errand[c].second ],
                        dpAr[it][b] + spAr[b][ errand[c].first ] +
                        spAr[ errand[c].first ][ errand[c].second ] );
                    }
                }
            }
        }
    }
}


void printSpAr()
{
    LL a, b, c, d;
    FOR(a,1,1+n)
    {
        cout << "source = " << a << endl;
        prAr( spAr[a], 1, n );
        cout << endl;
    }
}

void printGr()
{
    LL a, b, c, d, e;
    cout << "printing graph " << endl;
    FOR(a,1,1+n)
    {
        DBG(a);
        prVec( gr[a] );
        cout << endl;
    }
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL i, j, k, p, q;
    cin >> t;
//    DBG(t);
    FOR(i,1,1+t)
    {
        cin >> n >> m >> b;
//        DBG3(n, m, b);
        homeCity = b;
        FOR(j,0,SIZE)
        {
            gr[j] = vector<PairLL>();
        }
        errand = vector<PairLL>();
        workNode = vector<LL>();
        FOR(j,0,m)
        {
            LL ui, vi, di;
            ILL3(ui , vi, di);
            gr[ui].PUB( PairLL(vi, di) );
            gr[vi].PUB( PairLL(ui, di) );
        }
//        printGr();
        FOR(j,1,1+n)
        {
            dijkstra(j, spAr[j]);
        }
//        printSpAr();
        cin >> z;
        set<LL> workSet;
        FOR(j, 1,1+z)
        {
            LL uj, vj, bj;
            ILL3(uj, vj, bj);
            FOR(k,0,bj)
            {
                errand.push_back( PairLL(uj, vj) );
            }
            workSet.insert(uj);
            workSet.insert(vj);
        }
        for (auto it : workSet)
        {
            workNode.push_back( it );
        }
        makeDp2();
        LL ans = LLMAX;
        FOR(j,1,1+n)
        {
            aMin(ans, dpAr[ (1<<errand.size())-1 ][j] + spAr[j][b] );
        }
        cout << ans << endl;
    }
    return 0;
}


