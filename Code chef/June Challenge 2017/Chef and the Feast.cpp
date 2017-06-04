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
long long T, N, aAr[SIZE];
vector<long long> minNum;
long long p, x, ans;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
    for (a = 1;  a <= T; a++)
    {
//        cout << "a  = " << a << endl;
        minNum = vector<long long>();
        p = 0;
        x = 0;
        ans = 0;
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &aAr[b]);
//            minNum.push_back( aAr[b] );
            if ( aAr[b] >= 0 )
            {
                p++;
                x += aAr[b];
            }
            else
            {
                minNum.push_back( aAr[b] );
            }
        }
//        cout << "x  = " << x << endl;
//        x = x*p;
        sort(minNum.begin(), minNum.end());
        reverse(minNum.begin(), minNum.end());
        for (b = 0; b < minNum.size(); b++)
        {
//            cout << "b = " << b << endl ;
            if ( x + p*minNum[b] >= 0 )
            {
                x += minNum[b] ;
                p++;
//                cout << "x = " << x << endl;
//                cout << "p = " << p << endl;
            }
            else
            {
                break;
            }
        }
        ans = p*x;
//        cout << "ans = " << ans << endl;
        for (; b < minNum.size(); b++)
        {
//            cout << "b = " << b << endl;
//            cout << "minNum[b] = " << minNum[b] << endl;
            ans += minNum[b];
        }
        cout << ans << endl;
    }
    return 0;
}
