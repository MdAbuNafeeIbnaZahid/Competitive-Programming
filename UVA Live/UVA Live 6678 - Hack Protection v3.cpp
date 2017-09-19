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
    Pair(){}
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
    Triple(){}
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
#define SPWIDTH 39

LL n;

LL sparseTree[SIZE][59];
map<LL, ordered_set > myMap;


vector<LL> inpVec;
vector<LL> xorVec;
vector<LL> changeAr[SIZE];

void makeSparseTree( vector<LL> vecLL )
{
//    cout << "in make sparse tree " << endl;
//
//    cout << "printing vecLL " << endl;
//    prVec( vecLL );

    LL a, b, c, d;
    LL len = vecLL.size();
    FOR(a,0,n)
    {
        sparseTree[a][0] = inpVec[a];
    }

//    cout << "initialized column 0 of sparse tree " << endl;

    FOR(a,1,SPWIDTH)
    {
//        DBG( a );
        FOR(b,0,n)
        {
//            DBG( b );
            if ( b+(1LL<<a)-1LL >= len )
            {
                break;
            }
            sparseTree[b][a] = sparseTree[b][a-1] & sparseTree[b+(1<<(a-1))][a-1];
        }
    }
}


void printSparseTree(LL num)
{
    LL a, b, c, d;
    FOR(a,0,num)
    {
        DBG( a );
        prAr( sparseTree[a], 0, 4 );
    }
}


LL getRangeAnd(LL si, LL ei)
{
    LL a, b, c, d;
    LL k = 0, ret;

    FOR(a,0,SIZE)
    {
        if ( si+(1LL<<a) > ei+1 )
        {
            break;
        }
    }
    k=a-1;
    ret = sparseTree[si][k] & sparseTree[ei-(1LL<<k)+1][k];
//    ret = getRangeAnd(si, k) & getRangeAnd( ei-(1LL<<k)+1,  k);
    return ret;
}

vector<LL> getChangeVec(LL idx)
{
//    cout << "in getChangeVec " << endl;
//    DBG( idx );
    LL a, b, c, d, e;
    LL len = inpVec.size();
//    DBG( len );
    vector<LL> ret;
    ret.push_back( idx );
    LL val = inpVec[idx];

//    DBG(val);

//    cout << "entering while loop " << endl;
    while( 1 )
    {
//        DBG(val);
        if ( getRangeAnd(idx, inpVec.size()-1) == val )
        {
//            cout << " will break now " << endl;
            ret.push_back( inpVec.size() );
            break;
        }

        LL lowIdx = ret[ ret.size()-1 ]+1;
        LL highIdx = inpVec.size()-1;



//        DBG2(lowIdx, highIdx);

        while( lowIdx < highIdx )
        {
            LL midIdx = (lowIdx+ highIdx)>>1;
            if ( getRangeAnd(idx, midIdx) < val )
            {
                highIdx = midIdx;
            }
            else
            {
                lowIdx = midIdx+1;
            }
        }
        ret.push_back( lowIdx );
        val = getRangeAnd(idx, lowIdx);
    }
    return ret;
}

LL bruteAns( vector<LL> vecLL )
{
    LL ret = 0;
    LL a, b, c, d, e;
    LL len = vecLL.size();
    FOR(a,0,len)
    {
        FOR(b,a,len)
        {
            LL xorVal = 0;
            LL andVal = (~0);
            FOR(c,a,1+b)
            {
                xorVal ^= vecLL[c];
                andVal &= vecLL[c];
            }
            if ( xorVal==andVal )
            {
                ret++;
            }
        }
    }
    return ret;
}


LL getRangeXorCnt(  LL si, LL ei , LL xVal)
{
    LL ret = myMap[xVal].order_of_key( ei+1 );
    ret -= myMap[xVal].order_of_key( si );
    return ret;
}


LL solve( vector<LL> vecLL )
{
//    cout << "in solve " << endl;
//    cout << "printing vecLL " << endl;
//    prVec( vecLL );


    LL ret = 0;
    LL a, b, c, d, e;
    LL len = vecLL.size();
//    DBG( len );


    myMap.clear();
    xorVec.clear();
    makeSparseTree( vecLL );
//    cout << "sparse tree is built " << endl;
//
//    cout << "printing sparse tree " << endl;
//    printSparseTree( len );
//    cout << endl;

    LL xorVal = 0;
    FOR(a,0,len)
    {
        xorVal ^= vecLL[a];
        xorVec.push_back( xorVal );
        myMap[xorVal].insert( a );
    }

//    cout << "created xorVal & created myMap" << endl;

    LL xorUpto = 0;
    FOR(a,0,len)
    {
//        DBG( a );
        changeAr[a] = getChangeVec(a);

//        cout << "printing changeAr" << endl;
//        prVec( changeAr[a] );


        if (a==0)
        {
            xorUpto = 0;
        }
        else
        {
            xorUpto = xorVec[a-1];
        }
        FOR(b,0, changeAr[a].size()-1 )
        {
            LL targetXor = xorUpto ^ ( getRangeAnd(a, changeAr[a][b]) );
            ret += getRangeXorCnt(changeAr[a][b], changeAr[a][b+1]-1,  targetXor);
        }
    }
    return ret;
}



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e;
    while( scanf("%lld", &n) != EOF )
    {
//        n = rand() % 100;
//        DBG( n );
        inpVec.clear();
        FOR(a,0,n)
        {
            LL vi;
            ILL(vi);
//            vi = rand() % SIZE;
            inpVec.push_back( vi );


        }
//        cout << "printing inpVec " << endl;
//        prVec( inpVec );

        LL ans = solve( inpVec );

//        if (ans != bruteAns(inpVec))
//        {
//            exit(-5);
//        }

        printf("%lld\n", ans);
    }
    return 0;
}


