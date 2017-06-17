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


#define LL 			long long
#define PairLL		pair<long long, long long>


#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MK              make_pair
#define PB				push_back

#define DBG(x) cout<<#x<<" : "<<x<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


/******   END OF HEADER *********/
#define SIZE 30
LL powTen[SIZE];
LL n, s;

void makePow10()
{
    LL a, b, c, d,e ;
    powTen[0] = 1;
    for (a= 1;  a <SIZE; a++)
    {
        powTen[a] = powTen[a-1] * 10;
    }
}

LL getDif(LL num)
{
    LL ret = 0, copNum = num, pos = 0;
    while( copNum )
    {
        LL dig = copNum % 10LL;
        copNum /= 10LL;
        ret += ( dig * (powTen[pos]-1LL) );
        pos++;
    }
    return ret;
}

LL binSearch(LL lowVal, LL highVal)
{
    LL midVal = (lowVal+ highVal+1)/2LL;
    if ( lowVal == highVal )
    {
        return lowVal;
    }
    if ( getDif(midVal) < s )
    {
        return binSearch(midVal, highVal);
    }
    else
    {
        return binSearch(lowVal, midVal-1LL);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    makePow10();
    cin >> n >> s;
    LL sub = binSearch(9LL, powTen[18] );
//    cout << "sub = " << sub <<endl;
    LL ans = max(0LL, n-sub );
    cout << ans;
    return 0;
}
