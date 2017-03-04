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
#define SIZE 19
long long a,b, c, d, e, f;
char grid[SIZE][SIZE], prevChar;
long long ifPos;
long long dirR[] = {1, 0, 1, 1};
long long dirC[] = {0, 1, 1, -1};
long long check()
{
    long long a, b, d, e, f, g, r, c, dr, dc, nr, nc;
    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        {
            r = a;
            c = b;
            for (d = 0; d < 4; d++)
            {
                dr = dirR[d];
                dc = dirC[d];;
                for (e = 0; e < 3; e++)
                {
                    nr = r + dr*e;
                    nc = c + dc*e;
                    if (nr>3 || nc>3 || grid[nr][nc]!='x')
                    {
                        break;
                    }
                }
                if (e >= 3)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    for (a = 0; a<4; a++)
    {
        cin >> grid[a];
    }
    for (a = 0; a < 4; a++)
    {
//        cout << "a = " << a << endl;
//        cout << grid[a] << endl;
    }
    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        {
            prevChar = grid[a][b];
            if ( prevChar != 'o' )
            {
                grid[a][b] = 'x';
                ifPos = ifPos || check();
            }
            grid[a][b] = prevChar;
        }
    }
    if ( ifPos )
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

