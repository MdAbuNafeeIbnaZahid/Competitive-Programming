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
#define LL long long
/******   END OF HEADER *********/
LL n, k;
vector<LL> divv;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k;
    LL sqRoot = sqrt(n+9);
    for (a = 1;  a<= sqRoot; a++ )
    {
        if ( n-(n/a)*a == 0 )
        {
            divv.push_back(a);
            divv.push_back(n/a);
        }
    }
    sort(divv.begin(), divv.end());


//    cout << "(k*(k+1) )/2 = " << (k*(k+1) )/2 << endl;
    if ( k > (1e6) )
    {
        cout << -1;
        return 0;
    }
    if ( (k*(k+1) )/2 > divv[ divv.size() - 1 ] )
    {
        cout << -1;
        return 0;
    }




//    return 0;
    for (a = 0; a < divv.size(); a++)
    {
        if ( (k*(k+1) )/2 <= divv[a] )
        {
            LL mul = n/divv[a];
            for (b = 1; b < k; b++)
            {
                printf("%lld ", b*mul );
            }
            LL rem = divv[a] - (k*(k-1) ) / 2;
            printf("%lld", rem*mul);
            return 0;
        }
    }
    return 0;
}
