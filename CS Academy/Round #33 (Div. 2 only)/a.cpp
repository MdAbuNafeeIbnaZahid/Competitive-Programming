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
#define LL long long
/******   END OF HEADER *********/
LL N;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL minX = INT_MAX;
    LL minY = INT_MAX;
    LL maxX = INT_MIN;
    LL maxY = INT_MIN;
    LL a, b, c, d, e;
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        LL x, y;
        scanf("%lld %lld", &x, &y);
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }
    cout << (maxX-minX)*(maxY-minY);
    return 0;
}
