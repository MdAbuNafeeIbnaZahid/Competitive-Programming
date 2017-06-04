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
#define SIZE 10009
long long T, N, K, lenAr[SIZE], ans;
vector<long long> numSet[SIZE];
long long num;
long long ifMakePair(long long x, long long y)
{
    long long xIdx = 0, yIdx = 0, ret, a, b, c, d, e;
    for (a = 1; a <= K; a++)
    {
        long long flag = 0;
        if ( xIdx < numSet[x].size() && numSet[x][xIdx] == a )
        {
            xIdx++;
            flag = 1;
        }
        if ( yIdx < numSet[y].size() && numSet[y][yIdx] == a )
        {
            yIdx++;
            flag = 1;
        }
        if (flag == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> N >> K;
        for (b = 1; b <= N; b++)
        {
            numSet[b] = vector<long long>();
            scanf("%lld", &lenAr[b]);
            for ( c = 1; c <= lenAr[b]; c++)
            {
                scanf("%lld", &num);
                numSet[b].push_back(num);
            }
            sort(numSet[b].begin(), numSet[b].end());
        }
        for (b = 1; b <= N; b++)
        {
            for (c = b+1; c <= N; c++)
            {
                if ( lenAr[b] + lenAr[c] < K )
                {
                    continue;
                }
                ans += ifMakePair(b, c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
