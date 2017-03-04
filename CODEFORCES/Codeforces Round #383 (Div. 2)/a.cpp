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
long long getAns(long long n)
{
    long long a, b, c, d, e, f, ret = 1;
    if ( n == 0 )
    {
        return 1;
    }
    else if ( n == 1 )
    {
        return 8;
    }

    if ( n%2 )
    {
        ret = getAns(n/2)%10;
        ret = (ret*ret*8)%10;
        return ret;
    }
    else
    {
        ret = getAns(n/2)%10;
        ret = (ret*ret)%10;
        return ret;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    long long n, ans;
    cin >> n;
    ans = getAns(n);
    cout << ans%10;
    return 0;
}

