
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




/******   END OF HEADER *********/
#define SIZE 5009
#define MOD 1000000007


LL len;
char str[SIZE];

LL hashValAr[SIZE], spp[SIZE], sppI[SIZE];
LL powMod[SIZE];
//bool isPalin[SIZE][SIZE];
//bool dp[2][SIZE][SIZE];
//map<LL,PairLL > hashToStr;

void buildPowAr()
{
    LL a, b, c, d, e, f;
    spp[0] = SPRIME;
    sppI[0] = bigMod(SPRIME, BPRIME-2, BPRIME);
    FOR(a,1,SIZE)
    {
        spp[a] = ( spp[a-1] * spp[0] ) % BPRIME;
        sppI[a] = ( sppI[a-1] * sppI[0] ) % BPRIME;
    }
}

void buildHash()
{
    LL a, b, c, d, e, f;
    FOR(a,1,1+len)
    {
        hashValAr[a] = ( hashValAr[a-1] + ( str[a] * spp[a-1])%BPRIME ) % BPRIME;
    }
}

LL getRangeHashVal(LL u, LL v)
{
    return ( sppI[u] * ( ( hashValAr[v] - hashValAr[u-1] + BPRIME )%BPRIME ) ) % BPRIME;
}

//void buildIsPalin()
//{
//    LL a, b, c, d, e, f;
//    FOR(a,0,len)
//    {
//        FOR(b,1,1+len)
//        {
//            if ( b+a > len )
//            {
//                break;
//            }
//            if ( a <= 1 )
//            {
//                isPalin[ b ][ b+a ] = (str[b]==str[b+a]);
//            }
//            else
//            {
//                isPalin[b][ b+a ] = ( isPalin[b+1][b+a-1] && str[b]==str[b+a] );
//            }
//        }
//    }
//}

LL ansAr[SIZE];
LL toPrAr[SIZE];


LL isPrime(LL num)
{
    LL a, b, c, e, f;
    for (a = 2; a*a <= num; a++)
    {
        if ( num % a == 0 )
        {
            return false;
        }
    }
    return true;
}



LL dp2[SIZE][SIZE];


void printDp2()
{
    LL a, b, c, d, e, f;
    FOR(a,1,1+len)
    {
        FOR(b,1,1+len)
        {
            cout << dp2[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void buildDp2()
{
    LL a, b, c, d, e, f;
    FOR(a,0,len)
    {
        FOR(b,1,1+len)
        {
            if (b+a>len)
            {
                break;
            }


            if (a==0)
            {
                dp2[b][b+a] = 1;
            }
            else
            {
                LL d1, d2;
                d1 = b+(a-1)/2;
                d2 = d1+1+(! ( a&1) );

                if ( dp2[b+1][b+a-1] && str[b]==str[b+a] )
                {
                    dp2[b][b+a] = 1;
                }

                if ( dp2[b][d1] && dp2[d2][b+a] && dp2[b][d1]==dp2[d2][b+a]
                && getRangeHashVal(b,d1)==getRangeHashVal(d2,b+a) )
                {
                    dp2[b][b+a] = dp2[b][d1]+1;
                }
            }
        }
    }
}

int main()
{
//    cout << 1 << endl;
//    DBG( isPrime(10007) );
//    DBG( isPrime(1000000007) );
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f, g;
    scanf("%s", str+1);
    len = strlen( str+1 );







    powMod[0] = 1;
    FOR(a,1,SIZE)
    {
        powMod[a] = powMod[a-1] * MOD;
    }
    buildPowAr();
    buildHash();



    buildDp2();




    FOR(a,1,1+len)
    {
        FOR(b,a,1+len)
        {
            ansAr[ dp2[a][b] ]++;
        }
    }

//    printDp2();


    LL toPr = 0;
    ROF(a,len, 0)
    {
        ansAr[a] += ansAr[ a+1 ];
    }

    FOR(a,1,1+len)
    {
        printf("%lld ", ansAr[a]);
    }
    return 0;



//    FOR(a,1,1+len)
//    {
//        FOR(b,a,1+len)
//        {
//            DBG3(a, b, getRangeHashVal(a, b) );
//        }
//    }


//    buildIsPalin();
////    cout << "hash, palin ar built" << endl;
//
//
//
//
//
//
//    FOR(a,1,1+len)
//    {
//        FOR(b,a,1+len)
//        {
//            if ( isPalin[a][b] )
//            {
////                DBG2(a,b);
//                dp[1][a][b] = true;
//                LL x = 1;
////                toPrAr[x]++;
//                ansAr[1] = ansAr[1]+1;
//            }
//        }
//    }
//    FOR(g,2,14)
//    {
////        cout << endl << endl << endl;
////        DBG(g);
//        RESET( dp[g&1] );
//        FOR(a,1,1+len)
//        {
//            FOR(b,a,1+len)
//            {
////                DBG2(a, b);
//
//
//                LL ai, bi;
//                if ( (a+b) & 1 )
//                {
//                    ai = (a+b)/2;
//                    bi = ai+1;
//                }
//                else
//                {
//                    ai = (a+b)/2 - 1;
//                    bi = ai+2;
//                }
//
////                DBG2(ai, bi);
////                DBG( dp[ (g-1)&1 ][ a ][ai] );
////                DBG( dp[ (g-1)&1 ][ bi ][b] );
////                DBG( getRangeHashVal(a,ai) );
////                DBG( getRangeHashVal(bi,b) );
//
//                if ( dp[ (g-1)&1 ][ a ][ai] && dp[ (g-1)&1 ][ bi ][b] &&
////                    hashValAr[a][ai]==hashValAr[bi][b]
//                    getRangeHashVal(a,ai)==getRangeHashVal(bi,b)
//                    )
//                {
////                    DBG2(a, b);
//                    dp[g&1][a][b] = true;
//                    ansAr[g]++;
//                }
//            }
//        }
//    }
//    FOR(a,1,1+len)
//    {
////        printf("%lld ", ansAr[a]);//                    DBG2(a, b);
//
////        LL ans = 0;
////        if ( a <= 16 )
////        {
////            FOR(b,1,1+len)
////            {
////                FOR(c,b,1+len)
////                {
////                    ans += dp[a][b][c];
////                }
////            }
////        }
//        printf("%lld ", ansAr[a]);
//    }
//
//    return 0;
}




