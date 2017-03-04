
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
long long n, k, ans;
long long aAr[SIZE];
long long cumSum[SIZE], powAr[SIZE], minH, maxH, maxAbs;
map<long long, long long> heightCnt;
//set<long long>
int main()
{
   // freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> n >> k;
//    cout << "n = " << n << endl;
    //heightCnt[ 0 ]++;
    for ( a = 1; a <= n; a++ )
    {
//        cout << "a = " << a << endl;
        scanf("%lld", &aAr[a]);
        cumSum[a] = cumSum[a-1] + aAr[a];
//        cout << "aAr[a] = " << aAr[a] << endl;
//        cout << "cumSum[a] = " << cumSum[a] << endl;
        //heightCnt[ cumSum[a] ]++;
        minH = min(minH, cumSum[a] );
        maxH = max( maxH, cumSum[a] );

    }

    maxAbs = maxH - minH;
//    cout << "maxAbs = " << maxAbs << endl;

    powAr[0] = 1;
    for ( a = 1; a <= 53; a++ )
    {
        powAr[ a ] = powAr[a-1] * k;
    }

    for ( a = n; a >= 0; a-- )
    {
//    	cout << "a = " << a << endl;
        long long addee = 0;
        if ( k == 1  )
        {
            addee += heightCnt[ cumSum[a] + 1LL ];
        }
        else if ( k == -1 )
        {
            addee += heightCnt[ cumSum[a] + 1LL ];
            addee += heightCnt[ cumSum[a] - 1LL ];
        }
        else
        {
            for ( b = 0; powAr[b] <= maxAbs ; b++ )
            {
//                cout << "powAr[b] = " << powAr[b] << endl;
                addee += heightCnt[ cumSum[a] + powAr[b] ];
            }
        }
        heightCnt[ cumSum[a] ]++;
        ans += addee;
//        cout << "ans = " << ans << endl;
    }
    hh

//    minH = heightCnt.begin()->first;
//    maxH = heightCnt.rbegin()->first;
//    maxAbs = max( abs(minH), abs(maxH) );
//    cout << "minH = " <<  minH << endl;
//    cout << "maxH = " <<  maxH << endl;

//    map<long long, long long>::iterator mapLLIt;
//    for ( mapLLIt = heightCnt.begin(); mapLLIt != heightCnt.end(); mapLLIt++ )
//    {
//        long long addee = 0;
//        if ( abs() )
//    }
    cout << ans ;
    return 0;
}

