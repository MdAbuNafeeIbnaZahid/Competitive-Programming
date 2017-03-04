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
long long n, ai;
long long a, b, c, d, e, f;
vector<long long> aVec;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n;a++)
    {
        scanf("%lld", &ai);
        aVec.push_back( ai );
    }
    sort(aVec.begin(), aVec.end());
    for (a = 2; a < aVec.size(); a++)
    {
        if ( aVec[a-1] + aVec[a-2] > aVec[a] )
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
