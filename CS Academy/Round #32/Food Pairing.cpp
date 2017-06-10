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
#define SIZE 519
long long N, M, ingr[SIZE], grid[SIZE][SIZE], calcGrid[SIZE][39];
long long sumGrid[SIZE*SIZE][39];
long long ifPossible(long long num)
{
    long long a, b, c, d, e, f, ret = 0;
    memset(calcGrid, 0, sizeof(calcGrid) );
    for (a = 1; a <= M; a++)
    {
        for (b = 1; b <= N; b++)
        {
            calcGrid[a][b] = num * grid[a][b];
        }
    }
    for (a = 1; a <= M; a++)
    {
        for (b = 1; b <= M; b++)
        {

        }
    }
}
long long myDiv(long long a, long long b)
{
    if (b == 0)
    {
        return INT_MAX;
    }
    return a/b;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> N;
    for ( a = 1; a <= N; a++)
    {
        scanf("%lld", &ingr[a]);
    }
    cin >> M;
    for (a = 1; a <= M; a++)
    {
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &grid[a][b]);
        }
    }
    long long cnt = 0;
    for (a = 1; a <= M; a++)
    {
        for (b = a+1; b <= M; b++)
        {
            cnt++;
            for (c = 1; c <= N; c++)
            {
                sumGrid[cnt][c] = grid[a][c] + grid[b][c];
            }
        }
    }

    long long ans = 0;
    for (a= 1; a <= cnt; a++)
    {
//        cout << "a = " << a << endl;
        long long posAns = INT_MAX;
        for (b = 1; b <= N; b++)
        {
            posAns = min(posAns, myDiv(ingr[b], sumGrid[a][b]) );
        }

        ans = max(ans, posAns);
    }
    cout << ans;
    return 0;
}
