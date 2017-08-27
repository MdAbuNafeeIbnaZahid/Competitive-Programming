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
#define BPRIME2 1000000009


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

LL isPrime(LL num)
{
    LL a, b, c, d, e, f;
    for (a = 2; a*a <= num; a++)
    {
        if ( num % a==0 )
        {
            return 0;
        }
    }
    return 1;
}





/******   END OF HEADER *********/
#define SIZE 250009
char firStr[SIZE], secStr[SIZE];
LL firLen, secLen, ans;

LL powSprime[SIZE], invPowSprime[SIZE];
LL powSprime2[SIZE], invPowSprime2[SIZE];

PairLL firHashValAr[SIZE], secHashValAr[SIZE];


struct myHashTable
{
    LL siz;
    set<PairLL> *ar;
    myHashTable(LL siz)
    {
        this->siz = siz;
        ar = new set<PairLL>[siz];
    }
    void myInsert(PairLL p)
    {
        LL a, b, c,d,e;
        LL hashVal = ( ( (p.first ^ p.second)%siz ) + siz )%siz;
        ar[ hashVal ].insert( p );
    }
    bool myFind( PairLL p )
    {
        LL a, b, c,d,e;
        LL hashVal = ( ( (p.first ^ p.second)%siz ) + siz )%siz;
        return ( ar[hashVal].find(p) != ar[hashVal].end() );
    }
};


void buildPowSprime(LL *powAr, LL *invPowAr, LL sp, LL bp)
{
    LL a, b, c, d, e, f;

    powAr[0] = 1;
    invPowAr[ 0 ] = 1;

    powAr[1] = sp % bp;
    invPowAr[1] = bigMod(sp, bp-2, bp);
    FOR( a,2,SIZE )
    {
        powAr[a] = (powAr[a-1] * powAr[1] ) % bp;
        invPowAr[a] = (invPowAr[a-1] * invPowAr[1]) % bp;
    }
}


void buildHashValAr(PairLL *hashAr, char *str)
{
    // 1 based string index
    LL a, b, c, d, e, f;
    LL len = strlen( str+1 );
    FOR(a,1,1+len)
    {
        hashAr[a].first = (hashAr[a-1].first + ( str[a]*powSprime[a] )%BPRIME )%BPRIME;
        hashAr[a].second = (hashAr[a-1].second + ( str[a]*powSprime2[a] )%BPRIME2 )%BPRIME2;
    }
}

PairLL getRangeHash(LL star, LL en, PairLL *hashAr)
{
    LL a, b, c, d, e, f;
    PairLL ret;

    ret.first = (hashAr[en].first - hashAr[star-1].first + BPRIME ) % BPRIME;
    ret.first = ( ret.first * invPowSprime[star-1] ) % BPRIME;

    ret.second = (hashAr[en].second - hashAr[star-1].second + BPRIME2 ) % BPRIME2;
    ret.second = ( ret.second * invPowSprime2[star-1] ) % BPRIME2;

    return ret;
}

// returns the matching index (1 based)
// if no match return 0
LL isMatch( LL matchLen )
{
    LL a, b, c, d, e, f;
    if ( matchLen == 0 )
    {
        return 1;
    }
    LL ret = 0;
    myHashTable hashSet(SIZE);
    FOR(a,1,1+firLen)
    {
        LL ei = a+matchLen-1;
        if ( ei > firLen )
        {
            break;
        }
        PairLL pairVal = getRangeHash( a, ei, firHashValAr );
        hashSet.myInsert( pairVal );
    }
    FOR(a,1,1+secLen)
    {
        LL ei = a+matchLen-1;
        if ( ei > secLen )
        {
            break;
        }
        PairLL pairVal = getRangeHash( a, ei, secHashValAr );
        if ( hashSet.myFind( pairVal ) )
        {
            return a;
        }
    }
    return 0;
}

LL binSearch(LL lowVal, LL highVal)
{
    LL a, b, c, d, e, f;
    if ( lowVal >= highVal )
    {
        return lowVal;
    }
    LL midVal = (lowVal+highVal+1)/2;

    if ( isMatch(midVal) )
    {
        return binSearch( midVal, highVal );
    }
    else
    {
        return binSearch( lowVal, midVal-1 );
    }
}

int main()
{
//    cout << isPrime( BPRIME2 ) << endl;
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    scanf("%s", firStr+1);
    scanf("%s", secStr+1);
    firLen = strlen( firStr+1 );
    secLen = strlen( secStr+1 );
    buildPowSprime(powSprime, invPowSprime, SPRIME, BPRIME);
    buildPowSprime(powSprime2, invPowSprime2, SPRIME, BPRIME2);


    buildHashValAr(firHashValAr, firStr);
    buildHashValAr(secHashValAr, secStr);


    LL maxMatch = binSearch( 0, min( firLen, secLen ) );
    if ( maxMatch == 0 )
    {
        cout << 0;
        return 0;
    }

    LL secIdx = isMatch( maxMatch );
    FOR(a,secIdx,secIdx+maxMatch)
    {
        printf("%c", secStr[a] );
    }
    cout << endl;
    cout << maxMatch << endl;



    return 0;
}



