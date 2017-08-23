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



/******   END OF HEADER *********/


#define SIZE 109
LL n, q, c;
vector<LL> matrix[SIZE][SIZE];
LL brightCnt[SIZE][SIZE][SIZE], brightCumSum[SIZE][SIZE][SIZE];

LL getSumOfVector(vector<LL> vec)
{
    LL a, b, c, d, e, f;
    LL ret = 0;
    FOR(a,0,vec.size())
    {
        ret += vec[a];
    }
    return ret;
}

LL addTimeAndGetSum( vector<LL> vec, LL t )
{
    LL a, b, d, e, f;
    FOR(a,0,vec.size())
    {
        vec[a] = (vec[a]+t)%(c+1);
    }
    return getSumOfVector( vec );
}

void getBrightCnt()
{
    LL a, b, c, d, e;
    FOR(a,0,15)
    {
        FOR(b, 0, SIZE)
        {
            FOR(c, 0, SIZE)
            {
                brightCnt[ a ][ b ][ c ] = addTimeAndGetSum( matrix[b][c], a );
            }
        }
    }
}

void calcCumSum( LL cumSumAr[SIZE][SIZE], LL ar[SIZE][SIZE] )
{
    LL a, b, c, d, e, f;
    FOR(a,1,SIZE)
    {
        FOR(b,1,SIZE)
        {
            cumSumAr[a][b] = ar[a][b] + cumSumAr[a-1][b] + cumSumAr[a][b-1] - cumSumAr[a-1][b-1];
        }
    }
}


LL getRectSum(LL cumSumAr[SIZE][SIZE], LL a, LL b, LL c, LL d)
{
    if ( a > c ) swap(a,c);
    if ( b > d ) swap(b, d);
    a--;
    b--;
    return cumSumAr[c][d] - cumSumAr[a][d] - cumSumAr[c][b] + cumSumAr[a][b];
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL i, j, k, m, p, a, b;
    cin >> n >> q >> c;
    FOR(i,1,1+n)
    {
        LL xi, yi, si;
        scanf("%lld %lld %lld", &xi, &yi, &si);
        matrix[xi][yi].push_back( si );
    }
    getBrightCnt();

    FOR(a,0,15)
    {
        calcCumSum( brightCumSum[a], brightCnt[a] );
    }

    FOR(a,1,1+q)
    {
        LL ti, x1i, y1i, x2i, y2i;
        scanf("%lld %lld %lld %lld %lld", &ti, &x1i, &y1i, &x2i, &y2i);
        LL ans = getRectSum( brightCumSum[ti%(c+1)], x1i, y1i, x2i, y2i );
        printf("%lld\n", ans);
    }

    return 0;
}
