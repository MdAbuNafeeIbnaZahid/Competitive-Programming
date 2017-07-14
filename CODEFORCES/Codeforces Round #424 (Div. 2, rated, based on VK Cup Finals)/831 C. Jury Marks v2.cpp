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
#define SIZE 2009
LL k, n, aAr[SIZE], bAr[SIZE];
set<LL> aSet, bSet;
vector<LL> bVec, aVec;
LL ans;

vector<LL> setToVec( set<LL> inSet )
{
    LL a, b, c, d;
    vector<LL> ret;
    set<LL>::iterator setLLIt;
    for(setLLIt = inSet.begin(); setLLIt != inSet.end(); setLLIt++)
    {
        ret.PB( *setLLIt );
    }
    return ret;
}

LL isPos(vector<LL> factVec, vector<LL> remVec)
{
    LL a, b, c, d, e;
    LL initVal;
    if ( factVec.size() < remVec.size() )
    {
        return 0;
    }
    initVal = remVec[ remVec.size()-1 ] - factVec[ factVec.size() -1 ];
//    DBG( initVal );
    while( factVec.size() && remVec.size() )
    {
        LL curFact = factVec[ factVec.size() -1 ];
//        DBG( curFact );
        LL curRem = remVec[ remVec.size()-1 ];
//        DBG( curRem );
        if ( initVal + curFact == curRem )
        {
            remVec.pop_back();
            factVec.pop_back();
        }
        else
        {
//            remVec.pop_back();
            factVec.pop_back();
        }
    }
    return remVec.size()==0;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> k >> n;
    LL curMark = 0;
//    DBG(k);
//    DBG(n);
    FOR(a,1,1+k)
    {
        LL ai;
        scanf("%lld", &aAr[a]);
        curMark += aAr[a];
        aSet.insert( curMark );
    }
    aVec = setToVec( aSet );
    FOR(a,1,1+n)
    {
        LL bi;
        scanf("%lld", &bi);
        bVec.PB( bi );
    }
    SORT(bVec);
    while( aVec.size() )
    {
//        printVecLL( aVec );
        LL addee = isPos( aVec, bVec );;

//        DBG(addee);
        ans += addee;
        aVec.pop_back();
    }
    cout << ans;
    return 0;
}

