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
#define SPRIME 10007
#define BPRIME 1000000007


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


LL bigMod(LL a, LL b, LL M)
{
    if ( b == 0 ) return 1%M;
    LL x = bigMod(a, b/2, M);
    x = (x*x)%M;
    if ( b&1LL )
    {
        x = (x*a)%M;
    }
    return x;
}


/******  END OF HEADER *********/
#define SIZE 10009
#define eps (1e-9)
LL T, n;
LL aAr[SIZE], bAr[SIZE], cAr[SIZE];

double getF(double x)
{
//    cout << " in getF " << endl;
//    DBG( x );
    LL a, b, c, d, e, f;
    double ret = aAr[1] * x * x + bAr[1] * x + cAr[1];
//    DBG( ret );
    FOR(a,2,1+n)
    {
//        DBG( a );
        ret = max( ret, aAr[a]*x*x + bAr[a]*x + cAr[a] );
    }
    return ret;
}

double ternarySearch(double star, double en)
{
//    cout << "in ternary search" << endl;
//    DBG2(star, en);
    LL a, b, c, d, e;
    if ( abs(en-star) <= eps )
    {
        return star;
    }
    double midStar, midEn;
    midStar = 2*star/3 + en/3;
    midEn = star/3 + 2*en/3;
//    DBG2(midStar, midEn);
//    DBG( getF(midStar) );
//    DBG( getF(midEn) );
    if ( getF(midStar) <= getF(midEn) )
    {
        return ternarySearch(star, midEn);
    }
    else
    {
        return ternarySearch( midStar, en );
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f, g;
    ILL( T );
//    DBG(T);
    FOR(a,1,1+T)
    {
        ILL(n);
//        DBG(n);
        FOR(b,1,1+n)
        {
            ILL3( aAr[b], bAr[b], cAr[b] );
        }
        double xAns = ternarySearch(0.0, 1000.0);
        double ans = getF(xAns);
        printf("%0.4lf", ans);
        cout << endl;
//        if ( a < T )
//        {
//            cout << endl;
//        }
    }
    return 0;
}
