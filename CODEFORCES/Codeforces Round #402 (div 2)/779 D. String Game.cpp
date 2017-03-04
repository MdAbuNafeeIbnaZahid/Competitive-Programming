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
char s1[SIZE], s2[SIZE];
long long aAr[SIZE];
long long check( char *str1, char *str2,  long long *ig, long long upto )
{
    long long a, b, c, d, e;
    char fuS1[SIZE], fuS2[SIZE];
    long long len1 = strlen(str1), len2 = strlen(str2);
//    cout << "len1 = " << len1 << endl;
//    cout << "len2 = " << len2 << endl;
    strcpy(fuS1+1, str1);
    strcpy(fuS2+1, str2);
//    cout << "fuS1 = " << fuS1 << endl;
//    cout << "fuS2 = " << fuS2 << endl;
//    cout << "upto = " << upto << endl;
    for ( a = 1; a <= upto; a++ )
    {
        fuS1[ aAr[a] ] = '#';
    }
//    cout << "changed fuS1 = " << fuS1 << endl;

    long long cnt2 = 0;
    for ( a = 1; a <= len1; a++ )
    {
        if ( fuS1[a] == fuS2[ cnt2+1 ] )
        {
            cnt2++;
        }
        if ( cnt2 >= len2 )
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d,e;
    scanf("%s", s1+1);
    scanf("%s", s2+1);
    long long len = strlen(s1+1);
    for ( a = 1; a <= len; a++ )
    {
        scanf("%lld", &aAr[a]);
    }
    long long minVal = 0, maxVal = strlen(s1+1), midVal;
    while( minVal < maxVal )
    {
//        cout << "minVal = " << minVal << endl;
//        cout << "maxVal = " << maxVal << endl;
        midVal = ceil( ( minVal + maxVal ) / 2.0 );
//        cout << "midVal = " << midVal << endl;
        if ( check(s1+1, s2+1, aAr, midVal) )
        {
            minVal = midVal;
        }
        else
        {
            maxVal = midVal - 1;
        }
//        cout << endl;
    }
    long long ans = maxVal;
    cout << ans;
    return 0;
}

