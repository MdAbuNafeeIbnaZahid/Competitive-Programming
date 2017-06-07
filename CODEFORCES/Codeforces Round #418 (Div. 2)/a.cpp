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
#define SIZE 209
long long n, k;
long long aAr[SIZE], bAr[SIZE];
long long a, b, c, d, e;
vector<long long> vec;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        cin >> aAr[a];
    }
    for (b = 1; b <= k; b++)
    {
        cin >> bAr[b];
        vec.push_back( bAr[b] );
    }
    sort(bAr+1, bAr+k+1);
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for (a = 1; a <= n; a++)
    {
        if ( aAr[a] == 0 )
        {
            aAr[a] = vec[0];
            vec.erase( vec.begin() );
        }
    }
    for (a = 1; a <= n; a++)
    {
        for (b = a+1; b <= n; b++)
        {
            if ( aAr[a] >= aAr[b] )
            {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
    return 0;
}
