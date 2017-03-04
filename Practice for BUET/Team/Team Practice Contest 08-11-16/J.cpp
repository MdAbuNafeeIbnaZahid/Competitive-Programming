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
#define SIZE 509
long long t, n, k, ans;
long long a, b, c, d, e, f, lastMeet[SIZE];
char str[SIZE], ch;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    for (a = 1; a <= t; a++)
    {
        ans = 0;
        for (b = 'A'; b <= 'Z'; b++)
        {
            lastMeet[b] = INT_MIN;
        }
        cin >> n >> k;
        scanf("%s", str);
        for (b = 0; b < n; b++)
        {
            ch = str[b];
            if ( b-lastMeet[ch] <= k )
            {
                ans++;
                //cout << "b = " << b << endl;
            }
            lastMeet[ ch ] = b;
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}

