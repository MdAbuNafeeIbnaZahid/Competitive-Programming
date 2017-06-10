
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
long long N, aAr[SIZE], fst[SIZE], lst[SIZE];
set< pair<long long, long long> > setPair, workPair;
long long dp[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a= 1; a <= N; a++)
    {
        lst[ aAr[a] ] = a;
    }
    for (a = N; a >= 1; a--)
    {
        fst[ aAr[a] ] = a;
    }
    for (a = 1; a < SIZE; a++)
    {
        if ( fst[a] == 0 )
        {
            continue;
        }
        setPair.insert( make_pair( fst[a], lst[a] ) );
    }
    while( setPair.size() )
    {
        pair<long long, long long> curP = *setPair.begin();
        setPair.erase( setPair.begin() );
        long long si = curP.first, minei = curP.second;
        long long maxei = curP.second;
        while( setPair.size() )
        {
            pair<long long, long long> nextP = *setPair.begin();
            if ( nextP.first > maxei )
            {
                break;
            }
            setPair.erase( setPair.begin() );
            maxei = max(maxei, nextP.second);
        }
        // opposite
        workPair.insert( make_pair(maxei, si) );
    }
//    cout << "workPair.size() = " << workPair.size() << endl;
    cout << workPair.size();
    return 0;
    for (a = 1; a <= N; a++)
    {
        dp[a] = dp[a-1];
        if ( workPair.size() && (*workPair.begin()).first == a )
        {
            dp[a] = max(dp[a], dp[ (*workPair.begin()).second - 1 ] + 1);
            workPair.erase( workPair.begin() );
        }
    }
    cout << dp[N];
    return 0;
}
