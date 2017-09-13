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
void prAr(T1 *ar, LL si, LL ei)
{
    long long a, b, c;
    for (a = si; a <= ei; a++)
    {
        cout << "ar [ " << a << " ] = " << ar[a] << endl;
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


// __builtin_popcountll = long long

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
#define SIZE 100009
LL n, m;
vector<LL> gr[SIZE], transGr[SIZE], consGr[SIZE];
LL cAr[SIZE], visAr[SIZE], compoAr[SIZE];


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
            countAr[a] = cAr[a];
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

DSU dsu(SIZE+3);

void dfs1(LL u, vector<LL> &vec)
{
    if ( visAr[u] )
    {
        return;
    }
    visAr[u] = 1;
    for (auto it : gr[u] )
    {
        dfs1(it, vec);
    }
    vec.push_back( u );
}

void dfs2(LL u, LL par, DSU &ds)
{
    LL a, b, c, d, e;
    if (visAr[u])
    {
        return;
    }
    visAr[u] = 1;
    ds.makePair( u, par );
    for (auto it : transGr[u])
    {
        dfs2(it, par, ds);
    }
}

void makeConsGr()
{
    LL a, b, c, d, e;
    FOR(a,1,SIZE)
    {
        for (auto it : gr[a])
        {
            if ( dsu.getParent(a) != dsu.getParent(it) )
            {
                consGr[ dsu.getParent(a) ].PUB( dsu.getParent(it) );
            }
        }
    }
}

LL dpAr[SIZE];

void calcDp(LL u)
{
    LL a, b, c, d;
    LL head = dsu.getParent(u);
    dpAr[head] = dsu.getCount(head);
    LL addee = 0;
    for (auto it : consGr[u])
    {
        aMax(addee, dpAr[ dsu.getParent(it) ]);
    }
    dpAr[head] += addee;
}

void printGr( vector<LL> *grAr )
{
    LL a, b, c, d, e;
    FOR(a,1,1+n)
    {
        DBG(a);
        prVec( grAr[a] );
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    cin >> n >> m;
//    DBG2(n, m);
    FOR(a,1,1+n)
    {
        ILL( cAr[a] );
        dsu.countAr[a] = cAr[a];
    }

//    prAr(cAr, 1, n);
    FOR(a,1,1+m)
    {
        LL u, v;
        ILL2(u, v);
        gr[u].PUB(v);
        transGr[v].PUB(u);
    }
//    cout << "printing graph" << endl;
//    printGr( gr );
//    cout << "printing transGr" << endl;
//    printGr( transGr );
    RESET(visAr);
    vector<LL> nodeVec;
    FOR(a,1,1+n)
    {
        dfs1(a, nodeVec);
    }
    REV( nodeVec );

//    prVec( nodeVec );

    RESET(visAr);
    for (auto it : nodeVec)
    {
        dfs2(it, it, dsu);
    }
//    cout << "parentAr " << endl;
//    prAr(dsu.parentAr, 1, n);

//    cout << "countAr " << endl;
//    prAr(dsu.countAr, 1, n);

    makeConsGr();


    REV( nodeVec );
//    cout << "just before calcDp" << endl;
//    cout << "printing nodeVec " << endl;
//    prVec( nodeVec );
    for (auto it : nodeVec)
    {
        calcDp(it);
    }
    FOR(a,1,1+n)
    {
        LL ans = dpAr[ dsu.getParent(a) ];
        printf("%lld ", ans);
    }
    return 0;
}


