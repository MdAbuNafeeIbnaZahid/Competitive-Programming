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
#define SIZE 1000009

// x = delete
// y = increase
LL n, x, y;
LL aAr[SIZE];

LL sivAr[SIZE*2], insCntAr[SIZE], cumInsCntAr[2*SIZE], cumSumAr[2*SIZE];

LL ans = LLMAX;

void buildSivAr()
{
    LL a, b, c, d, e, f;
    FOR(a,2,SIZE)
    {
        sivAr[a] = a;
    }
    FOR(a,2,SIZE)
    {
        if ( sivAr[a] == a )
        {
            for (b = a*a; b < SIZE; b+=a)
            {
                sivAr[b] = a;
            }
        }
    }
}

LL calcCost(LL num, LL div)
{
    LL target = ( (num+div-1) / div ) * div;
    return y*( target-num );
}


LL calcFullCost(LL div)
{
    LL a, b, c, d, e;
    LL minIncCost, minIncIdx = 1;
    minIncCost = calcCost( aAr[1], div );
    FOR(a,2,1+n)
    {
        if ( calcCost( aAr[a], div ) < minIncCost )
        {
            minIncCost = calcCost( aAr[a], div );
            minIncIdx = a;
        }
    }
    LL ret = minIncCost;
    FOR(a,1,1+n)
    {
        if ( a==minIncIdx )
        {
            continue;
        }
        LL addee = min( x, calcCost(aAr[a], div) );
        ret += addee;
    }
    return ret;
}


LL getClosestDis(LL pri, LL mul)
{
    LL lowerVal = pri*(mul-1)+1;
    LL upperVal = pri * mul;
    while ( lowerVal < upperVal )
    {
        LL midVal = (lowerVal+upperVal+1) / 2;
        if ( cumInsCntAr[pri*mul] - cumInsCntAr[midVal-1] > 0 )
        {
            lowerVal = midVal;
        }
        else
        {
            upperVal = midVal - 1;
        }
    }
    return upperVal;
}


LL solve()
{
//    cout << "in solve " << endl;
    LL a, b, c, d, e, f;
    LL ret = LLMAX;
    LL i = x/y;
//    DBG( i );
    FOR(a,1,SIZE)
    {
        sivAr[a] = a;
    }
    FOR(a,2,SIZE)
    {
        if ( sivAr[a]==a )
        {
//            cout << a <<  " is a prime " << endl;
            LL posRet = 0, setSize= 0;
            for (b = a; b < ( SIZE<<1LL); b+=a)
            {
//                DBG( b );
                sivAr[b] = a;

                LL addee = 0;
                LL setAddee = cumInsCntAr[ b ] - cumInsCntAr[ max(b-i-1, b-a) ];

//                DBG( setAddee );

                setSize += setAddee;

//                DBG( cumSumAr[b] );
//                DBG( cumSumAr )

                addee += ( setAddee*b - cumSumAr[b] + cumSumAr[max(b-i-1, b-a)] ) * y;
//                DBG( addee );



                LL vanishCnt = (cumInsCntAr[b]-cumInsCntAr[b-a]-setAddee);
//                DBG( vanishCnt );

                addee += vanishCnt * x;
//                DBG( addee );

                posRet += addee;
//                DBG( posRet );
            }

//            DBG( setSize );

//            LL minDis = a-1;
//            if ( setSize <= 0 )
//            {
//                for (b = a; b < (SIZE<<1LL); b+=a)
//                {
//                    if ( cumInsCntAr[b] - cumInsCntAr[b-a] > 0 )
//                    {
//                        minDis = min(minDis, b-getClosestDis(a, b/a) );
//                    }
//                }
//
//                posRet -= x;
//                posRet += minDis * y;
//
//            }

//            DBG( posRet );

            ret = min(posRet, ret);
        }
    }
    return ret;
}



int main()
{
//        cout << LLMAX << endl;

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);


    LL a, b, c, d, e, f;
    cin >> n >> x >> y;
//    DBG3(n, x, y);
//    buildSivAr();
    FOR(a,1,1+n)
    {
//        ILL( aAr[a] );
        cin >> aAr[a];
        insCntAr[ aAr[a] ]++;
    }

//    cout << "insCntAr " << endl;
//    printLLArray(insCntAr, 1, SIZE-1);

    FOR(a,1,SIZE)
    {
        cumInsCntAr[a] = cumInsCntAr[a-1] + insCntAr[a];
        cumSumAr[a] = cumSumAr[a-1] + insCntAr[a] * a;
    }




    FOR(a,SIZE,SIZE<<1LL)
    {
        cumInsCntAr[a] = cumInsCntAr[a-1];
        cumSumAr[a] = cumSumAr[a-1] ;
    }

//    cout << "cumInsCntAr " << endl;
//    printLLArray( cumInsCntAr, 1, 2*SIZE-1 );
//
//    cout << "cumSumAr " << endl;
//    printLLArray( cumSumAr, 1, 2*SIZE-1 );


    LL ans = solve();
    cout << ans;

    return 0;
}




