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
long long n, lAr[SIZE], rAr[SIZE];
long long a, b, c, d, e, f, g, beauty, leftTot, rightTot, ans, maxBeauty;
long long posLeftTot, posRightTot;

int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld %lld", &lAr[a], &rAr[a]);
        leftTot += lAr[a];
        rightTot += rAr[a];
    }
    maxBeauty = abs(leftTot-rightTot);
//    cout << "maxBeauty = " << maxBeauty << endl;
    for (a = 1; a <= n; a++)
    {
        posLeftTot = leftTot-lAr[a]+rAr[a];
        posRightTot = rightTot-rAr[a]+lAr[a];
        if ( abs(posLeftTot-posRightTot) > maxBeauty )
        {
            maxBeauty = abs(posLeftTot-posRightTot);
            ans = a;
        }
    }
    cout << ans;
    return 0;
}
