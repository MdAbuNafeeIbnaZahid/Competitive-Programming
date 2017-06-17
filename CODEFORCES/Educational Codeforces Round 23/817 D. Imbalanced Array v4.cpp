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
#define SIZE 1000009
LL n, aAr[SIZE];
set< PairLL > valIdxSet;
set< LL > idxSet;
vector< PairLL > valIdxVec;

set<PairLL> getValIdxSet(LL *ar, LL len)
{
    LL a, b, c, d;
    set< PairLL > ret;
    for (a= 1; a <= len; a++)
    {
        ret.insert( MP( ar[a], a ) );
    }
    return ret;
}

vector<PairLL> getValIdxVec(LL *ar, LL len)
{
    LL a, b, c, d, e;
    vector< PairLL > ret;
    for (a = 1;a  <= len; a++)
    {
        ret.PB( MP( ar[a], a ) );
    }
    return ret;
}


LL getCalcVal( vector< PairLL > viVec )
{
    LL ret = 0, a, b, c, d;
    set<LL> doneSet;
    set<LL>::iterator setLLIt;
    doneSet.insert(0);
    doneSet.insert(n+1);
    while( viVec.size() )
    {
        LL curVal = viVec[ viVec.size() - 1 ].first;
        LL curIdx = viVec[ viVec.size() - 1 ].second;
//        DBG( viVec[ viVec.size() - 1 ] );
//        DBG(curVal);
//        DBG(curIdx);
        viVec.pop_back();


        setLLIt = doneSet.insert( curIdx ).first;

//        setLLIt = doneSet.lower_bound(curIdx);
        setLLIt++;
        LL afIdx = *( setLLIt );
        setLLIt--;
        setLLIt--;
        LL befIdx = *( setLLIt );
//        DBG(befIdx);

//        DBG(afIdx);
        ret += curVal * ( curIdx - befIdx ) * ( afIdx - curIdx );
//        doneSet.insert( curIdx );
    }
    return ret;
}


int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    LL subVal = 0, addVal = 0, ans = 0;
    cin >> n;
//    DBG(n);
    for (a= 1;  a<= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
//    valIdxSet = getValIdxSet( aAr, n );


    valIdxVec = getValIdxVec( aAr, n );
//    cout << "got valIdxVec" << endl;
//    DBG( valIdxVec.size() );
    SORT(valIdxVec);
//    while( valIdxVec.size() )
//    {
//        LL curVal = valIdxVec[ valIdxVec.size() - 1 ].first;
//        LL curIdx = valIdxVec[ valIdxVec.size() - 1 ].second;
//    }
    addVal = getCalcVal( valIdxVec );
//    DBG(addVal);

//    valIdxVec = getValIdxVec( aAr, n );
//    SORT(valIdxVec);
    REV(valIdxVec);
    subVal = getCalcVal(valIdxVec);


    ans = addVal - subVal;
    cout << ans;
    return 0;
}



