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


void printLLArray( LL *ar, LL si, LL ei )
{
    LL a, b, c, d, e;
    FOR(a, si, ei+1)
    {
        printf("ar[ %lld ] = %lld\n\n", a, ar[a]);
    }
}


void  printSetPair( set<PairLL> givenSetPair )
{
    for ( auto it : givenSetPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;
}

void printVecPair( vector<PairLL> givenVecPair )
{
    for ( auto it : givenVecPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;
}



LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};




/******   END OF HEADER *********/
#define SIZE 109
#define UP 0
#define LEFT 1

LL T, n, m;

char grid[SIZE][SIZE];
LL fearGrid[SIZE][SIZE], dp[SIZE][SIZE][9];


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    cin >> T;
    FOR(a,1,1+T)
    {
        RESET(grid);
        RESET(fearGrid);
        FOR(b,0,SIZE)
        {
            FOR(c,0,SIZE)
            {
                dp[b][c][0] = INT_MAX;
                dp[b][c][1] = INT_MAX;
            }
        }
//        dp[1][1][UP] = dp[1][1][DOWN] =
//            ( grid[1][1]=='1' + grid[2][1]=='1' + grid[] )
        cin >> n >> m;
        FOR(b,1,1+n)
        {
            scanf("%s", grid[b]+1);
        }
        FOR(b,1,1+n)
        {
            FOR(c,1,m+1)
            {
                if ( grid[b][c] == '1' )
                {
                    fearGrid[b][c]--;
                    FOR(d,0,4)
                    {
                        fearGrid[ b+dirR[d] ][ c+dirC[d] ]++;
                    }
                }
            }
        }
        dp[1][1][UP] = dp[1][1][LEFT] = fearGrid[1][1];
        FOR(b,1,1+n)
        {
            FOR(c,1,1+m)
            {
                if ( b ==1 && c==1 )
                {
                    continue;
                }
                // handle up
                dp[b][c][ UP ] = min( dp[b][c][UP], dp[b-1][c][UP] + fearGrid[b][c] );
                dp[b][c][ UP ] = min( dp[b][c][UP], dp[b-1][c][LEFT] + fearGrid[b][c]
                            - ( grid[b][c-1]=='1' ) );

                // handle down
                dp[b][c][ LEFT ] = min( dp[b][c][LEFT], dp[b][c-1][LEFT] + fearGrid[b][c] );
                dp[b][c][ LEFT ] = min( dp[b][c][LEFT], dp[b][c-1][UP] + fearGrid[b][c]
                       - ( grid[b-1][c]=='1' ) );
            }
        }

        LL ans = min( dp[n][m][UP], dp[n][m][LEFT] );
        ans += (grid[1][1]=='1');
        ans += (grid[n][m]=='1');
        cout << ans << endl;
    }
    return 0;
}
