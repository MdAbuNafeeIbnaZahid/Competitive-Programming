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
struct range
{
    long long xi, yi, ri;
    range(){}
    range(long long xi, long long yi, long long ri)
    {
        this->xi = xi;
        this->yi = yi;
        this->ri = ri;
    }
    bool operator < (const range B) const
    {
        if ( ri == B.ri )
        {
            if ( xi == B.xi )
            {
                return yi < B.yi;
            }
            return xi < B.xi;
        }
        return ri < B.ri;
    }
};
long long n, xi, yi, ri;
set<range> setR;
vector<range> vec[9];
double ans = 0;
bool ifIn(range big, range small)
{
    bool ret = (big.ri > small.ri);
    ret = ret &&
    ( (small.xi-big.xi)*(small.xi-big.xi) + (small.yi-big.yi)*(small.yi-big.yi)
    < big.ri*big.ri  );
    return ret;
}
long long findCnt(long long vecIdx, range ra)
{
    long long ret = 0, a, b, c, d, e;
    for ( a = 0; a < vec[vecIdx].size(); a++ )
    {
        ret += ifIn( vec[ vecIdx ][a], ra );
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d,e ;
    double pi = acos(-1);
//    cout << "pi = " << pi << endl;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld %lld %lld", &xi, &yi, &ri);
        setR.insert( range(xi, yi, ri) );
    }
//    reverse( setR.begin(), setR.end() );
    for ( set<range>::reverse_iterator rit = setR.rbegin(); rit != setR.rend(); rit++ )
    {
        range cur = *rit;
//        setR.erase( setR.rbegin() );
//        cout << cur.xi << " " << cur.yi << " " << cur.ri << endl;
        if ( findCnt(0, cur) & 1 ) // odd number of collision
                                    // even cover
        {
            if ( findCnt(1, cur) & 1 ) // odd number of collision
                                    // even cover
            {
                ans -= (cur.ri*cur.ri);
            }
            else
            {
                ans += (cur.ri*cur.ri);
            }
            vec[1].push_back(cur);
        }
        else
        {
            vec[0].push_back( cur );
            ans += (cur.ri*cur.ri);
        }
    }
    ans = pi * ans;
    printf("%0.10lf", ans);
    return 0;
}
