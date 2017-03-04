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
long long n, a, b, ans = INT_MAX;
char str[SIZE];
long long c, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b;
    a--;
    b--;
    scanf("%s", str);
    ans = (str[a] != str[b]);

    cout << ans ;
    return 0;

    for (c = 0; c < n; c++)
    {
        if ( str[c] == str[b] )
        {
            ans = min( ans, abs(c-a) );
        }
    }

}

