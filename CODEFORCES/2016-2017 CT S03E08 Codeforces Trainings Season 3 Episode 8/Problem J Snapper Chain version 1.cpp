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
long long t, n, k;
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    for (a = 1; a <= t; a++)
    {
        scanf("%lld %lld", &n, &k);
        for (b = 1; b <= n; b++)
        {
            if ( ( (k>>(b-1) ) & 1)==0 ) break;
        }
        if ( b <= n )
        {
            printf("OFF\n");
        }
        else
        {
            printf("ON\n");
        }
    }
    return 0;
}
