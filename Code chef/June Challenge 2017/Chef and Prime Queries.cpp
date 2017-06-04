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
#define SIZE 20
long long isPrime[SIZE], primeCnt;
int main()
{
    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    memset(isPrime, -1, sizeof(isPrime) );
    isPrime[1] = 0;
    for (a = 2; a*a < SIZE; a++)
    {
        if ( isPrime[a] )
        {
            for (b = a*a; b < SIZE; b+=a)
            {
                isPrime[b] = 0;
            }
        }
    }
    for ( a = 2; a < SIZE; a++)
    {
        if ( isPrime[a] )
        {
            primeCnt++;
        }
    }
    cout << "primeCnt = " << primeCnt << endl;
    return 0;
}
