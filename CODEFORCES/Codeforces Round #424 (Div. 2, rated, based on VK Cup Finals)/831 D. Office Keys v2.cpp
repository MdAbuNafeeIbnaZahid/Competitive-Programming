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
#define PUB				push_back
#define POB				pop_back

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
#define SIZE 2009
LL n, k, p;
vector<LL> aVec, bVec;
LL isPos(vector<LL> manVec, vector<LL> keyVec, LL val)
{
    LL a, b, c, d, e, f;
    while( manVec.size() && keyVec.size() )
    {
        LL curMan = manVec[ manVec.size()-1 ];
        LL curKey = keyVec[ keyVec.size() - 1 ];
        keyVec.POB();
        if ( abs(curMan-curKey) + abs(curKey-p) <= val )
        {
            manVec.POB();
        }
    }
    return manVec.size()==0;
}

LL binSearch(LL minVal, LL maxVal)
{
    LL a, b, c, d, e, f, midVal = (minVal+maxVal)/2;
    if ( minVal==maxVal )
    {
        return minVal;
    }

    if ( isPos(aVec, bVec, midVal) )
    {
        return binSearch(minVal, midVal);
    }
    else
    {
        return binSearch(midVal+1, maxVal);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k >> p;
    FOR(a,1,1+n)
    {
        LL ai;
        scanf("%lld", &ai);
        aVec.PUB(ai);
    }
    SORT(aVec);
    FOR(a,1,1+k)
    {
        LL bi;
        scanf("%lld", &bi);
        bVec.PUB(bi);
    }
    SORT(bVec);
    LL ans = binSearch(0, INT_MAX*SIZE*SIZE);
    cout << ans;
    return 0;
}

