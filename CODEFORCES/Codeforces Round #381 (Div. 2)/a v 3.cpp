
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
long long n, a, b, c, ans;
long long getAns(long long inHand, long long one, long long two, long long three, long long cost, long long depth)
{
    if ( depth > 10 )
    {
        return INT_MAX * 99;
    }
//    cout << "inHand = " << inHand << endl;
    long long a, b, c, d, e, f, ret = INT_MAX * 9;
    if ( inHand % 4 == 0 )
    {
        return cost;
    }
    ret = min(ret,  getAns(inHand+1, one, two, three, cost+one, depth+1) );
    ret = min(ret,  getAns(inHand+2, one, two, three, cost+two, depth+1) );
    ret = min(ret,  getAns(inHand+3, one, two, three, cost+three, depth+1) );
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b >> c;
    ans = getAns(n, a, b, c, 0, 0);
    cout << ans;
    return 0;
}
