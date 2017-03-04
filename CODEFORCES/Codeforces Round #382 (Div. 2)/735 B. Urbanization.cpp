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
long long n, n1, n2, ai;
vector<double> aVec, workVec;
long long a, b, c, d, e, f, g;
bool myCmp(double a, double b)
{
    return a*n2 + b*n1 > b * n2 + a*n1;
}
double ans = 0;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> n1 >> n2;
    if ( n1 < n2 )
    {
        swap(n1, n2);
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ai);
        aVec.push_back( ai );
    }
    sort(aVec.begin(), aVec.end() );
    for (a = 1; a <= n1+n2; a++)
    {
        workVec.push_back( aVec[ aVec.size()-1 ] );
        aVec.pop_back();
    }
    sort(workVec.begin(), workVec.end(), myCmp);
    for (a = 0; a < n1; a++)
    {
        ans += n2 * workVec[a];
    }
    for (a = n1; a < n1+n2; a++)
    {
        ans += n1 * workVec[a];
    }
    ans /= (n1 * n2);
    printf("%0.8lf", ans);
    return 0;
}
