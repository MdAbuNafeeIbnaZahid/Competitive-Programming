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
LL n;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    cin >> n;
    if (n & 1)
    {
        cout << (n/2);
    }
    else
    {
        cout << (n/2)-1;
    }
    return 0;




    n = 10;
    for (a = 1; a <= n; a++)
    {
        for (b=1; b <= n; b++)
        {
            if (a==b)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << (a+b)%(n+1) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
