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



/******   END OF HEADER *********/
#define SIZE 3609
LL dp[9][209][SIZE];
LL n, k;
LL twoCntAr[SIZE], fiveCntAr[SIZE];
LL ans;
void calcDp()
{
    LL a, b, c, d, e, f;
    FOR(a,0,7)
    {
        FOR(b,0,207)
        {
            FOR(c,0,SIZE)
            {
                dp[a][b][c] = INT_MIN;
            }
        }
    }
    dp[0][0][0] = 0;
    FOR(a,0,n)
    {
        LL twoCnt = twoCntAr[a+1];
        LL fiveCnt = fiveCntAr[a+1];
        FOR(b,0,1+k)
        {
            FOR(c,0,SIZE)
            {
//                if ( dp[a][b][c] == -1 )
//                {
//                    continue;
//                }
                dp[ (a+1) & 1 ][b][c] = max(dp[ (a+1)&1 ][b][c], dp[a&1][b][c]  );
                dp[ (a+1) & 1 ][ b+1 ][ min(SIZE-1LL, c+fiveCnt) ] = max( dp[ (a+1)&1 ][ b+1 ][ min(SIZE-1LL, c+fiveCnt) ],
                                                   dp[a&1][b][c] + twoCnt  );
            }
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f, g;
    cin >> n >> k;
    FOR(a,1,1+n)
    {
        LL ai;
        scanf("%lld", &ai);
        while( ai % 2 == 0 )
        {
            ai /= 2;
            twoCntAr[a]++;
        }
        while( ai % 5 ==  0 )
        {
            ai /= 5;
            fiveCntAr[a]++;
        }
    }
//    FOR(a,1,1+n)
//    {
//        DBG(a);
//        DBG( twoCntAr[a] );
//        DBG( fiveCntAr[a] );
//    }
    calcDp();
//    FOR(a,0,1+n)
//    {
//        FOR(b,0,1+k)
//        {
//            FOR(c,0,10)
//            {
//                cout << dp[a][b][c] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl << endl << endl;
//    }
    FOR(a,1,SIZE)
    {
        ans = max(ans, min(dp[n&1][k][a], a) );
    }
    cout << ans;
    return 0;
}


