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
#define SIZE 200009
long long n, aAr[SIZE], cntAr[SIZE], cumSum[SIZE], addee, elementsBetween;
long long a,b, c, d, e, f, g, h, ans, previousVal, probAns, totalPrev, current;
set<long long> setLL;
set<long long>::iterator setLLIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        cntAr[ aAr[a] ]++;
        setLL.insert( aAr[a] );
    }
    sort(aAr+1, aAr+n+1);
    for (a = 1; a < SIZE; a++)
    {
        cumSum[a] = cumSum[a-1] + cntAr[a];
    }
//    for (a = 200000-10; a < 200000+10; a++)
//    {
//        if ( cumSum[a-1] < cumSum[a] )
//        {
//            cout << "a = " << a << endl;
//            cout << cumSum[a] << endl;
//        }
//    }
//    cout << endl;
    for (setLLIt = setLL.begin(); setLLIt != setLL.end(); setLLIt++)
    {
        current = *setLLIt;
        probAns = 0;
        for (b = 2; current*b <= aAr[n]+current; b++)
        {
            elementsBetween = ( cumSum[ min(current*b-1, 200005LL) ] - cumSum[ min(current*(b-1)-1, 200005LL) ] );
            //cout << "elementsBetween = " << elementsBetween << endl;
            addee = elementsBetween * (b-1) * current;
            probAns += addee;
            previousVal = totalPrev;
        }
        //cout << "probAns = " << probAns << endl;
        ans = max(probAns, ans);
    }
    cout << ans << endl;
    return 0;
}
