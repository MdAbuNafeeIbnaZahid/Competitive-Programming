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
#define SIZE 200009
LL n, k, q;
LL cntAr[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k >> q;
    for (a = 1; a <= n; a++)
    {
        LL li, ri;
        scanf("%lld %lld", &li, &ri);
        cntAr[li]++;
        cntAr[ri+1]--;
    }
    for ( a= 1; a < SIZE; a++)
    {
        cntAr[a] += cntAr[a-1];
    }
    for (a= 1; a < SIZE; a++)
    {
        cntAr[a] = (cntAr[a] >= k);
    }
    for (a= 1; a < SIZE; a++)
    {
        cntAr[a] += cntAr[a-1];
    }
    for (a= 1; a <= q; a++)
    {
        LL ai, bi;
        scanf("%lld %lld", &ai, &bi);
        LL ans = cntAr[bi] - cntAr[ai-1];
        printf("%lld\n", ans);
    }
    return 0;
}
