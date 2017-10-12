//#define DEBUG

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




/// ********* debug template by Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}


// This debugger for Multiset is written by Nafee
template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
    os << "[";
    typename multiset< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}


// This debugger for queue is written by Nafee
template < typename T >
ostream &operator << ( ostream & os, queue< T > v ) {
    os << "[";
    bool isFirst = true;
    while(v.size())
    {
        T cur = v.front();
        v.pop();
        if ( !isFirst )
        {
            os << ", ";
        }
        os << cur;
        isFirst = false;
    }
    return os << "]";
}



// This debugger for Deque is written by Nafee
template < typename T >
ostream &operator << ( ostream & os, const deque< T > &v ) {
    os << "[";
    typename deque< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}


// This debugger for array is written by Nafee
template<typename T1>
void prAr(T1 *ar, long long si, long long ei)
{
    long long a, b, c;
    for (a = si; a <= ei; a++)
    {
        cout << "ar [ " << a << " ] = " << ar[a] << endl;
    }
}


// This debugger for unordered_set is written by Nafee
template < typename T >
ostream &operator << ( ostream & os, const unordered_set< T > &v ) {
    os << "[";
    typename unordered_set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}





#define LL 			long long
#define PairLL		pair<long long, long long>
#define TripleLL    Triple<long long, long long, long long>
typedef vector<long long> VL;



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

#ifdef DEBUG
    #define DBG(x) cout<<#x<<" : "<<x<<endl
    #define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
    #define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
    #define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl
    #define dbgAr(ar, si, ei) cout<<#ar<<" : "<<endl; prAr(ar, si, ei)
#else
    #define DBG(x)
    #define DBG2(x, y)
    #define DBG3(x, y, z)
    #define DBG4(a,b,c,d)
    #define dbgAr(ar, si, ei)
#endif // DEBUG


#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define SPRIME 10007
#define BPRIME 1000000007
#define LLMAX ( (unsigned long long) -1LL >> 1LL )





inline void ILL(LL &u)
{
    LL a, b, c, d;
    scanf("%lld", &u);
}

inline void ILL2(LL &u, LL &v)
{
    LL a, b, c, d, e;
    scanf("%lld %lld", &u, &v);
}

inline void ILL3(LL &u, LL &v, LL &w)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld", &u, &v, &w);
}

inline void ILL4(LL &u, LL &v, LL &w, LL &x)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld %lld", &u, &v, &w, &x);
}



LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};


LL bigMod(LL base, LL exponent, LL M)
{
    if ( exponent == 0 ) return 1%M;
    LL x = bigMod(base, exponent>>1LL, M);
    x = (x*x)%M;
    if ( exponent&1LL )
    {
        x = (x*base)%M;
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
// void * memcpy ( void * destination, const void * source, size_t num );

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

#define SIZE 1000009LL
#define MOD 1000000007LL
typedef unordered_set<LL> USL;
typedef set<LL> SL;

string getString(const char *str)
{
    LL a, b, c, d, e;
    string ret = "";
    while(*str != 0)
    {
        ret.PUB( *str );
        str++;
    }
    return ret;
}


VL getPrefixVec( string pattern )
{
    LL a, b, c, d, e;
    VL prefixVec;
    LL len = pattern.size();
    if (len>0)
    {
        prefixVec.push_back( 0 );
    }
    LL j = 0;
    for (a = 1; a < len; )
    {
        if ( pattern[a]==pattern[j] )
        {
            prefixVec.push_back( ++j );
            a++;
        }
        else
        {
            if (j>0)
            {
                j = prefixVec[j-1];
            }
            else
            {
                prefixVec.push_back(j);
                a++;
            }
        }
    }
    return prefixVec;
}

SL getPrefixSuffixSet( string pattern )
{
    VL prefixVec = getPrefixVec(pattern);
    SL prefixSuffixSet;
    LL len = prefixVec.size();
    LL j = prefixVec[len-1];
    while(j>0)
    {
        prefixSuffixSet.insert( j );
        j = prefixVec[j-1];
    }
    return prefixSuffixSet;
}


bool isConflict(LL fir, LL sec, LL len, const SL &prefixSuffixSet)
{
    LL overlap = fir+len-sec;
    DBG(overlap);
    if (overlap<=0)
    {
        return false;
    }
    return prefixSuffixSet.find(overlap)==prefixSuffixSet.end();
}



LL solve(LL n, string p, VL yVec)
{
    DBG("in solve");
    DBG3(n, p, yVec);
    LL a, b, c, d, e, f;
    LL totalEmpty = 0;
    if ( yVec.size()==0 )
    {
        return bigMod(26, n, MOD);
    }
    SL prefixSuffixSet = getPrefixSuffixSet(p);
    DBG(prefixSuffixSet);
    LL pLen = p.size();
    FOR(a,0,yVec.size()-1)
    {
        DBG(a);
        LL fir = yVec[a];
        LL sec = yVec[a+1];
        if ( isConflict(fir, sec, pLen, prefixSuffixSet) )
        {
            return 0;
        }
        LL emptyMidLen = sec-fir-pLen;
        if (emptyMidLen>0)
        {
            totalEmpty += emptyMidLen;
        }
    }
    totalEmpty += yVec[0]-1;
    totalEmpty += n-yVec[ yVec.size()-1 ]-pLen+1;
    DBG(totalEmpty);
    LL ret = bigMod(26, totalEmpty, MOD);
    return ret;
}


int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    LL n , m;
    cin >> n >> m;
    DBG2(n, m);
    getchar();
    char str[SIZE];
    scanf("%s", str);
    string p = getString(str);
    DBG(p);
    VL yVec;
    FOR(a,0,m)
    {
        LL num;
        ILL(num);
        yVec.push_back( num );
    }
    DBG(yVec);
    LL ans = solve(n, p, yVec);
    cout << ans;
    return 0;
}

