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
#define SIZE 1009
char s[SIZE], t[SIZE], toPut[SIZE], chS, chT;
long long a, b, c, d, e, f, len, k;
set< pair<char, char> > mySet;
int main()
{
//    freopen("input.txt", "r", stdin);
    memset(toPut, 0, sizeof(toPut) );
    scanf("%s", s);
    scanf("%s", t);
    len = strlen(s);
    //cout << "len = " << len << endl;
    for (a = 0;  a < len; a++)
    {
        chS = s[a];
        chT = t[a];
        if ( toPut[chS] == 0 && toPut[chT]==0 )
        {
            if ( chS > chT )
            {
                swap(chS, chT);
            }
            toPut[chS] = chT;
            toPut[chT] = chS;
            if ( chS != chT )
            {
                mySet.insert( {chS, chT} );
            }

        }
        else if ( toPut[chS]==chT && toPut[chT]==chS )
        {

        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    k = mySet.size();
    cout << k << endl;
    for ( set< pair<char, char> >::iterator setIt = mySet.begin(); setIt != mySet.end(); setIt++ )
    {
        cout << setIt->first << " " << setIt->second << endl;;
    }
    return 0;
}

