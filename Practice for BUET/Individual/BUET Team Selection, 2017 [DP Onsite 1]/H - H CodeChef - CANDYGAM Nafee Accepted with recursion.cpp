
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
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define LLMAX ( (unsigned long long)(-1LL) >> 1LL )

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



void ILL(LL &u)
{
    LL a, b, c, d;
    scanf("%lld", &u);
}

void ILL2(LL &u, LL &v)
{
    LL a, b, c, d, e;
    scanf("%lld %lld", &u, &v);
}

void ILL3(LL &u, LL &v, LL &w)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld", &u, &v, &w);
}

LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};




/******   END OF HEADER *********/
#define SIZE 59

#define ALICE 0
#define BOB 1

#define FIRST_ROW 2
#define LAST_ROW 3
#define FIRST_COL 4
#define LAST_COL 5

LL dp[SIZE][SIZE][SIZE][SIZE][9];

LL T, N, M, aAr[SIZE][SIZE];


LL cumAar[SIZE][SIZE];

LL getAliceDp(LL u, LL v, LL x, LL y);
LL getBobDp(LL u, LL v, LL x, LL y);

LL getRectSum(LL u, LL v, LL x, LL y)
{
    LL a, b, c, d, e;
    LL ret = 0;
    u--;
    v--;
    return cumAar[x][y] - cumAar[u][y] - cumAar[x][v] + cumAar[u][v];
}



LL getEdgeSum(LL u, LL v, LL x, LL y, LL typ)
{
    LL a, b, c, d;
    LL ret;
    if ( typ == FIRST_ROW )
    {
        ret = getRectSum(u, v, u, y);
    }
    else if ( typ == LAST_ROW )
    {
        ret = getRectSum(x, v, x, y);
    }
    else if ( typ == FIRST_COL )
    {
        ret = getRectSum( u, v, x, v );
    }
    else if ( typ == LAST_COL )
    {
        ret = getRectSum(u, y, x, y);
    }
    return ret;
}

LL buildEdgeSumAr(LL *edgeSumAr, LL u, LL v, LL x, LL y, LL typ)
{
    LL a, b, c, d, e, f;
    edgeSumAr[ typ ] = getEdgeSum( u, v, x, y, typ );
    return edgeSumAr[typ];
}

void buildAliceMove(LL &u, LL &v, LL &x, LL &y)
{
    LL a, b, c, d, e, f;
    LL edgeSumAr[9], minEdgeSum = LLMAX;
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_ROW) );
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_ROW)) ;
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_COL) );
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_COL) );

//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);
//    edgeSumAr[ LAST_ROW ] = getEdgeSum(u, v, x, y, LAST_ROW);
//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);
//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);

    if ( minEdgeSum == edgeSumAr[ FIRST_ROW ] )
    {
        u++;
    }
    else if ( minEdgeSum == edgeSumAr[LAST_ROW] )
    {
        x--;
    }
    else if ( minEdgeSum == edgeSumAr[FIRST_COL] )
    {
        v++;
    }
    else if ( minEdgeSum == edgeSumAr[LAST_COL] )
    {
        y--;
    }
}

LL getAliceDp(LL u, LL v, LL x, LL y)
{
//    cout << "in getAliceDp " << endl;
//    DBG4(u, v, x, y);
    buildAliceMove(u, v, x, y);
//    cout << "buildAliceMove executed" << endl;
//    DBG4(u, v, x, y);
    return getBobDp(u, v, x, y);
}

LL getBobDp(LL u, LL v, LL x, LL y)
{
    if ( u>x || v>y ) return 0;

    if ( dp[u][v][x][y][BOB] != -1 )
    {
        return dp[u][v][x][y][BOB];
    }

    LL ret = INT_MIN;

    LL edgeSumAr[9];
    buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_ROW);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_ROW);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_COL);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_COL);


    ret = max( ret,  edgeSumAr[FIRST_ROW] + getAliceDp(u+1, v, x, y) );
    ret = max( ret, edgeSumAr[LAST_ROW] + getAliceDp(u, v, x-1, y) );
    ret = max( ret, edgeSumAr[FIRST_COL] +  getAliceDp(u, v+1, x, y) );
    ret = max( ret, edgeSumAr[LAST_COL] + getAliceDp(u, v, x, y-1) );

    dp[u][v][x][y][BOB] = ret;

    return ret;
}


