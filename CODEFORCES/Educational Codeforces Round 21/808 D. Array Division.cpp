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
long long n, aAr[SIZE];
map<long long, long long> fst, lst;
long long conSum[SIZE];
long long myAbs(long long x)
{
    if (x < 0) x = -x;
    return x;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        conSum[a] = conSum[a-1] + aAr[a];
        lst[ aAr[a] ] = a;
    }
    long long tot = conSum[n];
//    cout << "tot = " << tot << endl;
    for (a = n; a >= 1; a--)
    {
        fst[ aAr[a] ] = a;
    }
    if (tot & 1LL)
    {
        cout << "NO";
        return 0;
    }
    for (a = 1; a <= n; a++)
    {
        long long leftSum = conSum[a];
        long long rightSum = tot-conSum[a];
        long long dif = myAbs(leftSum - rightSum);
        if ( dif & 1LL )
        {
            continue;
        }
        if ( leftSum == rightSum )
        {
            cout << "YES";
            return 0;
        }
        if ( leftSum < rightSum )
        {
            if ( lst[ dif/2 ] > a )
            {
                cout << "YES";
                return 0;
            }
        }
        else
        {
            if ( (fst[ dif/2 ]<=a) &&  (fst[ dif/2 ]!=0) )
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
