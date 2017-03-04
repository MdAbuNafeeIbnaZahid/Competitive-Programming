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
long long n;
char str[SIZE];
long long a, b, c, d, e, f, cnt[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", str);
    for (a = 0; a < n; a++)
    {
        cnt[ str[a] ]++;
    }
    if ( cnt['A'] > cnt['D'] )
    {
        cout << "Anton";
    }
    else if ( cnt['A'] < cnt['D'] )
    {
        cout << "Danik";
    }
    else
    {
        cout << "Friendship";
    }
    return 0;
}
