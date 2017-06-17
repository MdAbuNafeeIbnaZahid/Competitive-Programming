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
#define YES ("YES")
#define NO ("NO")
LL x11, y11, x22, y22, x, y;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL dx, dy;
    cin >> x11 >> y11 >> x22 >> y22;
    cin >> x >> y;
    dx = abs(x11-x22);
    if (dx % x)
    {
        cout << NO;
        return 0;
    }
    dx /= x;

    dy = abs(y11-y22);
    if (dy % y)
    {
        cout << NO;
        return 0;
    }
    dy /= y;

    if ( (dx+dy) & 1 )
    {
        cout << NO;
        return 0;
    }

    cout << YES;
    return 0;
}
