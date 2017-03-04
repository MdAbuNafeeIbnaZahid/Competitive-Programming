
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
long long n, isNotPrime[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);]
    long long a, b, c, d, e;
    isNotPrime[1] = 1;
    for ( a = 2; a*a < SIZE ; a++ )
    {
        if ( !isNotPrime[a] )
        {
            for ( b = a*a; b < SIZE; b += a )
            {
                isNotPrime[b] = 1;
            }
        }
    }
    cin >> n;
    if ( n < 3 )
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    for ( a = 2; a < 2+n; a++ )
    {
        printf("%lld ", isNotPrime[a]+1);
    }
    return 0;
}

