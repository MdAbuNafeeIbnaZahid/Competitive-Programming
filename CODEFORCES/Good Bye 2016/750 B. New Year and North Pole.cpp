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
long long n, ti, pos;
long long a, b, c, d, e;
string dir;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> ti >> dir;
        if ( dir ==  "North" )
        {
            for (b = 1; b <= ti; b++)
            {
                pos--;
                if (pos < 0)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
        else if (dir == "South")
        {
            for (b = 1; b <= ti; b++)
            {
                pos++;
                if (pos > 20000 )
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
        else if (dir == "West" || dir == "East")
        {
            if (pos <= 0 || pos >= 20000 )
            {
                cout << "NO";
                return 0;
            }
        }
        else if (dir == "East")
        {
            for (b = 1; b <= ti; b++)
            {
                pos++;
                if (pos > 20000 )
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    if (pos != 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}

