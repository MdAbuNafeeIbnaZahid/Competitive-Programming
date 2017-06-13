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
#define LL long long
/******   END OF HEADER *********/
LL t, x, y, p, q;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    cin >> t;
    for (a = 1; a <= t; a++)
    {


        scanf("%lld %lld %lld %lld", &x, &y, &p, &q);

//        cout << "x = " << x  << endl;
//        cout << "y = " << y  << endl;
//        cout << "p = " << p  << endl;
//        cout << "q = " << q  << endl;


        if ( p == 0 && x != 0)
        {
            printf("%lld\n", -1LL);
            continue;
        }
        if (p==0 && x==0)
        {
            printf("%lld\n", 0LL);
            continue;
        }

//        cout << "x = " << x  << endl;
//        cout << "y = " << y  << endl;
//        cout << "p = " << p  << endl;
//        cout << "q = " << q  << endl;

//        if ( p==1 )
//        {
//            cout << "p==1" << endl;
//        }
//        if ( q==1 )
//        {
//            cout << "q==1" << endl;
//        }
//        if ( x<y )
//        {
//            cout << "x<y" <<endl;
//        }


        if ( (p==1) && (q==1) && (x<y) )
        {
            printf("%lld\n", -1LL);
            continue;
        }
        else
        {
            if ( (x/ (y*1.0) ) >= ( (p/ (q*1.0) ) ) )
            {
                LL up = ceil( (1.0*x) /p);
                LL down = ceil( (1.0*y) /q );
                LL maxUD = max(up, down);
                printf("%lld\n", (maxUD*q)-y );
                continue;
            }
            else
            {
                LL k = ceil( (1.0 * (y-x) ) / (q-p) );
                printf("%lld\n", k*q-y);
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}
