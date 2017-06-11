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
#define SIZE 1029
long long N;
double ansX[SIZE], ansY[SIZE], pi = acos(-1);

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> N;
    ansX[1] = 0;
    ansY[1] = 0;

    ansX[2] = 0.5;
    ansY[2] = sqrt(3) / 2;

    ansX[3] = 1;
    ansY[3] = 0;

    for (a = 4; a <= N; a++)
    {
        ansX[a] = cos( (pi/3) / (N-2) );
        ansY[a] = sin( (pi/3) / (N-2) );
    }

    for (a = 1;  a<= N; a++)
    {
        printf("%0.10lf %0.10lf\n", ansX[a], ansY[a]);
    }

    return 0;
}
