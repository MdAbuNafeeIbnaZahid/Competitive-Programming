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
#define SIZE 109
long long n, w, aAr[SIZE];
long long ansAr[SIZE], req, rem;
pair<long long, long long> pairAr[SIZE]; ;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n >> w;
    rem = w;
    for (a = 1; a <= n; a++)
    {
        cin >> aAr[a];
        pairAr[a] = make_pair(aAr[a], a);
        req += (aAr[a]+1)/2;
        ansAr[a] = (aAr[a]+1)/2;
    }
    if (req > w)
    {
        cout << -1;
        return 0;
    }
    rem = w-req;
    sort(pairAr+1, pairAr+n+1);
//    cout << "before while loop" << endl;
    while(rem > 0)
    {
        for (a = n; a >= 1 && rem>0; a--)
        {
            if ( ansAr[ pairAr[a].second ] <  aAr[ pairAr[a].second ]  )
            {
                ansAr[ pairAr[a].second ]++;
                rem--;
            }
        }
    }
    for (a = 1; a <= n; a++)
    {
        cout << ansAr[a] << " ";
    }
    return 0;
}

