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
#define PB				push_back

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)

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
#define SIZE 1009
#define MOD 1000000007

    // M-K   N-M
LL dp[SIZE][SIZE], ncr[SIZE][SIZE];
LL T, N, M, K;

void calcDp()
{
    LL a, b, c, d, e, f;
    dp[0][0] = 1;
    FOR(a,1,SIZE-1)
    {
        dp[0][a] = ( a*dp[0][a-1] ) % MOD;
    }
    LL si = 1;
    FOR(a,1,SIZE-1)
    {
        si *= -1;
        dp[a][0] = ( a*dp[a-1][0] + si + MOD ) % MOD;
    }
    FOR(a,1,SIZE-1)
    {
        dp[1][a] = (dp[0][a] * a ) % MOD;
    }
    FOR(a,2,SIZE-1) // M-K
    {
        FOR(b,1,SIZE-1) // N-M
        {
            dp[a][b] = ( (a-1) * dp[a-2][b] ) % MOD;
            dp[a][b] = ( dp[a][b] + ( (a+b-1)*dp[a-1][b] ) % MOD ) % MOD;
//            dp[a][b] = ( dp[a][b] + b*dp[a-][b] )
        }
    }
}

void calcNcr()
{
    LL a, b, c, d, e, f;
    FOR(a,0,SIZE-1)
    {
        ncr[a][a] = 1;
    }
    FOR(a,0,SIZE-1)
    {
        ncr[a][0] = 1;
    }
    FOR(a,1,SIZE-1)  // n
    {
        FOR(b,1,SIZE-1)  // r
        {
            ncr[a][b] = (ncr[a-1][b] + ncr[a-1][b-1] ) % MOD;
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    calcDp();
    calcNcr();
    cin >> T;
    FOR(a,1,T)
    {
        scanf("%lld %lld %lld", &N, &M, &K);
        LL ans = ( ncr[M][K] * dp[M-K][N-M] ) % MOD;
        printf("Case %lld: %lld\n", a, ans);
    }
    return 0;
}
