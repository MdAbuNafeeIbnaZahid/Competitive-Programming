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
long long n, k;
long long aAr[SIZE], bAr[SIZE];
long long a, b, c, d,e , f;
long long ans;
struct item
{
    long long bef, af, dif;
    item(){}
    item(long long bef, long long af)
    {
        this->bef = bef;
        this->af = af;
        dif = bef - af;
    }
    bool operator < ( const item B ) const
    {
        return dif < B.dif;
    }
};
multiset<item> setItem;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long alreadyBought = 0;
    cin >> n >> k;
//    cout << "n = " << n << ", k = " << k << endl;
    for ( a = 1; a <= n; a++ )
    {
        scanf("%lld", &aAr[a]);
    }
    for ( a = 1; a <= n; a++ )
    {
        scanf("%lld", &bAr[a]);
    }
    for ( a = 1; a <= n; a++ )
    {
        if ( aAr[a] <= bAr[a] )
        {
            ans += aAr[a];
            alreadyBought++;
        }
        else
        {
            setItem.insert( item( aAr[a], bAr[a] ) );
        }
    }
//    cout << "alreadyBought = " << alreadyBought << endl;
    while( alreadyBought < k )
    {
        item cur = *setItem.begin();
        setItem.erase( setItem.begin() );
        ans += cur.bef;
        alreadyBought++;
//        cout << "ans = " << ans << endl;
    }
    while( setItem.size() )
    {
        item cur = *setItem.begin();
        setItem.erase( setItem.begin() );
        ans += cur.af;
    }
    cout << ans;
    return 0;
}

