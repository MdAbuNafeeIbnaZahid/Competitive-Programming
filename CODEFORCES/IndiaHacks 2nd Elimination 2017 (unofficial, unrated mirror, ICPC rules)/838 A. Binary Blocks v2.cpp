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
#define SIZE 2509

LL n, m;
LL matrix[SIZE][SIZE], cntAr[SIZE][SIZE];
LL ans = INT_MAX;

LL getRect(LL a, LL b, LL c, LL d)
{
    a = min(a, n);
    c = min(c, n);

    b = min(b, m);
    d = min(d, m);

    return cntAr[c][d] - cntAr[a-1][d] - cntAr[c][b-1] + cntAr[a-1][b-1];
}


LL calcPosAns( LL k )
{
    LL a, b, c, d, e, f;
//    cout << "in calcPosAns" << endl;
    LL ret = 0;
    FOR(a,1, ceil(1.0*n/k)+1 )
    {
        FOR(b, 1, ceil(1.0*m/k)+1 )
        {
            LL p, q, r, s;
            p = (a-1)*k+1;
            q = (b-1)*k+1;

            r = a*k;
            s = b*k;

//            DBG(p);
//            DBG(q);
//            DBG(r);
//            DBG(s);

            LL oneCnt = getRect( p, q, r, s  );

//            DBG( oneCnt );

            LL addee = min(oneCnt, k*k - oneCnt);

            ret += addee;
        }
    }
    return ret;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f, g;

    cin >> n >> m;
    FOR(a,1,1+n)
    {
        char str[SIZE];
        scanf("%s", str+1);
        FOR(b,1,1+m)
        {
            matrix[a][b] = (str[b]=='1');
        }
    }

//    cout << "matrix" << endl ;
//    FOR(a,1,1+n)
//    {
//        FOR(b,1,1+m)
//        {
//            cout << matrix[a][b] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl << endl << endl;

    FOR(a,1,1+n)
    {
        FOR(b,1,1+m)
        {
            cntAr[a][b] = matrix[a][b] + cntAr[a-1][b] + cntAr[a][b-1] - cntAr[a-1][b-1];
        }
    }

//    FOR(a,1,1+n)
//    {
//        FOR(b,1,1+m)
//        {
//            DBG(a);
//            DBG(b);
//            DBG( cntAr[a][b] );
//        }
//    }





    FOR(a,2,10 )
    {
//        DBG(a);
        LL posAns = calcPosAns(a);
//        DBG( posAns );
        ans = min(ans, posAns);
    }
    cout << ans;
    return 0;
}

