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
#define SIZE 2000009
LL n, k;
LL doneUpto, ans, ar[SIZE];
vector<LL> prevVec, curVec;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k;
    ans = 2* (  (n-1)/k );
    if ( (n-1)%k == 1 )
    {
        ans++;
    }
    else if ( (n-1)%k >= 2 )
    {
        ans  += 2;
    }
    cout << ans << endl;
    FOR(a,0,k)
    {
        ar[a] = 1;
    }
    FOR(a,2,1+n)
    {
        printf("%lld %lld\n", ar[a%k], a);
        ar[a%k] = a;
    }
    return 0;



    FOR(a,1,1+k)
    {
        curVec.PUB( 1+a );
        printf("%lld %lld\n", 1LL, 1+a);
    }
    prevVec = curVec;
    doneUpto = 1+k;
    while( doneUpto < n )
    {
        curVec = vector<LL>();
        FOR(a,0,min(k, n-doneUpto ))
        {
            printf("%lld %lld\n", ++doneUpto, prevVec[a]);
            curVec.PUB( doneUpto );
        }
        prevVec = curVec;
    }
    return 0;
}
