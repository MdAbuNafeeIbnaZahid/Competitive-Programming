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
long long n, ai, bi, ci, k, firstAns, secondAns;
long long a, b, c, d, e, f, g, maxSph, side1, side2;
map< pair<long long, long long>, set<pair<long long, long long> > > myMap;
map< pair<long long, long long>, set<pair<long long, long long> > >::iterator mapIt;
pair<long long, long long> twoSides;
set< pair<long long, long long> > setPair;
void handleInventory(long long x, long long y, long long z, long long idx)
{
    if ( x > y )
    {
        swap(x,y);
    }
    myMap[ {x,y} ].insert( {z, idx} );
}
long long minOf3(long long x, long long y, long long z)
{
    return min(min(x,y),z);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld %lld %lld",&ai, &bi, &ci);
        handleInventory(ai, bi, ci, a);
        handleInventory(bi, ci, ai, a);
        handleInventory(ci, ai, bi, a);
    }
    for (mapIt = myMap.begin(); mapIt != myMap.end(); mapIt++)
    {
        twoSides = mapIt->first;
        setPair = mapIt->second;
        if ( setPair.size() > 1 )
        {
            side1 = ( *( --setPair.end() ) ).first;
            side2 = (*( --(--setPair.end() ) ) ).first;
            if ( minOf3(twoSides.first, twoSides.second, side1+side2) > maxSph )
            {
                maxSph = minOf3(twoSides.first, twoSides.second, side1+side2);
                k = 2;
                firstAns = (*(--setPair.end() ) ).second;
                secondAns = (*( --(--setPair.end() ) ) ).second;
            }
        }
        else
        {
            side1 = ( *( --setPair.end() ) ).first;
            //side2 = (*( --(--setPair.end() ) ) ).first;
            if ( minOf3(twoSides.first, twoSides.second, side1) > maxSph )
            {
                maxSph = minOf3(twoSides.first, twoSides.second, side1);
                k = 1;
                firstAns = (*(--setPair.end() ) ).second;
                //secondAns = (*( --(--setPair.end() ) ) ).second;
            }
        }
    }
    cout << k << endl << firstAns;
    if (k>1)
    {
        cout << " " << secondAns;
    }
    return 0;
}

