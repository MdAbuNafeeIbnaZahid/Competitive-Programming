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
long long n, m, fAr[SIZE], gAr[SIZE], hAr[SIZE];
long long a, b, c, d, e, f;
set<long long> headSet;
vector<long long> headVec;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for ( a = 1; a <= n; a++)
    {
        scanf("%lld", &fAr[a]);
        headSet.insert( fAr[a] );
        headVec.push_back( fAr[a] );
    }
    m = headSet.size();
    for ( a = 0; a < headVec.size(); a++ )
    {
        if ( fAr[ headVec[a] ] != headVec[a] )
        {
            cout << -1;
            return 0;
        }
    }
    long long mIdx = 0;
    set<long long>::iterator setLLIt;
    for (setLLIt = headSet.begin(); setLLIt != headSet.end(); setLLIt++)
    {
        long long cur = *setLLIt;
        gAr[ cur ] = ++mIdx;
        hAr[ mIdx ] = cur;
    }
    for ( a = 1; a <= n; a++ )
    {
        gAr[a] = gAr[ fAr[a] ];
    }
    cout << m << endl;
    for ( a = 1; a<= n; a++ )
    {
        printf("%lld ", gAr[a]);
    }
    cout << endl;
    for (a = 1; a <= m; a++)
    {
        printf("%lld ", hAr[a]);
    }
    return 0;
}

