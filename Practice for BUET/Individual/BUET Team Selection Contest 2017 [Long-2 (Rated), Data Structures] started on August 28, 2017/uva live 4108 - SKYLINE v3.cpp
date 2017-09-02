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
#define SIZE 100009

struct SegTree
{
    LL siz;
    LL *maxAr, *minAr, *lazyAr;
    SegTree(){}
    SegTree(LL siz)
    {
        this->siz = siz;
        maxAr = new LL[siz+9];
        minAr = new LL[siz+9];
        lazyAr = new LL[siz+9];
        RESET( maxAr );
        RESET( minAr );
        RESET( lazyAr );
    }

    void applyLazy(LL att, LL L, LL R)
    {
        if ( lazyAr[att] )
        {
//            cout << "in applyLazy " << endl;
//            DBG3(att, L, R);
            maxAr[att] = max( maxAr[att], lazyAr[att] );
            minAr[att] = max( minAr[att], lazyAr[att] );
            if ( L<R ) // if not leaf node
            {
//                LL mid = (L+R)/2;
                lazyAr[ 2*att ] = max( lazyAr[2*att], lazyAr[att] );
                lazyAr[ 2*att + 1 ] = max( lazyAr[2*att+1], lazyAr[att] );
            }
            lazyAr[att] = 0;
        }
    }

    LL update(LL att, LL L, LL R, LL lef, LL r, LL val)
    {
//        cout << "in update " << endl;
//        DBG3(att, L, R);
//        DBG3(lef, r, val);
        applyLazy(att, L, R);
        if ( r<L || R<lef ) // NO overlap
        {
//            cout << "no overlap, returning 0 " << endl;
            return 0;
        }
        if ( lef <= L && R <= r ) // complete overlap
        {
//            cout << "complete overlap " << endl;
            if ( maxAr[att] <= val )
            {
//                cout << " maxAr[att] <= val " << endl;
                maxAr[att] = val;
                minAr[att] = val;
                if ( R>L ) // if not a leaf node
                {
//                    cout << "not a leaf node" << endl;
//                    cout << "updating lazy of children " << endl;
                    lazyAr[ 2*att ] = max( lazyAr[2*att], val );
                    lazyAr[ 2*att+1 ] = max( lazyAr[2*att+1], val );
                }
                lazyAr[att] = 0;
//                cout << "returining R-L+1 " << endl;
//                DBG( R-L+1 );
                return R-L+1;
            }
            else if ( val <= minAr[att] )
            {
                return 0;
            }
        }

        // partial overlap or min <= val <= max
//        cout << "partial overlap or min <= val <= max" << endl;
        LL mid = (L+R)/2;
        LL lefRet = update(2*att, L, mid, lef, r, val);
        LL rightRet = update(2*att+1, mid+1, R, lef, r, val);

        maxAr[att] = max( maxAr[2*att], maxAr[2*att+1] );
        minAr[att] = min( minAr[2*att], minAr[2*att+1] );
        return lefRet+rightRet;
    }

    void print(LL upto)
    {
        LL a, b, c, d;
        cout << "lazyAr " << endl;
        printLLArray(lazyAr, 1, upto);
        cout << "minAr " << endl;
        printLLArray(minAr, 1, upto);
        cout << "maxAr " << endl;
        printLLArray(maxAr, 1, upto);
    }
};
LL testCases, n;
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    ILL(testCases);
//    DBG( testCases );
    FOR(a,1,1+testCases)
    {
        LL ans = 0;
        SegTree st(4*SIZE);
        cin >> n;
//        DBG( n );
        FOR(b,1,1+n)
        {
            LL li, ri, hi;
            ILL3(li, ri, hi);
            ri--;
//            DBG3(li, ri, hi);
            LL addee = st.update(1, 1, SIZE-4, li, ri, hi);
//            DBG( addee );

//            cout << "after update " << endl;
//            st.print( 2 * SIZE );

            ans += addee;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


