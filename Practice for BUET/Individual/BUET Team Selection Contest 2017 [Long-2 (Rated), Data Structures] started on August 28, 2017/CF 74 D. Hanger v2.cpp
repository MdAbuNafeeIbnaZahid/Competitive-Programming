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

set<LL> setLL;

/******   END OF HEADER *********/
#define SIZE 100009
LL n, q;
set< PairLL > sizeIndex, indexSize;
map<LL, LL> emHook;
ordered_set OS;
LL getHook()
{
    LL a, b, c,d, e;
    LL ret;
    set<PairLL>::iterator it = sizeIndex.end();
    it--;
    PairLL oldSi = *it;
    sizeIndex.erase( oldSi );
    indexSize.erase( MP(oldSi.second, oldSi.first) );
    ret = oldSi.second + oldSi.first/2;
    if ( oldSi.first == 1 )
    {
        return ret;
    }

    PairLL newSiL, newSiR;
    newSiL = MP(ret-oldSi.second, oldSi.second);
    if ( newSiL.first > 0 )
    {
        sizeIndex.insert( newSiL );
        indexSize.insert( MP(newSiL.second, newSiL.first) );
    }

    newSiR =  MP(oldSi.first+oldSi.second-1-ret, ret+1) ;
    if ( newSiR.first > 0 )
    {
        sizeIndex.insert( newSiR );
        indexSize.insert( MP(newSiR.second, newSiR.first) );
    }

    return ret;
}

void putHook(LL num)
{
    LL a, b, c, d, e, f;
    PairLL leftIs, rightIs, newIs;
    newIs = MP(num, 1);
    set<PairLL>::iterator it = indexSize.lower_bound( newIs );

    if ( it != indexSize.begin() )
    {
        it--;
        leftIs = *( it );
        if ( leftIs.first + leftIs.second == num )
        {
            indexSize.erase( leftIs );
            sizeIndex.erase( MP(leftIs.second, leftIs.first) );
            newIs = leftIs;
            newIs.second++;
        }
    }

    it = indexSize.upper_bound( newIs );
    if ( it != indexSize.end() )
    {
        rightIs = *it;
        if ( newIs.first+newIs.second == rightIs.first )
        {
            indexSize.erase( rightIs );
            sizeIndex.erase( MP(rightIs.second, rightIs.first) );
            newIs.second += rightIs.second;
        }
    }

    indexSize.insert( newIs );
    sizeIndex.insert( MP(newIs.second, newIs.first) );
}

void printOS(ordered_set toPr)
{
    LL a, b, c, d, e;
    LL siz = toPr.size();
    FOR(a,0,siz)
    {
        cout << *toPr.find_by_order( a ) << " ";
    }
    cout << endl;
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    ILL2(n, q);
//    DBG2(n, q);
    sizeIndex.insert( MP(n, 1) );
    indexSize.insert( MP(1, n) );

    FOR(a,1,1+q)
    {
//        DBG(a);
        LL typ;
        ILL(typ);
//        DBG2(a, typ);
        if ( typ == 0 )
        {
            LL i, j;
            ILL2(i, j);
//            DBG2(i, j);
            LL ans = OS.order_of_key(j+1) - OS.order_of_key(i);
            printf("%lld\n", ans);
        }
        else
        {
            if ( emHook[typ]==0 ) // get a slot
            {
//                cout << "before getting " << endl;
//                cout << "sizeIndex" << endl;
//                printSetPair( sizeIndex );
//                cout << "indexSize" << endl;
//                printSetPair( indexSize );
//                cout << "OS"  << endl;
//                printOS( OS );


                emHook[typ] = getHook();
//                DBG( emHook[typ] );
                OS.insert( emHook[typ] );


//                cout << "after getting " << endl;
//                cout << "sizeIndex" << endl;
//                printSetPair( sizeIndex );
//                cout << "indexSize" << endl;
//                printSetPair( indexSize );
//
//                cout << "OS"  << endl;
//                printOS( OS );


            }
            else // putting a slot
            {
//                cout << " before putting a slot" << endl;
//                cout << "sizeIndex" << endl;
//                printSetPair( sizeIndex );
//                cout << "indexSize" << endl;
//                printSetPair( indexSize );
//

                putHook( emHook[typ] );
                OS.erase( emHook[typ] );
                emHook[ typ ] = 0;

//                cout << " after putting a slot" << endl;
//                cout << "sizeIndex" << endl;
//                printSetPair( sizeIndex );
//                cout << "indexSize" << endl;
//                printSetPair( indexSize );

            }
        }
    }


    return 0;
}

