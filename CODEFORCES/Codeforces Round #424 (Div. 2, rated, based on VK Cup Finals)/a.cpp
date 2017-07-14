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
#define MP              make_pair
#define PB				push_back

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)

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


void printMapLLLL( map<LL, LL> mapToPr )
{
    LL a, b, c, d, e;
    map<LL, LL>::iterator mapIt;
    cout << endl;
    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
    {
        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
    }
    cout << endl;
}


/******   END OF HEADER *********/
#define SIZE 1009
#define INC 1
#define CONS 2
#define DEC 3
LL n, aAr[SIZE];
LL isInc(LL si, LL ei, LL typ)
{
    LL a, b, c, d, dif;
    FOR(a,si, ei)
    {
        if ( typ==INC && aAr[a]>=aAr[a+1] )
        {
            return 0;
        }
        else if ( typ==CONS && aAr[a]!=aAr[a+1] )
        {
            return 0;
        }
        else if ( typ==DEC && aAr[a]<=aAr[a+1] )
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n;
    FOR(a,1,n+1)
    {
        cin >> aAr[a];
    }
    LL ans = 0;
    FOR(a,1,n+1)
    {
        FOR(b,a,n+1)
        {
            if ( isInc(1,a,INC) && isInc(a,b,CONS) && isInc(b,n,DEC) )
            {
                ans = 1;
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
