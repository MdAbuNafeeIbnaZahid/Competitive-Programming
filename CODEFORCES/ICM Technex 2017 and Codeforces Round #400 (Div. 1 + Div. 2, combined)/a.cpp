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
#define SIZE
struct namePair
{
    string fir, sec;
    namePair(){}

};
long long n;

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    string s1, s2;
    cin >> s1 >> s2;
    namePair np;
    cout << s1 << " " << s2 << endl;
    cin >> n;
//    cout << "n = " << n << endl;
    for ( a = 1; a<= n; a++ )
    {
        string str1, str2;
        cin >> str1 >> str2;

        if ( s1 == str1 )
        {
            s1 = str2;
        }
        else if ( s2 == str1 )
        {
            s2 = str2;
        }
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}
