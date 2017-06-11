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
long long n;
vector<long long> dig;
vector<long long> getDig(long long num)
{
    vector<long long> ret;
    while(num)
    {
        ret.push_back( num%10 );
        num /= 10;
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, m = 1, ans;
    cin >> n;
    if (n <= 9)
    {
        cout << 1;
        return 0;
    }
    dig = getDig(n);
    for (a = 1; a < dig.size(); a++)
    {
        m *= 10;
    }
//    cout << "m = " << m << endl;
    ans = m-(n%m);
    cout << ans << endl;
    return 0;
}
