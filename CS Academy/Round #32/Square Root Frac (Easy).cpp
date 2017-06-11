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
long long T, num;
double dob;
double llToDob(long long n)
{
    double ret = 0, mul = n;
    long long a, b, c, d, e;
    for (a = 1; a <= 9; a++)
    {
        mul *= 0.1;
    }
    return mul;
}
double minError = 9;
long long ans;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, e;
    cin >> T;
    for (a= 1; a <= T; a++)
    {
        minError = 9;
        cin >> num;
//        cout << "num = " << num << endl;
        dob = llToDob(num);
//        cout << llToDob(num);
//        cout << "dob = " << dob << endl;
        for (b = 0; b < SIZE; b++)
        {
            double check = (dob+b) * (dob+b);
//            cout << "check = " << check << endl;
            double error = abs(round(check) - check );
            if ( error < minError )
            {
                ans = (int)round(check);
                minError = error;
            }
//            if ( abs(round(check) - check ) < SM )
//            {
////                long long ans = round(check);
//                cout << ans  << endl;;
//                break;
//            }
        }
        cout << ans << endl;
    }
    return 0;
}
