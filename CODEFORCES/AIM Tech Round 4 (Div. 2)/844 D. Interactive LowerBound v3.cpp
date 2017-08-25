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




/******   END OF HEADER *********/
#define SIZE 50009
#define MAX_Q 2000
LL n, start, x;
LL querMark[SIZE];

ordered_set OS;

LL startVal, startNext;


void printOS( ordered_set p )
{
    LL a, b, c, d, e, f;
    FOR(a,0,p.size())
    {
        cout << *p.find_by_order(a) << " ";
    }
    cout << endl;
}

void makeQuery(LL nextAdd, LL &retVal, LL &retNext)
{
    LL a, b, c, d, e, f;
    printf("? %lld\n", nextAdd);
    fflush( stdout );
    ILL2(retVal, retNext);
}

void printAns(LL an)
{
    printf("! %lld\n", an);
    fflush( stdout );
    exit(0);
}

LL posAns = -1;

int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


//    while(1)
//    {
//        LL typ, val;
//        cin >> typ >> val;
//        if ( typ == 0 )
//        {
//            OS.insert( val );
//        }
//        else if ( typ == 1 )
//        {
//            OS.erase( val );
//        }
//        printOS( OS );
//    }
    srand(  time(NULL)  );
    LL a, b, c, d, e, f, g;
    ILL3(n, start, x);
    makeQuery(start, startVal, startNext);
    if ( startVal >= x )
    {
        printAns( startVal );
    }
    LL targetVal = startVal;
    LL targetNext = startNext;
    FOR(a,1,n+1)
    {
        if ( a==start )
        {
            continue;
        }
        OS.insert( a );
    }
//    DBG2( targetVal, targetNext );
    FOR(a,2,1001)
    {
        if ( OS.size() == 0 )
        {
            break;
        }
        LL randIdx = (rand() * SPRIME ) % OS.size();
        LL randNum = *OS.find_by_order( randIdx );
        OS.erase( randNum );
//        printOS( OS );
        LL vi, ni;
        makeQuery( randNum, vi, ni );
        if ( vi<x )
        {
            if ( vi>targetVal )
            {
                targetVal = vi;
                targetNext = ni;
            }
        }
        else if ( vi == x )
        {
            printAns( vi );
        }
        else if ( vi > x )
        {
            posAns = vi;
        }
//        DBG2( targetVal, targetNext );
    }
//    cout << "random shooting complete" << endl;
//    DBG2(targetVal, targetNext);
    FOR(a,1001,MAX_Q)
    {
        if ( targetNext ==-1 )
        {
            printAns( -1 );
        }
        LL vi, ni;
        makeQuery(targetNext, vi, ni);
        if ( vi >= x )
        {
            printAns( vi );
        }
        targetNext = ni;
        targetVal = vi;
    }


    printAns( posAns );
    return 0;
}


