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
#define SIZE 109
long long n, aAr[SIZE];
long long a, b, c, d, e, f;
long long ifPos, arSum, fir;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> aAr[a];
        ifPos = ifPos || aAr[a];
        arSum += aAr[a];
    }
    if ( !ifPos )
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    if (arSum)
    {
        cout << 1 << endl;
        cout << 1 << " " << n;
        return 0;
    }
    else
    {
        for (a = 1; a <= n; a++)
        {
            if ( aAr[a] )
            {
                fir = a;
                break;
            }
        }
        cout << 2 << endl;
        cout << 1 << " " << fir << endl;
        cout << fir+1 << " " << n << endl;
    }

    return 0;
}

