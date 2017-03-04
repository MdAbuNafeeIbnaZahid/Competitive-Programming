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
long long n, aAr[SIZE], bAr[SIZE];
long long aCnt[SIZE], bCnt[SIZE];
long long a, b, c, d, e , f;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for ( a =1; a <= n; a++ )
    {
        scanf("%lld", &aAr[a]);
        aCnt[ aAr[a] ]++;
    }
    for ( a = 1; a<= n; a++ )
    {
        scanf("%lld", &bAr[a]);
        bCnt[ bAr[a] ]++;
    }
    for ( a = 1; a <= 5; a++ )
    {
        if ( (aCnt[a]+bCnt[a])%2 )
        {
            cout << -1;
            return 0;
        }
    }
    long long ans = 0;
    for ( a = 1; a <= 5; a++ )
    {
        long long addee = ( aCnt[a] ) - ( aCnt[a] + bCnt[a] )/2;
        if ( addee < 0 )
        {
            addee = 0;
        }
        ans += addee;
    }
    cout << ans;
    return 0;
}

