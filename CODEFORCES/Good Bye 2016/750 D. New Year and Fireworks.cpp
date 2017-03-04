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
#define SIZE 39
long long n, tAr[SIZE];
long long dirX[] = {1, 1, 0, -1, -1, -1, 0, 1};
long long dirY[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long x, y, d;
long long a, b, c, e , f;
struct idx
{
    long long x, y;
    idx(){}
    idx(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator < (const idx B) const
    {
        if ( x != B.x ) return x < B.x;
        return y < B.y;
    }
};
struct fire
{
    long long x, y, d;
    fire(){}
    fire(long long x, long long y, long long d)
    {
        this->x = x;
        this->y = y;
        this->d = d;
    }
    bool operator < (const fire B) const
    {
        if ( x != B.x  ) return x < B.x;
        if ( y != B.y ) return y < B.y;
        return d < B.d;
    }
};
set<idx> visited;
set<fire> setFire, newSetFire;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> tAr[a];
    }
    setFire.insert( fire(0, -1, 2) );
    for (a = 1; a <= n; a++)
    {
        newSetFire = set<fire>();
        for (set<fire>::iterator setFireIt = setFire.begin(); setFireIt != setFire.end(); setFireIt++)
        {
             x = setFireIt->x;
             y = setFireIt->y;
             d = setFireIt->d;
             for (b = 1; b <= tAr[a]; b++)
             {
                 x += dirX[d];
                 y += dirY[d];
                 visited.insert( idx(x, y) );
             }
             newSetFire.insert( fire(x, y, (d+1)%8 ) );
             newSetFire.insert( fire(x, y, (d-1+8)%8) );
        }
        setFire = newSetFire;
    }
    cout << visited.size();
    return 0;
}

