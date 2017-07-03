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

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)

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

struct vouch
{
    PairLL pa;
    LL cost;

    vouch(){}
    vouch(LL l, LL r, LL cost)
    {
        pa = MP(l, r);
        this->cost = cost;
    }

    bool operator < ( vouch B ) const
    {
        if ( pa == B.pa )
        {
            return cost < B.cost;
        }
        return pa < B.pa;
    }

    friend ostream &operator << (ostream &stream, vouch ob);
};

ostream &operator<<(ostream &stream, vouch ob)
{
    stream << ob.pa.first << " " << ob.pa.second << " " << ob.cost << endl;
    return stream;
}


set< vouch > startVouch, endVouch;

#define SIZE
LL n, x;
map<LL, LL> cosMap;
LL ans = INT_MAX;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    cin >> n >> x;
    FOR(a,1,n)
    {
        LL li, ri, ci;
        scanf("%lld %lld %lld", &li, &ri, &ci);
        startVouch.insert( vouch(li, ri, ci) );
        endVouch.insert( vouch(ri, li, ci) );
    }

    while( startVouch.size() )
    {
        vouch curVouch = *startVouch.begin();
        startVouch.erase( startVouch.begin() );
        LL curVouchDur = curVouch.pa.second-curVouch.pa.first + 1;

//        DBG(curVouch);
//        cout << curVouch << endl;

        while( (endVouch.begin()->pa).first < curVouch.pa.first )
        {
            vouch curEndVouch = *endVouch.begin();
//            DBG(curEndVouch);
            endVouch.erase( endVouch.begin() );
            LL dur = curEndVouch.pa.first - curEndVouch.pa.second + 1;
//            DBG(dur);
            if ( cosMap[ dur ] == 0 )
            {
                cosMap[ dur ] = curEndVouch.cost;
            }
            cosMap[ dur ] = min(cosMap[dur], curEndVouch.cost);

//            DBG( cosMap[dur] );
        }


        LL tar = x-curVouchDur;
//        DBG(tar);
        if ( cosMap[ tar ] != 0 )
        {
            ans = min(ans, curVouch.cost +  cosMap[ x-curVouchDur ]   );
        }

//        DBG(ans);
    }




//    FOR(a,1,n)
//    {
//        LL li, ri, ci;
//        scanf("%lld %lld %lld", &li, &ri, &ci);
//        LL dur = ri-li+1;
//        if ( cosMap[ x-dur ] != 0 )
//        {
//            ans = min(ans, ci+cosMap[ x-dur ]  );
//        }
//        cosMap[ dur ] = ci;
//    }
    if (ans >= INT_MAX)
    {
        ans = -1;
    }
    cout << ans;
    return 0;
}


