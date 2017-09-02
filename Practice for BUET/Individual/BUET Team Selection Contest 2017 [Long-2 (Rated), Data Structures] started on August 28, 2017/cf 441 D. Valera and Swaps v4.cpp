
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


PairLL mergePair(PairLL A, PairLL B)
{
    PairLL ret;
    vector<LL> vec;
    vec.push_back( A.first );
    vec.push_back( A.second );
    vec.push_back( B.first );
    vec.push_back( B.second );
    SORT( vec );
    ret = MP(vec[0], vec[1]);
    return ret;
}


struct DSU
{
    LL *parentAr, *countAr;
//    PairLL *pairAr;
    LL siz;
    DSU(LL siz)
    {
        LL a, b, c,d ;
        this->siz = siz;
        parentAr = new LL[siz+9];
        countAr = new LL[siz+9];
//        pairAr = new PairLL[siz+9];
        FOR(a,0,siz)
        {
            parentAr[a] = a;
            countAr[a] = 1;
//            pairAr[a].first = a;
//            pairAr[a].second = INT_MAX;
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
        if (u<v)
        {
            swap(u, v);
        }
        // now v <= u
        if ( getParent(u) == getParent(v) )
        {
            return ;
        }
        // v will reign
        countAr[ getParent(v) ] += countAr[ getParent(u) ];
//        pairAr[ getParent(v) ] = mergePair( pairAr[getParent(u)], pairAr[getParent(v)] );
        parentAr[ getParent(u) ] = getParent( v );
    }
    LL getCount( LL u )
    {
        return countAr[ getParent(u) ];
    }
//    PairLL getPair(LL u)
//    {
//        return pairAr[ getParent(u) ];
//    }
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
#define SIZE 3009
LL n, pAr[SIZE], m;
LL valToIdx[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    cin >> n;
    FOR(a,1,1+n)
    {
        ILL( pAr[a] );
    }
    cin >> m;

    DSU dfu(SIZE);
    FOR(a,1,1+n)
    {
        dfu.makePair(a, pAr[a]);
    }
    LL swapPresent = 0;
    set<LL> headSet;
    FOR(a,1,1+n)
    {
        LL head = dfu.getParent( a );
        if ( headSet.find( head ) == headSet.end() )
        {
            swapPresent += dfu.getCount( a )-1;
            headSet.insert( head );
        }
    }
    cout << abs( swapPresent-m ) << endl;

    for (long long x = 0; ;x++)
    {
//        FOR(a,1,1+n)
//        {
//            valToIdx[ pAr[a] ] = a;
//        }
        DSU dfu(SIZE);
        FOR(a,1,1+n)
        {
            dfu.makePair(a, pAr[a]);
        }
//        LL swapPresent = 0;
//        set<LL> headSet;
//        FOR(a,1,1+n)
//        {
//            LL head = dfu.getParent( a );
//            if ( headSet.find( head ) == headSet.end() )
//            {
//                swapPresent += dfu.getCount( a )-1;
//                headSet.insert( head );
//            }
//        }
//        LL swapNeeded = (m-swapPresent);
//        if (x==0)
//        {
//            cout << abs(swapNeeded) << endl;
//        }


        LL i, j;
        if ( swapPresent < m ) // we need to merge two circles
        {
            FOR(a,2,1+n)
            {
                if ( dfu.getParent(1) != dfu.getParent(a) )
                {
                    i = 1;
                    j = a;
                    break;
                }
            }
            swapPresent++;
        }
        else if ( swapPresent == m)
        {
            break;
        }
        else if ( swapPresent > m) // we need to break a circle
        {
            FOR(a,1,1+n)
            {
                if ( dfu.getCount(a) > 1 )
                {
                    i = a;
                    FOR(b,a+1,1+n)
                    {
                        if ( dfu.getParent(b) == dfu.getParent(a)  )
                        {
                            j = b;
                            break;
                        }
                    }
                    break;
                }
            }
            swapPresent--;
        }

        if (i>j)
        {
            swap(i, j);
        }
        // now i <= j
        printf("%lld %lld ", i, j);
        swap( pAr[ i ], pAr[ j ] );
    }
    return 0;
}



