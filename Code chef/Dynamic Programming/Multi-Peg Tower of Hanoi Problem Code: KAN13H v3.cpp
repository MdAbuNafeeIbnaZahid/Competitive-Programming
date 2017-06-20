#include <bits/stdc++.h>
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
#define SIZE 59
LL T, N, P, K;
        // peg  diskCnt
LL minMov[SIZE][SIZE], n1[SIZE][SIZE];

void solv()
{
    LL a, b, c, d, e;
    for (a = 0;a  < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            minMov[a][b] = (1LL<<62);
        }
    }
    for (a = 1; a < SIZE; a++)
    {
        minMov[a][1] = 1;
    }
//    for (a = 2; a < SIZE; a++)
//    {
//        minMov[3][a] = minMov[3][a-1] * 2 + 1;
//    }
    for ( a = 3; a < SIZE; a++) // peg
    {
        for (b = 2; b < SIZE; b++)  // number of disk
        {
            for (c = 1; c < b; c++) // loop of n1
            {
                if ( minMov[a][b] > 2*minMov[a][c] + minMov[a-1][b-c] )
                {
                    n1[a][b] = c;
                    minMov[a][b] = 2*minMov[a][c] + minMov[a-1][b-c];
                }
            }
        }
    }
}

LL calc(LL peg, LL disk, LL kth)
{
//    if ( peg == 3 )
//    {
//        return ( ( 1LL<<(disk-kth+1) ) -1 );
//    }
//    else


    if ( kth == 1 )
    {
        return minMov[peg][disk];
    }
    else
    {
        LL n1Val = n1[peg][disk];
        if ( kth <= n1Val )  // case 1
        {
            return minMov[peg-1][ disk-n1Val ] + minMov[peg][n1Val] +
                    calc( peg, n1Val, kth);
        }
        else   // case 2
        {
            return minMov[peg][n1Val] + calc(peg-1, disk-n1Val, kth-n1Val);
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    solv();
//    cout << "minMov" << endl;
//    for (a = 3;a <= 5; a++)
//    {
//        for (b = 1; b <= 9; b++)
//        {
//            cout << minMov[a][b] << "(" << n1[a][b] << ")" << " ";
//        }
//        cout << endl;
//    }
//    cout << endl << endl << endl;
//    cout << "n1" << endl;
//    for (a = 3;a <= 5; a++)
//    {
//        for (b = 1; b <= 9; b++)
//        {
//            cout << n1[a][b] << " ";
//        }
//        cout << endl;
//    }
    cin >> T;
    FOR(a,1,T)
    {
        scanf("%lld %lld %lld", &N, &P, &K);
        LL ans = calc(P, N, K);
        printf("Case %lld: %lld\n",a,ans);
    }
    return 0;
}

