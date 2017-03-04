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
less<long long>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
#define SIZE 200009
long long n, m, k;
long long x, s, aAr[SIZE], bAr[SIZE], cAr[SIZE], dAr[SIZE];
long long a, b, c, d, e, f, ans, remS, newN, newX, tempAns, targetIdx;
long long binSearch(long long searchVal)
{
    long long startIdx = 0, mid, endIdx = k;
    while( startIdx < endIdx )
    {
        //cout << "startIdx = " << startIdx << endl;
        //cout << "endIdx = " << endIdx << endl;
        mid = (startIdx+endIdx+1)/2;
        //cout << "mid = " << mid << endl;
        if ( dAr[mid] <= searchVal )
        {
            startIdx = mid;
        }
        else
        {
            endIdx = mid-1;
        }
    }
    return endIdx;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ans = -1LL;
    ans = (unsigned long long)ans >> 1;
    ans -= 9999;
    //cout << ans << endl;
    cin >> n >> m >> k;
    cin >> x >> s;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 1; a <= m; a++)
    {
        scanf("%lld", &bAr[a]);
    }
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &cAr[a]);
    }
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &dAr[a]);
    }
    //cout << "traversing type 1" << endl;
    for (a = 1; a <= m; a++)
    {
        //cout << "a = " << a << endl;
        newX = x;
        remS = s;
        if ( remS >= bAr[a] )
        {
            remS -= bAr[a];
            newX = aAr[a];
        }
        //cout << "remS = " << remS << endl;
        //cout << "newX = " << newX << endl;
        targetIdx = binSearch(remS);
        //cout << "targetIdx = " << targetIdx << endl;
        newN = n - cAr[ targetIdx ];
        tempAns = newN * newX;
        ans = min(tempAns, ans);
        //cout << "ans = " << ans << endl;
    }
    for (a = 1; a <= k; a++)
    {
        if ( dAr[a] <= s )
        {
            newN = n - cAr[ a ];
            tempAns = newN * x;
            ans = min(ans, tempAns);
        }
    }
    cout << ans ;
    return 0;
}
