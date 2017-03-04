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
#define SIZE 500009
long long n;
char *strAr[SIZE];
char strIn[SIZE];
long long handle(char *s1, char *s2)
{
    long long a, b, c, d, e, len1 = strlen(s1), len2 = strlen(s2);
    for ( a = 0; a < min(len1, len2) ; a++ )
    {
        if ( s1[a] < s2[a] )
        {
            return 1;
        }
        else if ( s1[a] > s2[a] )
        {
            s1[ a  ] = '\0';
            return 2;
        }
    }
    if ( len1 > len2 )
    {
        s1[ len2 ] = '\0';
        return 3;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e;
    cin >> n;
    for (  a = 1; a <= n; a++ )
    {
        long long len;
        scanf("%s", strIn);
        len = strlen( strIn );
        strAr[a] = new char[ len + 9 ];
        strcpy( strAr[a], strIn );
    }
    for ( a = n; a > 1; a-- )
    {
        handle( strAr[a-1], strAr[a] );
    }
    for ( a = 1; a<= n; a++ )
    {
        printf("%s\n", strAr[a]);
    }
    return 0;
}

