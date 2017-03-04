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
long long n, minFl, maxFl;
char str1[SIZE], str2[SIZE];
char cs1[SIZE], cs2[SIZE];
vector<char> v1, v2;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    long long len;
    cin >> n;
    scanf("%s", str1);
    scanf("%s", str2);
    sort(str1, str1+n);
    sort(str2, str2+n);

    //cout << str2 << endl;

    // min fl
//    strcpy(cs1, str1);
//    strcpy(cs2, str2);
//
    for ( a = 0; a < n; a++ )
    {
        v1.push_back( str1[a] );
        v2.push_back( str2[a] );
    }

    while( v1.size() )
    {
        len = v1.size()-1;
        if ( v1[len] > v2[len] )
        {
            minFl++;
            v1.pop_back();
            v2.erase( v2.begin() );
        }
        else
        {
            v1.pop_back()  ;
            v2.pop_back();
        }
    }


    //  maxFl
    v1 = vector<char>();
    v2 = vector<char>();
    for ( a = 0; a < n; a++ )
    {
        v1.push_back( str1[a] );
        v2.push_back( str2[a] );
    }

    while( v1.size() && v2.size() )
    {
        if ( v2[0] > v1[0] )
        {
            maxFl++;
            v1.erase( v1.begin() );
            v2.erase( v2.begin() );
        }
        else
        {
            v2.erase( v2.begin() );
        }
    }
    cout << minFl << " " << maxFl;
    return 0;
}


