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
long long n;
long long aAr[SIZE], bAr[SIZE], posAns[SIZE];
long long isPresent[SIZE], du1, du2, notPre;

long long ifOk()
{
    long long misM = 0;
    long long a, b, c, d, e;
    for ( a= 1; a <= n; a++)
    {
        if ( posAns[a] != bAr[a] )
        {
            misM++;
        }
    }
    return misM == 1;
}

void prAns()
{
    long long a, b, c, d;
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", posAns[a]);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        posAns[a] = aAr[a];
        isPresent[ aAr[a] ]++;
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &bAr[a]);
    }
    for (   a = 1; a <= n; a++)
    {
        if ( isPresent[a] == 0 )
        {
            notPre = a;
        }
    }
    for (a = 1; a <= n; a++)
    {
        for (b = a+1; b <= n; b++)
        {
            if ( aAr[a] == aAr[b] )
            {
                du1 = a;
                du2 = b;
            }
        }
    }

    posAns[ du1 ] = notPre;
    if( ifOk() )
    {
        prAns();
        return 0;
    }

    posAns[ du1 ] = posAns[du2];
    posAns[ du2 ] = notPre;
    prAns();

    return 0;
}
