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

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

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


void printLL2dAr(LL **ar, LL u, LL v, LL x, LL y)
{
    LL a, b, c, d, e, f;
    cout << endl ;
    FOR(a,u,x+1)
    {
        FOR(b,v,y+1)
        {
            cout << *( *(ar+a) + b ) << " ";
        }
        cout << endl;
    }
}



LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};




/******   END OF HEADER *********/
#define SIZE 109
#define MAXCOIN 100009
#define MOD 1000000009
LL T, N, Q, M;
vector<LL> vecNum, vecNumMod;
LL ncrAr[SIZE][SIZE], coinModCntAr[SIZE];
LL factorialAr[MAXCOIN];
LL invFactorialAr[MAXCOIN];
LL ways[SIZE];

LL ans;

LL getPow(LL n, LL r)
{
    LL ret = 1;
    if ( r == 0 )
    {
        return 1;
    }
    LL half = getPow(n, r/2);
    ret = (half * half) % MOD;
    if ( r & 1 )
    {
        ret = (ret*n) % MOD;
    }
    return ret;
}

LL getModInverse(LL num)
{
    return getPow(num, MOD-2) % MOD;
}

void calcFactorial()
{
    LL a, b, c, d, e, f;
    factorialAr[0] = 1;
    invFactorialAr[0] = 1;
    FOR(a,1,MAXCOIN)
    {
        factorialAr[a] = (factorialAr[a-1] * a) % MOD;
        invFactorialAr[a] = ( invFactorialAr[a-1] * getModInverse(a) ) % MOD;
    }
}

LL getNcr(LL n, LL r)
{
//    cout << "in getNcr " << endl;
//    DBG( factorialAr[n] );
//    DBG( invFactorialAr[r] );
//    DBG( invFactorialAr[n-r] );
    LL ret = ( factorialAr[n] * invFactorialAr[r] ) % MOD;
    ret = ( ret * invFactorialAr[n-r] ) % MOD;
    return ret;
}

void calcNcrAr()
{
    LL a, b, c, d, e, f;
    FOR(a,0,SIZE)
    {
        ncrAr[a][0] = 1;
        ncrAr[a][a] = 1;
    }
    FOR(a,1,SIZE)
    {
        FOR(b,1,a)
        {
            ncrAr[a][b] =  ( ncrAr[a-1][b-1] + ncrAr[a-1][b] ) % MOD;
        }
    }
}

void calcCoinModCntAr()
{
    LL a, b, c, d, e;
    vector<LL> ret;
    for ( auto it : vecNum )
    {
        ret.push_back( it % M );
        LL val = ((it%M)+M)%M;
        if ( val == 0 )
        {
            coinModCntAr[ M ]++;
            continue;
        }
        coinModCntAr[ val ]++;
    }
}


LL dp[SIZE][SIZE];

void printDp()
{
    LL a, b, c, d, e, f;
    FOR(a,0,1+M)
    {
        FOR(b,0,M)
        {
            cout << dp[a][b] << " ";
        }
        cout << endl;
    }
}

int main()
{
//    cout << -10 % 6;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f, g;
    calcNcrAr();
    calcFactorial();
    cin >> T;
//    DBG(T);
    FOR(a,1,1+T)
    {
        cin >> N >> Q;
//        DBG(N);
//        DBG(Q);
        vecNum = vector<LL>();
        FOR(b,1,1+N)
        {
            LL num;
            scanf("%lld", &num);
            vecNum.push_back( num );
        }
        FOR(g,1,1+Q)
        {
            scanf("%lld", &M);
//            DBG(M);
            RESET( coinModCntAr );
            calcCoinModCntAr();
//            printLLArray( coinModCntAr, 0, M+1 );
            FOR(b,0,SIZE)
            {
                FOR(c,0,SIZE)
                {
                    dp[b][c] = 0;
                }
            }
            dp[0][0] = 1;
            FOR(b,1,1+M)
            {
//                DBG(b);
                RESET(ways);
                FOR(c,1,1+coinModCntAr[b] )
                {
                    LL target = (c*b)%M;
                    ways[target] = ( ways[target] + getNcr(coinModCntAr[b], c) )%MOD;
                }



                FOR(c,0,M)
                {
//                    DBG(c);
                    dp[b][c] = dp[b-1][c];
                    FOR(d,0,M )
                    {
//                        DBG( d );
//                        printDp();
//                        printLL2dAr(dp, 0, 0, M, M);
//                        LL target = ( (c - d*b)%M + M )%M;
////                        DBG( target );
//                        LL ncrVal = getNcr(coinModCntAr[b], d);
////                        DBG( ncrVal );
                        LL addee = ( dp[b-1][ (c-d+M)%M ] * ways[d] )%MOD;
//                        DBG( addee );
                        dp[b][c] = ( addee + dp[b][c] ) % MOD;
//                        printDp();
                    }
                }
            }
            LL ans = dp[M][0];
            printf("%lld\n", ans);
        }

    }
    return 0;
}



