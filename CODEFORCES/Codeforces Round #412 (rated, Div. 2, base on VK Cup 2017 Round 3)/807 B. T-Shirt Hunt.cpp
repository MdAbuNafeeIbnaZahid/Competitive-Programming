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
LL p, x, y;
LL isOk[SIZE];
LL isOkFunc(LL s)
{
    LL i = (s/50) % 475;
    LL a, b, c, d;
    for ( a= 1; a <= 25; a++)
    {
        i = (i * 96 + 42) % 475;
        if ( 26 + i == p )
        {
            return 1;
        }
    }
    return 0;
}
LL getDist(LL cur, LL tar)
{
    LL dif = abs(cur - tar);
    if ( dif % 50 != 0 )
    {
        return INT_MAX;
    }
    if ( tar < cur )
    {
        return 0;
    }
    return (dif+50)/100;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, ans = INT_MAX;
    cin >> p >> x >> y;
    for (a = y; a < SIZE; a++)
    {
        isOk[a] = isOkFunc(a);
    }
    for (a = y; a < SIZE; a++)
    {
        if ( isOk[a] )
        {
            ans = min(ans, getDist(x, a) );
        }

    }
    cout << ans ;
    return 0;
}
