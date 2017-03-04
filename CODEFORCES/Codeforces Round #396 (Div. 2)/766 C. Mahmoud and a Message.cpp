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
#define MOD 1000000007
long long n, aAr[SIZE], charCnt[SIZE][SIZE], ifNotOk[SIZE][SIZE], charCntSpec, maxLen;
long long waysDp[SIZE], minSubstr[SIZE];
char str[SIZE], ch;
long long a, b, c, d, e, f;
long long len;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", str);
    for (a = 'a'; a <= 'z'; a++)
    {
        cin >> aAr[a];
    }
    for (a = 0; a < n; a++)
    {
        ch = str[a];
        if ( a > 0 )
        {
            for (b = 'a'; b <= 'z'; b++)
            {
                charCnt[a][b] = charCnt[a-1][b];
            }
        }
        charCnt[a][ ch ]++;
    }
    for ( a = 0; a < n; a++)
    {
        for (b = a; b < n; b++)
        {
            len = b-a+1;
            for (c = 'a'; c <= 'z'; c++)
            {
                if ( a > 0 )
                {
                    charCntSpec = charCnt[b][c] - charCnt[a-1][c];
                }
                else
                {
                    charCntSpec = charCnt[b][c] ;
                }
                ifNotOk[a][b] = ifNotOk[a][b] || ( ( charCntSpec) && (len > aAr[c] ) );
            }
        }
    }

    waysDp[n] = 1;
    for (a = n-1; a >= 0; a--)
    {
        for ( b = a; b < n; b++ )
        {
             if ( ifNotOk[a][b] )
             {
                break;
             }
             waysDp[a] = ( (waysDp[a]%MOD) +  (waysDp[b+1]%MOD ) ) %MOD;
        }
    }

    cout << waysDp[0] << endl;

    for (a = 0; a < n; a++)
    {
        for (b = a; b < n; b++)
        {
            if ( ifNotOk[a][b] )
            {
                continue;
            }
            maxLen = max(maxLen,  (b-a+1) );
        }
    }
    cout << maxLen << endl;

    minSubstr[n] = 0;
    for (a = n-1; a >= 0; a--)
    {
        minSubstr[a] = INT_MAX;
        for ( b = a; b < n; b++ )
        {
             if ( ifNotOk[a][b] )
             {
                break;
             }
             minSubstr[a] = min( minSubstr[a], minSubstr[b+1]+1);
        }
    }
    cout << minSubstr[0];


    return 0;
}

