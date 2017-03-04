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
#define SIZE 99
long long powOf2[SIZE];
long long n, k, ans;
long long a, b, c, d, e, f, g;
long long func(long long n, long long k)
{
    if (k == powOf2[n])
    {
        return n+1;
    }
    else if ( k < powOf2[n] )
    {
        return func(n-1, k);
    }
    else
    {
        return func(n-1, k-powOf2[n]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    powOf2[0] = 1;
    for (a = 1; a < 60; a++)
    {
        powOf2[a] = powOf2[a-1]*2;
    }
    cin >> n >> k;
    ans = func(n-1, k);
    cout << ans ;
    return 0;
}

