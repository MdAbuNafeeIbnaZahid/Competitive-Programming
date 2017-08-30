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

//
//void printVecLL(vector<LL> vecToPr)
//{
//    LL a, b, c, d, e;
//    for ( a= 0; a < vecToPr.size(); a++)
//    {
//        printf("%lld ", vecToPr[a]);
//    }
//    printf("\n");
//}
//
//
//void printMapLLLL( map<LL, LL> mapToPr )
//{
//    LL a, b, c, d, e;
//    map<LL, LL>::iterator mapIt;
//    cout << endl;
//    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
//    {
//        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
//    }
//    cout << endl;
//}
//
//
//void printLLArray( LL *ar, LL si, LL ei )
//{
//    LL a, b, c, d, e;
//    FOR(a, si, ei+1)
//    {
//        printf("ar[ %lld ] = %lld\n\n", a, ar[a]);
//    }
//}
//
//
//void  printSetPair( set<PairLL> givenSetPair )
//{
//    for ( auto it : givenSetPair )
//    {
//        cout << "(" << it.first << ", " << it.second << ")" << endl;
//    }
//    cout << endl;
//}
//
//void printVecPair( vector<PairLL> givenVecPair )
//{
//    for ( auto it : givenVecPair )
//    {
//        cout << "(" << it.first << ", " << it.second << ")" << endl;
//    }
//    cout << endl;
//}



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
//        DBG(siz );
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



/******   END OF HEADER *********/
#define SIZE 1009

struct twoDBIT
{
    LL siz;
    vector<BIT> vecBit;
    twoDBIT(LL siz)
    {
        LL a, b, c, d, e;
        this->siz = siz;
        vecBit.resize( siz+9 );
        FOR(a,0,siz+9)
        {
            vecBit[a] = BIT(siz+9);
        }
    }
    void print()
    {
        LL a, b, c, d, e;
        FOR(a,1,1+siz)
        {
            DBG(a);
            FOR(b,1,1+siz)
            {
                cout << vecBit[a].treeAr[b] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    LL read(LL u, LL v)
    {
        LL sum = 0;
        while(u > 0)
        {
            sum += vecBit[u].read(v);
            u -= (u & -u);
        }
        return sum;
    }
    void update(LL u, LL v, LL val)
    {
//        cout << "in update of twoDBIT " << endl;
        while(u <= siz)
        {
//            DBG(u);
            vecBit[u].update(v, val);
            u += (u & -u);
        }
    }

    LL getRectSum(LL u, LL v, LL x, LL y)
    {
//        cout << "in getRectSum " << endl;
//        DBG4(u, v, x, y);
//        DBG( read(x, y) );
//        DBG( read(u-1, y) );
//        DBG( read(x, v-1) );
//        DBG( read(u-1, v-1) );
        LL ret = 0;
        ret = read(x,y) - read(u-1, y) - read(x, v-1) + read(u-1,v-1);
        return ret;
    }
};
LL T, q;
int trAr[SIZE+9][SIZE+9];
bool trBool[SIZE][SIZE];

LL read(LL u, LL v)
{
    LL a, b, c, d, e, f;
    LL ret = 0;
    while( u > 0 )
    {
        LL copV = v;
        LL addee = 0;
        while( copV > 0 )
        {
            addee += trAr[u][copV];
            copV -= (copV & -copV);
        }
        ret += addee;
        u -= (u & -u);
    }
    return ret;
}


LL update(LL u, LL v, LL val)
{
    while( u < SIZE )
    {
        LL copV = v;
        while( copV < SIZE )
        {
            trAr[u][copV] += val;
            copV += (copV & -copV);
        }
        u += (u & -u);
    }
}


LL getRectSum(LL u, LL v, LL x, LL y)
{
    LL ret = read(x,y) - read(u-1,y) - read(x,v-1) + read(u-1,v-1);
    return ret;
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
//    twoDBIT td(5);
//    FOR(a,1,1+5)
//    {
//        DBG(td.vecBit[a].siz );
//    }
//    LL checkAr[SIZE];
//    RESET(checkAr);
//    BIT bit(SIZE);
//    while( 1 )
//    {
//
//    }
    cin >> T;
    FOR(a,1,1+T)
    {
        cout << "Case " << a << ":" << endl;
//        twoDBIT td(SIZE);
//        set<PairLL> setP;
        RESET( trAr );
        RESET( trBool );
        cin >> q;
//        DBG(q);
        FOR(b,1,1+q)
        {
//            DBG(b);
            LL typ;
            ILL(typ);
//            DBG2(b, typ);
            LL u, v, x, y;
            if ( typ == 0 )
            {
                ILL2(u, v);
                u += 3;
                v += 3;
//                DBG2(u, v);
//                if ( setP.find( MP(u, v) ) != setP.end() )
//                {
//                    continue;
//                }
////                cout << "not inserted before" << endl;
//                setP.insert( MP(u, v) );

//                cout << "before update" << endl;
//                td.print();
                if ( trBool[u][v] )
                {
                    continue;
                }
                trBool[u][v] = true;
                update(u, v, 1);
//                cout << "after update" << endl;
//                td.print();
            }
            else
            {
                ILL4(u, v, x, y);
                u += 3;
                v += 3;
                x += 3;
                y += 3;
//                DBG4(u, v, x, y);
                LL ans = getRectSum(u, v, x, y);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}


