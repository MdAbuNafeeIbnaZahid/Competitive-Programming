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
#define SIZE 9999
long long T, n;
set<long long> goodSet;
long long goodMark[SIZE], goodCnt;
long long isGood(long long n)
{
    long long a, b, c, d, e, ret = 1;
    for (a = 1; a < n; a++)
    {
        for (b = a+1; b < n; b++)
        {
            if ( goodMark[a] && goodMark[b] && a+b==n )
            {
                goodMark[n] = 0;
            }
        }
    }
    return goodMark[n];
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    memset(goodMark, -1, sizeof(goodMark));
    for  (a = 1; a < 500; a++)
    {
        isGood(a);
        if ( goodMark[a] )
        {
//            cout << a << " ";
            goodCnt++;
        }
    }
    //cout << "goodCnt = " << goodCnt << endl;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n;
        for (b = 1;  b <= n; b++)
        {
            printf("%lld ", 1+b*3);
        }
        cout << endl;
    }
    return 0;
}
