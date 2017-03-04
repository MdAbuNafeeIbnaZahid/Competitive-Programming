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
long long n, a, b, c, d, isPres[999];
string str;
long long ifContains(string s, char ch)
{
    long long a, b, c, d;
    for (a = 0; a < s.size(); a++)
    {
        if ( s[a] == ch )
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> str;
//    cout << "str = " << str << endl;
    char ch = 'a';
    for (a = 0; a < str.size(); a++)
    {
        if ( str[a] == '2' )
        {
            continue;
        }
        if ( str[a] != ch )
        {
            cout << "NO";
            return 0;
        }
        for (b = a; b < str.size(); b++)
        {
            if ( str[b] == ch )
            {
                str[b] = '2';
            }
        }
        ch++;
    }
    cout << "YES";


    return 0;
}
