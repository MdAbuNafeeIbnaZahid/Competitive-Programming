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
/******   END OF HEADER *********/
#define SIZE 100009
long long n, aAr[SIZE], pAr[SIZE];
vector<long long> children[SIZE];
long long height[SIZE], oddCnt[SIZE*100], evenCnt[SIZE*100], xorVal, ans;
long long oddNodeCnt, evenNodeCnt;
void up(long long u)
{
    long long cur = u, h = 1;
    while(cur && height[cur]==0)
    {
        height[cur] = h++;
        cur = pAr[cur];
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for ( a= 2; a <= n; a++)
    {
        scanf("%lld", &pAr[a]);
        children[pAr[a]].push_back( a );
    }
    for (a = 1; a <= n; a++)
    {
        if (  children[a].size() == 0 )
        {
            up(a);
        }
    }
    for (a = 1; a <= n; a++)
    {
        if ( height[a] & 1 ) // odd node
        {
            xorVal ^= aAr[a];
//            oddCnt[ aAr[a] ]++;;
            oddNodeCnt++;
        }
        else
        {
            evenCnt[ aAr[a] ]++;
            evenNodeCnt++;
        }
    }
    for (a = 1; a <= n; a++)
    {
        if ( height[a] & 1  ) // odd node
        {
            long long newXorVal = xorVal ^ aAr[a];
            ans += evenCnt[ newXorVal ];
        }
    }
    if ( xorVal == 0 ) // Sagheer already winning
    {
        ans += (oddNodeCnt * (oddNodeCnt-1) )/2;
        ans += (evenNodeCnt * (evenNodeCnt-1) )/2;
    }
    cout << ans << endl;
    return 0;
}
