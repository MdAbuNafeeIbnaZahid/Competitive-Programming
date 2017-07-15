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


struct BIT
{
    LL siz, *treeAr;
    BIT(){}
    BIT(LL siz)
    {
        this->siz = siz;
        treeAr = new LL[siz+9];
        memset(treeAr, 0, sizeof(treeAr) );
    }

    LL read(LL idx)
    {
        LL ret = 0;
        while( idx > 0 )
        {
            ret += treeAr[idx];
            idx -= ( idx & -idx );
        }
        return ret;
    }

    void update(LL idx, LL val)
    {
        while( idx <= siz )
        {
            treeAr[idx] += val;
            idx += ( idx & -idx );
        }
    }
};


#define SIZE 109
char grid[SIZE][SIZE];
LL n, m;
LL blackCnt, minSide, mostLeft, mostRight, mostUp, mostDown, sqSide;

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> m;
    minSide = min(n, m);
//    DBG(minSide);
    FOR(a,1, 1+n)
    {
//        scanf("%s", grid[a]+1);
        getchar();
        FOR(b,1,1+m)
        {
            char ch;
            scanf("%c", &ch);
            grid[a][b] = ch;
//            DBG(a);
//            DBG(b);
//            DBG(ch);
            if ( ch == 'B' )
            {
                blackCnt++;
                if ( !mostLeft )
                {
                    mostLeft = b;
                }
                if ( !mostUp )
                {
                    mostUp = a;
                }
                mostLeft = min(mostLeft, b);
                mostRight = max(mostRight, b);
                mostDown = a;
            }
        }
    }
//    DBG(mostLeft);
//    DBG(mostRight);
//    DBG(mostUp);
//    DBG(mostDown);
//    DBG(blackCnt);
    if ( blackCnt==0 )
    {
        cout << 1;
        return 0;
    }
    sqSide = max(mostRight-mostLeft, mostDown-mostUp);
    sqSide++;
//    DBG(sqSide);
    if  ( sqSide > minSide )
    {
        cout << -1;
        return 0;
    }
    LL ans = sqSide*sqSide - blackCnt;
    cout << ans;
    return 0;
}

