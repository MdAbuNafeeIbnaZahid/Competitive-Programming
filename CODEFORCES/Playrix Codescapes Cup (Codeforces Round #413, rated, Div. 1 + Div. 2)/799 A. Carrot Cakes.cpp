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
#define SIZE 1000009
long long n, t, k, d;
long long dpWithout[SIZE], dpWith[SIZE], withoutT = INT_MAX, withT = INT_MAX;

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n >> t >> k >> d;
    for (a = 1; a < SIZE; a++)
    {
        dpWithout[ a ] = dpWithout[a-1];
        if ( a - t >= 0 )
        {
            dpWithout[ a ] = dpWithout[ a-t ] + k;
        }
        if ( dpWithout[a] >= n )
        {
            withoutT = min(withoutT, a);
        }



        dpWith[a] = dpWith[a-1];
        if ( a - t >= d )
        {
            dpWith[a] = dpWith[a-t] + k;
        }
        if ( dpWithout[a] + dpWith[a] >= n )
        {
            withT = min(withT, a);
        }
    }

    if ( withoutT > withT )
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;

    for (a = 1; a < SIZE; a++)
    {

    }
    return 0;
}
