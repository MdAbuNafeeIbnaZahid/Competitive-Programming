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
#define MAX_VAL 100001
long long a,b,h,w, n, aAr[SIZE];
long long dp[39][SIZE];
vector<long long> aVec;
void calcDp()
{
    long long i, j, k, l;
    dp[0][w] = h;
    for (i = 0; i < aVec.size(); i++)
    {
        long long curA = aVec[i];
        for (j = 0; j <= MAX_VAL; j++)
        {
            dp[i+1][ min(curA*j, (long long)MAX_VAL) ] = max(dp[i+1][ min(curA*j, (long long)MAX_VAL) ],
                                                    dp[i][j]);
            dp[i+1][ j ] = max(dp[i+1][ j ],  min(dp[i][j] * curA, (long long)MAX_VAL) );
            dp[ i+1 ][j] = max(dp[i][j], dp[i+1][j]);
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long i, j, k, l;
    cin >> a >> b >> h >> w >> n;
    if (a>b)
    {
        swap(a, b);
    }
    if (h>w)
    {
        swap(h,w);
    }
    for (i = 1; i <= n; i++)
    {
        long long ai;
        scanf("%lld", &ai);
        aVec.push_back( ai );
    }
    sort(aVec.begin(), aVec.end());
    reverse(aVec.begin(), aVec.end());
    while(aVec.size() > 34)
    {
        aVec.pop_back();
    }
    calcDp();
    for (i = 0; i <= aVec.size(); i++)
    {
        for (j = 0; j <= MAX_VAL; j++)
        {
            long long minS = min(dp[i][j], j), maxS = max(dp[i][j], j);
            if ( a <= minS && b <= maxS )
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
    return 0;
}
