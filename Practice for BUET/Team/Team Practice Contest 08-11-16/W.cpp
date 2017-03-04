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
long long B, S, bi, si, ans, yb;
vector<long long> bachVec;
long long a, b, c, d, e, f, kase;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        kase++;
        yb = INT_MAX;
        cin >> B >> S;
        if (B+S==0)
        {
            return 0;
        }
        bachVec = vector<long long>();
        for (a = 1; a <= B; a++)
        {
            scanf("%lld", &bi);
            //bachVec.push_back( bi );
            yb = min(yb, bi);
        }
        //sort(bachVec.begin(), bachVec.end());
        for(a = 1; a <= S; a++)
        {
            scanf("%lld", &si);
        }
        ans = max(0LL, B-S);
        cout << "Case " << kase << ": " << ans;
        if (ans > 0)
        {
            cout << " " << yb;
        }
        cout << endl;
    }
    return 0;
}
