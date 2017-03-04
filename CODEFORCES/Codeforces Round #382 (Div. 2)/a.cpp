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
#define SIZE
long long a, b, c, d, e, f, g, leftIdx, rightIdx;
long long n, k;
string str;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> str;
    for (a = 0; a < n; a++)
    {
        if ( str[a] == 'G'  || str[a] == 'T' )
        {
            rightIdx = a;
        }
    }
    for (a = n-1; a >= 0; a--)
    {
        if ( str[a] == 'G'  || str[a] == 'T' )
        {
            leftIdx = a;
        }
    }
    for (a = leftIdx; a <= rightIdx; a += k)
    {
        if ( a == rightIdx )
        {
            cout << "YES";
            return 0;
        }
        else if ( str[a] == '#' )
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}

