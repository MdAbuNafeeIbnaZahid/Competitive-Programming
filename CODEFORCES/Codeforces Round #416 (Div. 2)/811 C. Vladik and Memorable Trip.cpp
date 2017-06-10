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
#define SIZE 5009
long long n, aAr[SIZE];
long long leftIdx[SIZE], rightIdx[SIZE];
void getRange(long long val, long long &left, long long &right)
{
    long  long a, b, c, d, e;
    long long oldLeft = leftIdx[ val ];
    long long oldRight = rightIdx[ val ];
    long long newLeft = leftIdx[val];
    long long newRight = rightIdx[val];
    long long doneLeft = leftIdx[val];
    long long doneRight = rightIdx[val];
    for ( a = doneLeft; a <= doneRight; a ++ )
    {
        oldLeft = min( oldLeft, leftIdx[ aAr[a] ] );
        oldRight = max(oldRight, rightIdx[ aAr[a] ] );
    }
    newLeft=oldLeft;
    newRight = oldRight;
    while( oldLeft < doneLeft || oldRight > doneRight )
    {
        newLeft = oldLeft;
        newRight = oldRight;
        for ( a = oldLeft; a <= doneLeft; a++ )
        {
            newLeft = min(newLeft, leftIdx[ aAr[a] ] );
            newRight = max(newRight, rightIdx[ aAr[a] ] );
        }
        for ( a = doneRight; a <= oldRight; a++ )
        {
            newLeft = min(newLeft, leftIdx[ aAr[a] ] );
            newRight = max(newRight, rightIdx[ aAr[a] ] );
        }

        doneLeft = oldLeft;
        doneRight = oldRight;

        oldLeft = newLeft;
        oldRight = newRight;
    }

    left = oldLeft;
    right = oldRight;
}

set< pair<long long, long long> > setPair;

void printSetPair(set< pair<long long, long long> > setToPr)
{
    set< pair<long long, long long> >::iterator setPIt;
    for ( setPIt = setToPr.begin(); setPIt != setToPr.end(); setPIt++ )
    {
        pair<long long, long long> curP = *setPIt;
        cout << curP.second << " " << curP.first << endl;
    }
}
long long dp[SIZE];
long long getComfort(long long si, long long ei)
{
    long long a, b, c, d, e, ret = 0;
    set<long long> citySet;
    for (a = si; a <= ei; a++)
    {
        if ( citySet.find( aAr[a] ) == citySet.end() )
        {
            citySet.insert( aAr[a] );
            ret ^= aAr[a];
        }
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    for (a = 0;  a <  SIZE; a++  )
    {
        leftIdx[a] = INT_MAX;
        rightIdx[a] = INT_MIN;
    }
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        leftIdx[ aAr[a] ] = min(a, leftIdx[ aAr[a] ]);
        rightIdx[ aAr[a] ] = max( a, rightIdx[ aAr[a] ] );
    }
    for (a = 0; a < SIZE; a++ )
    {
        if ( leftIdx[a] == INT_MAX )
        {
            continue;
        }
        long long l, r;
        getRange(a, l, r);
        // ending first
        setPair.insert( {r, l} );
    }
//    printSetPair( setPair );
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        dp[a] = dp[a-1];
        while( setPair.size() )
        {
            pair<long long, long long> curP = *setPair.begin();
            if ( curP.first > a )
            {
                break;
            }
//            cout << curP.second << " " << curP.first << endl;
            setPair.erase( setPair.begin() );
            long long comfo = getComfort( curP.second, curP.first );
//            cout << "comfo = " << comfo << endl;
            dp[ a ] = max(dp[a], dp[curP.second-1] + comfo);
        }
//        cout << "dp[a] = " << dp[a] << endl;
    }
    cout << dp[n] << endl;
    return 0;
}
