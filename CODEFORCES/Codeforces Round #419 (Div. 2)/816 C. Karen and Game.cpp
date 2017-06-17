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
#define SIZE 109

LL inGrid[SIZE][SIZE], n, m, firRowMin = INT_MAX;

set< PairLL > ansSet;

void up(LL gridToUp[SIZE][SIZE], LL row, LL col, LL val, LL willPrin)
{
    LL a, b, c, d;
    if ( row )
    {
        for (a = 1; a <= m; a++)
        {
            gridToUp[ row ][ a ] += val;
        }

        if ( willPrin )
        {
            for (a = 1; a <= val; a++)
            {
                printf("row %lld\n", row);
            }
        }
    }

    else
    {
        for (a = 1; a <= n; a++)
        {
            gridToUp[ a ][ col ] += val;
        }

        if ( willPrin )
        {
            for (a = 1; a <= val; a++)
            {
                printf("col %lld\n", col);
            }
        }
    }
}

LL isMatch(LL gridA[SIZE][SIZE], LL gridB[SIZE][SIZE])
{
    LL a, b, c, d;
    for ( a= 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            if ( gridA[a][b] != gridB[a][b] )
            {
                return 0;
            }
        }
    }
    return 1;
}

LL getReqMov(LL firRowMov, LL willPrin)
{
    LL workGrid[SIZE][SIZE];
    LL a, b, c, d, e, ret = 0;
    RESET(workGrid);
    up(workGrid, 1, 0, firRowMov, willPrin);
    ret += firRowMov;
    for ( a= 1; a <= m; a++)
    {
        if ( workGrid[1][ a ] < inGrid[1][ a ] )
        {
            LL dif = inGrid[1][ a ] - workGrid[1][ a ];
            up(workGrid, 0, a, dif, willPrin );
            ret += dif;
        }
    }
    for ( a = 2; a <= n; a++)
    {
        if ( workGrid[a][ 1 ] < inGrid[ a ][ 1 ] )
        {
            LL dif = inGrid[ a ][ 1 ] - workGrid[a][ 1 ];
            up(workGrid, a, 0, dif, willPrin);
            ret += dif;
        }
    }
    if ( ! isMatch(inGrid, workGrid) )
    {
        return INT_MAX;
    }
    return ret;
}


int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;
    cin >> n >> m;
    for ( a= 1;  a <= n; a++)
    {
        for (b=1; b <= m; b++)
        {
            scanf("%lld", &inGrid[a][b]);
        }
    }
    for (a = 1; a <= m; a++)
    {
        firRowMin = min(firRowMin, inGrid[1][ a ] );
    }

    for (a = 0; a <= firRowMin; a++)
    {
        LL reqMov = getReqMov( a, 0 );
        ansSet.insert( MP(reqMov, a) );
    }

    PairLL ansP = *ansSet.begin();

    if ( ansP.first >= INT_MAX )
    {
        cout << -1;
        return 0;
    }

    cout << ansP.first << endl;;
    getReqMov( ansP.second, 1 );

    return 0;
}