void buildCumAar()
{
    LL a, b, c, d, e, f;
    RESET( cumAar );
    FOR(a,1,SIZE)
    {
        FOR(b,1,SIZE)
        {
            cumAar[a][b] = aAr[a][b] + cumAar[a-1][b] + cumAar[a][b-1] - cumAar[a-1][b-1];
        }
    }
}




int main()
{
//    cout << LLMAX << endl;
 //   freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f, g;
//    cin >> T;
    ILL(T);
//    DBG( T );
    FOR(a,1,1+T)
    {
//        cin >> N >> M;
        ILL2(N, M);
//        DBG2(N, M);
//        DBG( N);
//        DBG( M );
        RESET( aAr );
        FOR(b,1,1+N)
        {
            FOR(c,1,1+M)
            {
                ILL( aAr[b][c] );
//                LL aij;
//                scanf("%lld", &aAr[b][c]);
            }
        }
        RESET( cumAar );
        SET( dp );
        buildCumAar();

//        FOR(b,1,1+N)
//        {
//            FOR(c,1,1+M)
//            {
//                cout << cumAar[b][c] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        LL bobCandyCnt = getAliceDp(1, 1, N, M);
        LL aliceCandyCnt = cumAar[N][M]-bobCandyCnt;

        LL ans;
        if ( bobCandyCnt == aliceCandyCnt )
        {
            ans = bobCandyCnt+aliceCandyCnt;
        }
        else
        {
            ans = max(aliceCandyCnt, bobCandyCnt);
        }
        cout << ans << endl;;
    }
    return 0;
}#include <bits/stdc++.h>
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
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define LLMAX ( (unsigned long long)(-1LL) >> 1LL )

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



void ILL(LL &u)
{
    LL a, b, c, d;
    scanf("%lld", &u);
}

void ILL2(LL &u, LL &v)
{
    LL a, b, c, d, e;
    scanf("%lld %lld", &u, &v);
}

void ILL3(LL &u, LL &v, LL &w)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld", &u, &v, &w);
}

LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};




/******   END OF HEADER *********/
#define SIZE 59

#define ALICE 0
#define BOB 1

#define FIRST_ROW 2
#define LAST_ROW 3
#define FIRST_COL 4
#define LAST_COL 5

LL dp[SIZE][SIZE][SIZE][SIZE][9];

LL T, N, M, aAr[SIZE][SIZE];


LL cumAar[SIZE][SIZE];

LL getAliceDp(LL u, LL v, LL x, LL y);
LL getBobDp(LL u, LL v, LL x, LL y);

LL getRectSum(LL u, LL v, LL x, LL y)
{
    LL a, b, c, d, e;
    LL ret = 0;
    u--;
    v--;
    return cumAar[x][y] - cumAar[u][y] - cumAar[x][v] + cumAar[u][v];
}



LL getEdgeSum(LL u, LL v, LL x, LL y, LL typ)
{
    LL a, b, c, d;
    LL ret;
    if ( typ == FIRST_ROW )
    {
        ret = getRectSum(u, v, u, y);
    }
    else if ( typ == LAST_ROW )
    {
        ret = getRectSum(x, v, x, y);
    }
    else if ( typ == FIRST_COL )
    {
        ret = getRectSum( u, v, x, v );
    }
    else if ( typ == LAST_COL )
    {
        ret = getRectSum(u, y, x, y);
    }
    return ret;
}

LL buildEdgeSumAr(LL *edgeSumAr, LL u, LL v, LL x, LL y, LL typ)
{
    LL a, b, c, d, e, f;
    edgeSumAr[ typ ] = getEdgeSum( u, v, x, y, typ );
    return edgeSumAr[typ];
}

