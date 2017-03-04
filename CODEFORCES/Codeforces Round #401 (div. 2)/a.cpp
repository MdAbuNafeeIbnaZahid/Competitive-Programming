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
long long n, x, ar[9];
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    ar[0] = 0;
    ar[1] = 1;
    ar[2] = 2;
    cin >> n >> x;
    n %= 6;
    for ( a = 1; a <= n; a++ )
    {
//        cout << "a = " << a << endl;
        long long side;
        if ( a%2 )
        {
            side = 0;
        }
        else
        {
            side =  2;
        }
        swap( ar[1], ar[side] );
//        cout << ar[0] << " " << ar[1] << " " << ar[2] << endl;
    }
    cout << ar[x];
    return 0;
}
