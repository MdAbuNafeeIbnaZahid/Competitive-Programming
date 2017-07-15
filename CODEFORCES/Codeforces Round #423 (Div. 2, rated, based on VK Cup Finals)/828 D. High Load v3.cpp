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
#define SIZE 200009
LL n, k;
vector<LL> layer[SIZE];
LL doneUpto, curLayer, rem, maxDis;
void printEdge(vector<LL> low, vector<LL> high)
{
    LL a, b, c, d, e, f;
    LL highFir = high[0];
    while( low.size() && high.size() )
    {
        printf( "%lld %lld\n", low[ low.size()-1 ], high[ high.size()-1 ] );
        low.POB();
        high.POB();
    }
    while( low.size() )
    {
        printf( "%lld %lld\n", low[ low.size()-1 ], highFir );
        low.POB();
    }
}
void printTree()
{
    LL a, b, c, d, e;
//    cout << "in printTree()" << endl;
    FOR(a,1,SIZE)
    {
//        DBG(a);
        if ( layer[a+1].size() == 0 )
        {
            break;
        }
        printEdge( layer[a], layer[a+1] );

    }
    if ( layer[a].size() == 2 )
    {
        cout << layer[a][0] << " " << layer[a][1];
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k;
    rem = n;
    while( rem > 0 )
    {
//        DBG(rem);
        curLayer++;
//        DBG(curLayer);
        if ( rem > k )
        {
//            cout << "rem > k" << endl;
            FOR(a,1,1+k)
            {
                layer[ curLayer ].PUB( ++doneUpto );
            }
            maxDis+=2;
            rem -= k;
        }
        else
        {
//            cout << "rem <= k" << endl;
            if ( rem == 1 )
            {
                layer[ curLayer ].PUB( ++doneUpto );
                maxDis+=2;
            }
            else if ( rem == 2 )
            {
                layer[ curLayer ].PUB( ++doneUpto );
                layer[ curLayer ].PUB( ++doneUpto );
                maxDis+=3;
            }
            else
            {
                FOR(a,1,rem)
                {
                    layer[ curLayer ].PUB( ++doneUpto );
                }
                curLayer++;
                layer[ curLayer ].PUB( ++doneUpto );
                maxDis+=4;
            }
            rem = 0;
        }
        // Need to handle maxDistance
    }
    maxDis -= 2;
    cout << maxDis << endl;
    printTree();
    return 0;
}

