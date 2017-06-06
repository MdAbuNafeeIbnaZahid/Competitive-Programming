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
long long n, m;
char grid[SIZE][SIZE];
long long val[SIZE][SIZE];
long long leftM[SIZE], rightM[SIZE], isInFloor[SIZE], minH = INT_MAX;
long long ans, leftCover[SIZE], rightCover[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    for (a = 0; a < SIZE; a++)
    {
        leftCover[a] = rightCover[a] = INT_MAX;
    }
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        scanf("%s", grid[a]);
        rightM[a] = 0;
        leftM[a] = m+1;
        for (b = 1; b <= m; b++)
        {
            if ( grid[a][b] == '1' )
            {
                rightM[a] = b;
            }
        }
//        cout << "rightM[a] = " << rightM[a ] << endl;
        for (b = m; b >= 1; b--)
        {
            if ( grid[a][b] == '1' )
            {
                leftM[a] = b;
            }
        }
        isInFloor[a] = (rightM[a] > 0);
        if ( isInFloor[a] )
        {
            minH = min(minH, a);
        }
    }
    if ( minH >= INT_MAX )
    {
        cout << 0;
        return 0;
    }
    leftCover[n] = 2 * rightM[n];
    rightCover[n] = m+1;
    if ( minH == n )
    {
        cout << rightM[n];
        return 0;
    }
//    cout << "leftCover[n] = " << leftCover[n] << endl;
//    cout << "rightCover[n] = " << rightCover[n] << endl;
    for (a = n-1; a >= 1; a--)
    {

//        cout << "a = " << a << endl;
        leftCover[a] = min(leftCover[a+1] + 1 + 2 * rightM[a], leftCover[a]);
        leftCover[a] = min(rightCover[a+1] + 1 + m+1, leftCover[a]);

//        cout << "leftCover[a] = " << leftCover[a] << endl;


        rightCover[a] = min(rightCover[a+1] + 1 + 2 *( m+1- leftM[a] ), rightCover[a]);
        rightCover[a] = min(leftCover[a+1] + 1 + m+1, rightCover[a]);

//        cout << "rightCover[a] = " << rightCover[a] << endl;
    }

//    cout << "minH = " << minH << endl;

    ans = min( leftCover[minH+1]+1+rightM[minH], rightCover[minH+1]+1+(m+1-leftM[minH]) );
    cout << ans << endl;

    return 0;
}
