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
#define SIZE 3000009
LL n, kAr[SIZE];
string tAr[SIZE];
char ansStr[SIZE];
set<PairLL> setPair;
LL strUpto, doneUpto;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n;


//    DBG(n);
//    return 0;
    FOR(a,1,1+n)
    {
//        DBG(a);
        getchar();
        while(1)
        {
            char ch = getchar();
//            DBG(ch);
//            scanf("%c", &ch);
            if ( ch == ' ' )
            {
                break;
            }
            tAr[a].PUB( ch );
        }
//        DBG( tAr[a] );
        scanf("%lld", kAr+a);
        LL len = tAr[a].size();
        FOR(b,1,kAr[a]+1)
        {
            LL xi;
            scanf("%lld", &xi);
            setPair.insert( MP(xi, a) );
            strUpto = max(strUpto, xi+len-1);
        }
    }


    while( setPair.size() )
    {
        PairLL cur = *setPair.begin();
        setPair.erase( setPair.begin() );
        LL si = cur.first;
        LL strIdx = cur.second;
        LL ei = si + tAr[ strIdx ].size() - 1;
        FOR(a,max(doneUpto+1, si),ei+1)
        {
            ansStr[a] = tAr[ strIdx ][ a-si ];
        }
        doneUpto = max(doneUpto, ei);
    }

    FOR(a,1,strUpto+1)
    {
        if ( ansStr[a] )
        {
            printf("%c", ansStr[a]);
        }
        else
        {
            printf("%c", 'a');
        }
    }


    return 0;
}