void buildAliceMove(LL &u, LL &v, LL &x, LL &y)
{
    LL a, b, c, d, e, f;
    LL edgeSumAr[9], minEdgeSum = LLMAX;
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_ROW) );
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_ROW)) ;
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_COL) );
    minEdgeSum = min(minEdgeSum, buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_COL) );

//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);
//    edgeSumAr[ LAST_ROW ] = getEdgeSum(u, v, x, y, LAST_ROW);
//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);
//    edgeSumAr[ FIRST_ROW ] = getEdgeSum(u, v, x, y, FIRST_ROW);

    if ( minEdgeSum == edgeSumAr[ FIRST_ROW ] )
    {
        u++;
    }
    else if ( minEdgeSum == edgeSumAr[LAST_ROW] )
    {
        x--;
    }
    else if ( minEdgeSum == edgeSumAr[FIRST_COL] )
    {
        v++;
    }
    else if ( minEdgeSum == edgeSumAr[LAST_COL] )
    {
        y--;
    }
}

LL getAliceDp(LL u, LL v, LL x, LL y)
{
//    cout << "in getAliceDp " << endl;
//    DBG4(u, v, x, y);
    buildAliceMove(u, v, x, y);
//    cout << "buildAliceMove executed" << endl;
//    DBG4(u, v, x, y);
    return getBobDp(u, v, x, y);
}

LL getBobDp(LL u, LL v, LL x, LL y)
{
    if ( u>x || v>y ) return 0;

    if ( dp[u][v][x][y][BOB] != -1 )
    {
        return dp[u][v][x][y][BOB];
    }

    LL ret = INT_MIN;

    LL edgeSumAr[9];
    buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_ROW);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_ROW);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, FIRST_COL);
    buildEdgeSumAr(edgeSumAr, u, v, x, y, LAST_COL);


    ret = max( ret,  edgeSumAr[FIRST_ROW] + getAliceDp(u+1, v, x, y) );
    ret = max( ret, edgeSumAr[LAST_ROW] + getAliceDp(u, v, x-1, y) );
    ret = max( ret, edgeSumAr[FIRST_COL] +  getAliceDp(u, v+1, x, y) );
    ret = max( ret, edgeSumAr[LAST_COL] + getAliceDp(u, v, x, y-1) );

    dp[u][v][x][y][BOB] = ret;

    return ret;
}


void buildCumAar()
{
    LL a, b, c, d, e, f;
    RESET( cumAar );
    FOR(a,1,SIZE)
    {
        FOR(b,1,SIZE)
        {
            cumAar[a][b] = aAr[a][b] + cumAar[a-1][b] + cumAar[a][b-1] - cumAar[a-1][b-1];
        }
    }
}




int main()
{
//    cout << LLMAX << endl;
 //   freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f, g;
//    cin >> T;
    ILL(T);
//    DBG( T );
    FOR(a,1,1+T)
    {
//        cin >> N >> M;
        ILL2(N, M);
//        DBG2(N, M);
//        DBG( N);
//        DBG( M );
        RESET( aAr );
        FOR(b,1,1+N)
        {
            FOR(c,1,1+M)
            {
                ILL( aAr[b][c] );
//                LL aij;
//                scanf("%lld", &aAr[b][c]);
            }
        }
        RESET( cumAar );
        SET( dp );
        buildCumAar();

//        FOR(b,1,1+N)
//        {
//            FOR(c,1,1+M)
//            {
//                cout << cumAar[b][c] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;

        LL bobCandyCnt = getAliceDp(1, 1, N, M);
        LL aliceCandyCnt = cumAar[N][M]-bobCandyCnt;

        LL ans;
        if ( bobCandyCnt == aliceCandyCnt )
        {
            ans = bobCandyCnt+aliceCandyCnt;
        }
        else
        {
            ans = max(aliceCandyCnt, bobCandyCnt);
        }
        cout << ans << endl;;
    }
    return 0;
}
