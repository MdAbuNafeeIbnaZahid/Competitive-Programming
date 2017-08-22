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


/******   END OF HEADER *********/
#define SIZE 1000009
#define MOD 1000000007
LL n, aAr[SIZE];
LL cntAr[SIZE];
LL sivAr[SIZE], mobiusAr[SIZE], kAr[SIZE], pow2[SIZE];
LL mulCntAr[SIZE];
LL ans;
void sivAndMob()
{
    LL a, b, c, d, e, f;
    FOR(a,1,SIZE)
    {
        sivAr[a] = a;
        mobiusAr[a] = 1;
    }
    FOR(a,2,SIZE)
    {
        if ( sivAr[a] == a )
        {
            for (b = 1; b*a < SIZE ; b++)
            {
                LL next = b*a;
                if ( next % (a*a) == 0 )
                {
                    mobiusAr[next] = 0;
                }
                mobiusAr[ next ] *= -1;
                sivAr[ next ] = a;
            }
        }
    }
}

void calcPow2()
{
    LL a, b, c, d, e, f;
    pow2[0] = 1;
    FOR(a,1,SIZE)
    {
        pow2[a] = (pow2[a-1] << 1LL) % MOD;
    }
}

void calcKAr()
{
    LL a, b, c, d, e, f, g;
    kAr[0] = 0;
    FOR(a,1,SIZE)
    {
        kAr[a] = ( (kAr[a-1] << 1LL) % MOD + pow2[a-1] ) % MOD;
    }
}



int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f, g;
    calcPow2();
//    FOR(a,0,11)
//    {
//        DBG(a);
//        DBG( pow2[a] );
//    }
    sivAndMob();
//    FOR(a,1,30)
//    {
//        DBG( a );
//        DBG( mobiusAr[a] );
//    }
    calcKAr();
//    FOR( a, 0, 10 )
//    {
//        DBG(a);
//        DBG( kAr[a]  );
//    }
    cin >> n;
    FOR(a,1,1+n)
    {
        LL ai;
        scanf("%lld", &ai);
        cntAr[ ai ]++;
    }
    FOR(a,1,SIZE)
    {
        for (b = a; b < SIZE; b+=a)
        {
            mulCntAr[a] += cntAr[ b ];
        }
    }


//    FOR(a,1,5)
//    {
//        DBG( a );
//        DBG( mulCntAr[a] );
//    }


    FOR(a,2,SIZE)
    {
        LL ansAddee = 0;
        LL tempKSum = 0;
        LL gcd = a;
        for (b = 1; b*gcd < SIZE; b ++)
        {
            tempKSum = ( ( kAr[ mulCntAr[b*gcd] ] * mobiusAr[b] + MOD )%MOD + tempKSum ) % MOD;
        }
        ansAddee = ( tempKSum * gcd ) % MOD;
        ans =  (ans + ansAddee) %MOD;
    }
    cout << ans;
    return 0;
}

