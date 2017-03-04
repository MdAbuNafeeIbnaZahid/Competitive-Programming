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
long long n, m, li, ri, ans = INT_MAX;
long long a, b, c, d, e, f;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &li, &ri);
        ans = min(ans, ri-li+1);
    }
    cout << ans << endl;
    for (a = 0; a < n; a++)
    {
        printf("%lld ", a%ans);
    }
    return 0;
}

