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
long long n, k, ans;
long long a, b, c,  d, e;
string nStr;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    //ans = nStr.size() - 1;
    long long nCop = n;
    if ( n ==0 )
    {
        cout << 0;
        return 0;
    }

    while( nCop )
    {
        nCop /= 10;
        ans++;
    }
    ans--;

    long long cnt = 0;
    long long posAns = 0;
    while( n && cnt < k )
    {
        long long rightDig = n%10;
        if ( rightDig )
        {
            posAns++;
        }
        else
        {
            cnt++;
        }
        n /= 10;
    }

    if ( n ) ans = min(ans, posAns);
    cout << ans;
    return 0;
}

