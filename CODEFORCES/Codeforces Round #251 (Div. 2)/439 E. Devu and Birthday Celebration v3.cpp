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
#define MK              make_pair
#define PB				push_back

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


/******   END OF HEADER *********/

#define SIZE 100009
#define MOD 1000000007

LL factorialAr[SIZE], mobiusAr[SIZE], prime[SIZE], sivAr[SIZE];
vector<LL> factorVecAr[SIZE], primeFactorVecAr[SIZE];
map< PairLL, LL > bigModMap;
void sivAndMob()
{
    LL a, b, c, d, e;
    for (a = 1; a < SIZE; a++)
    {
        sivAr[a] = a;
        mobiusAr[a] = 1;
    }
    for (b = 2; b < SIZE; b++)
    {
        if ( sivAr[b] != b )
        {
            continue;
        }
        for (c = b; c < SIZE; c+=b)
        {
            primeFactorVecAr[c].PB( b );
            sivAr[c] = b;
            mobiusAr[c] *= -1;
            if ( c % (b*b) == 0 )
            {
                mobiusAr[c] = 0;
            }
        }
    }
}


vector<LL> getSqFreeFactors(LL num)
{
    LL a, b, c, d, e;
    vector<LL> ret;
    for ( a = 0; a < ( 1LL << primeFactorVecAr[num].size() ); a++ )
    {
        LL toP = 1;
        for (b= 0; b < primeFactorVecAr[num].size(); b++)
        {
            if ( (a>>b) & 1 )
            {
                toP *= primeFactorVecAr[num][ b ];
            }
        }
        ret.PB(toP);
    }
    return ret;
}

void makeFactorialAr()
{
    LL a, b, c, d;
    factorialAr[0] = 1;
    for (a= 1; a < SIZE; a++)
    {
        factorialAr[a] = (factorialAr[a-1] * a ) % MOD;
    }
}

LL bigMod(LL a, LL b, LL M)
{
    LL ret;
    if ( bigModMap.find( MK(a,b) ) == bigModMap.end() )
    {
        if ( b == 0 )
        {
            ret = 1%M;
        }
        else
        {
            LL x = bigMod(a, b/2, M);
            x = (x*x) % M;
            if (b & 1)
            {
                x = (x * a) % M;
            }
            ret = x;
        }


        bigModMap[ MK(a,b) ] = ret;
    }
    return bigModMap[ MK(a,b) ];

}

LL inv(LL b, LL M)
{
    return bigMod(b, M-2, M);
}

LL getNcr(LL n, LL r)
{
//    cout << " in getNcr " << endl;
//    DBG(n);
//    DBG(r);
    if (n < r)
    {
        return 0;
    }
    LL ret = factorialAr[ n ];
//    DBG(ret);
    ret = ( ret * inv( factorialAr[r], MOD ) ) % MOD;
//    DBG(ret);
    ret = ( ret * inv( factorialAr[n-r], MOD ) ) % MOD;
    return ret;
}
LL q, n, f;
vector<LL> getAllFactor(LL num)
{
    vector<LL> ret;
    LL a, b, c, d, sqrtVal = (sqrt(num+1));
    for (a=1; a <= sqrtVal; a++ )
    {
        if ( num % a == 0 )
        {
            ret.push_back( a );
            if ( a != (num/a) )
            {
                ret.push_back( num / a );
            }
        }
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    makeFactorialAr();
    sivAndMob();
    LL a, b, c, d, e;
//    cout << getNcr(1, 0) << endl;
//    cout << getNcr(2, 0) << endl;
//    cout << getNcr(3, 0) << endl;
//    cout << getNcr(4, 0) << endl;

    cin >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld %lld", &n, &f);
//        DBG(n);
//        DBG(f);
        vector<LL> allSqFreeFactor = getSqFreeFactors(n);
//        printVecLL( allSqFreeFactor );
        LL ans = 0;
        for (b = 0; b < allSqFreeFactor.size(); b++)
        {
            LL curFactor = allSqFreeFactor[b];
//            DBG(curFactor);
            if ( mobiusAr[curFactor]==0 || ( (n/curFactor-1) < (f-1) ) )
            {
                continue;
            }
            LL addee = ( mobiusAr[curFactor] * getNcr( n/curFactor-1, f-1 ) + MOD ) % MOD;
//            DBG(addee);
            ans = (ans + addee) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


