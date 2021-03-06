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
#define SIZE 1000009
#define MOD 1000000007
LL ans, len, pow2[SIZE];
char str[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    scanf("%s", str+1);
    LL cntA = 0;
    len = strlen( str+1 );
    pow2[0] = 1;
    for (a = 1; a < SIZE; a++)
    {
        pow2[a] = (pow2[a-1] * 2) % MOD;
    }
    for (a = 1; a <= len; a++)
    {
        if ( str[a] == 'a' )
        {
            cntA++;
        }
        else
        {
            ans = ( ans + pow2[cntA] - 1 ) % MOD;
        }
    }
    cout << ans;
    return 0;
}
