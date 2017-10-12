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
#define SIZE 109

struct solution
{
    LL subSeqLen;
    TripleLL prev;
    char ch;
    solution(){}
};

solution dp[SIZE][SIZE][SIZE];
        // oneIdx  twoIdx   matchUpto




void init()
{
    LL a, b, c, d, e;
    FOR(a,0,SIZE)
    {
        FOR(b,0,SIZE)
        {
            FOR(c,0,SIZE)
            {
                dp[a][b][c].subSeqLen = INT_MIN;
            }
        }
    }
    FOR(a,0,SIZE)
    {
        dp[a][0][0].subSeqLen = 0;
        dp[0][a][0].subSeqLen = 0;
    }
}


VL getPrefixVec(string pattern)
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
        if ( pattern[a] == pattern[j] )
        {
            prefixVec.push_back( ++j );
            a++;
        }
        else
        {
            if ( j > 0 )
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

LL getNextMatchUpto( LL prevMatchUpto, char nextChar, const VL &prefixVec,
const string &pattern )
{
    LL j = prevMatchUpto;
    assert( prefixVec.size()==pattern.size() );
    assert( j < pattern.size() );
    while(1)
    {
        if ( pattern[j] == nextChar )
        {
            return ++j;
        }



        if ( j > 0 )
        {
            j = prefixVec[j-1];
        }
        else
        {
            return 0;
        }
    }
    return 0;
}


void update(LL prevI, LL prevJ, LL prevK, struct solution &cur, char ch = NULL)
{
    LL nextSubSeqLen = dp[prevI][prevJ][prevK].subSeqLen + (ch!=NULL);
    if ( nextSubSeqLen > cur.subSeqLen )
    {
        cur.subSeqLen = nextSubSeqLen;
        cur.prev = TripleLL(prevI, prevJ, prevK);
        cur.ch = ch;
    }
}



string getAns(LL oneLen, LL twoLen, LL virusLen)
{
    LL a, b, c, d, e;
    string ans = "";
    LL maxSubSeqLen = -1;
    LL curVirusLen = 0;
    FOR(a,0,virusLen)
    {
        if ( dp[oneLen][twoLen][a].subSeqLen > maxSubSeqLen )
        {
            maxSubSeqLen = dp[oneLen][twoLen][a].subSeqLen;
            curVirusLen = a;
        }
    }

    LL curOneLen = oneLen;
    LL curTwoLen = twoLen;
    while( curOneLen>0 && curTwoLen>0 )
    {
        LL curChar = dp[curOneLen][curTwoLen][curVirusLen].ch;
        TripleLL curPrev = dp[curOneLen][curTwoLen][curVirusLen].prev;
        if ( curChar != NULL )
        {
            ans.PUB(curChar);
        }
        curOneLen = curPrev.first;
        curTwoLen = curPrev.second;
        curVirusLen = curPrev.third;
    }
    REV( ans );
    return ans;
}



string solve(string strOne, string strTwo, const string &virus)
{
    LL a, b, c, d, e;
    VL prefixVec = getPrefixVec(virus);
    DBG(prefixVec);
    strOne = "#" + strOne;
    strTwo = "#" + strTwo;
    init();
    FOR(a,1,strOne.size())
    {
        FOR(b,1,strTwo.size())
        {
            FOR(c,0,virus.size())
            {
                char nextChar = 0;
                if ( strOne[a]==strTwo[b] )
                {
                    nextChar = strOne[a];
                    LL nextMatchUpto = getNextMatchUpto(c, nextChar, prefixVec,
                        virus);
                    DBG(nextMatchUpto);
                    update(a-1, b-1, c, dp[a][b][nextMatchUpto], nextChar);
                }

                nextChar = 0;
                update(a-1, b, c, dp[a][b][c]);
                update(a, b-1, c, dp[a][b][c]);
            }
        }
    }
    string ans = getAns(strOne.size()-1, strTwo.size()-1, virus.size());
    if ( ans.size()==0 )
    {
        ans = "0";
    }
    return ans;
}


int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    LL a, b, c, d, e;
    string s1, s2, virus;
    cin >> s1 >> s2 >> virus;
    string ans = solve(s1, s2, virus);
    cout << ans;


//    LL ans = -1;
//    DBG( virus );
//    FOR(a,0,virus.size())
//    {
//        aMax(ans, dp[s1.size()][s2.size()][a].subSeqLen  );
//    }
//    DBG(ans);


    return 0;
}
