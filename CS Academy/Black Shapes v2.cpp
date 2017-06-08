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
/******   END OF HEADER *********/
#define SIZE 1009
struct twoDIdx
{
    long long x, y;
    twoDIdx(){}
    twoDIdx(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
};
map<long long , long long> sizeMap;
long long N, M, grid[SIZE][SIZE];
long long col[SIZE][SIZE];
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
bool ifOk(long long x, long long y)
{
    if (x <= 0 || x > N) return false;
    if (y <= 0 || y > M) return false;
    return col[x][y] == -1;
}
vector<twoDIdx> vec;
void dfs(long long x, long long y, long long cnt)
{
    if ( ! ifOk(x, y) )
    {
        return;
    }
    col[x][y] = cnt;
    vec.push_back( twoDIdx(x, y) );
    long long a, b, c, d, e;
    for (a = 0; a < 4; a++)
    {
        dfs( x+dx[a], y+dy[a], cnt );
    }
}
void handleVec(long long cnt)
{
    long long a, b, c, d,e ;
    sizeMap[ cnt ] = vec.size();
//    for ( a = 0; a < vec.size(); a++ )
//    {
//        col[ vec[a].x ][ vec[a].y ] = vec.size();
//    }
}
long long ans;

int main()
{
//    freopen("input.txt", "r", stdin);
    memset(col, -1, sizeof(col));
    long long a, b, c, d, e, f;
    cin >> N >> M;
    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= M; b++)
        {
            scanf("%lld", &grid[a][b]);
            if ( grid[a][b] == 0 )
            {
                col[a][b] = 0;
            }
        }
    }
    long long cnt = 0;
    for (a = 1; a <= N; a++)
    {
        for (b= 1; b <= M; b++)
        {
            vec = vector<twoDIdx >();
            dfs(a, b, ++cnt);
            ans = max(ans, (long long)vec.size());
            handleVec(cnt);
        }
    }
    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= M; b++)
        {
            if ( grid[a][b] )
            {
                continue;
            }
            long long posAns = 1;
            set<long long> regSet;
            for (c = 0 ; c < 4; c++)
            {

                regSet.insert( col[ a+dx[c] ][ b+dy[c] ] );
            }
            for ( set<long long>::iterator setLLIt = regSet.begin(); setLLIt != regSet.end();
                setLLIt++)

            {
                posAns += sizeMap[ *setLLIt ];
            }
            ans = max(ans, posAns);
        }
    }
    cout << ans;
    return 0;
}
