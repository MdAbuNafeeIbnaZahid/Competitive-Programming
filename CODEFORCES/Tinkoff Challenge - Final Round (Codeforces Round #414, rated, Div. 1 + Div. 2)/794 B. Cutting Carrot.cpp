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
long long n, h;
vector<double> vecDob;
double n1, h1;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> n >> h;
    n1 = n;
    h1 = h;
    while(n1 > 1)
    {
        h1 = sqrt( (n1-1) / n1 ) * h1;
        vecDob.push_back( h1 );
        n1 = n1 - 1;
    }


    sort(vecDob.begin(), vecDob.end());


    for (a = 0; a < vecDob.size(); a++)
    {
        printf("%0.9lf ",  vecDob[a]);
    }
    return 0;
}
