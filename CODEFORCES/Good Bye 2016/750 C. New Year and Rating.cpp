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
long long n, ci, di;
long long max2 = INT_MIN, min1 = INT_MAX, cur;
long long a, b, c, d, e, f, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld %lld", &ci, &di);
        if (di == 1)
        {
            min1 = min(min1, cur);
        }
        else
        {
            max2 = max(max2, cur);
        }
        cur += ci;
    }
    if ( min1 <= max2 )
    {
        cout << "Impossible";
        return 0;
    }
    ans = 1899 + cur-max2;
    if ( ans >= (INT_MAX/2) )
    {
        cout << "Infinity";
    }
    else
    {
        cout << ans;
    }
    return 0;
}

