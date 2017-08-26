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

void printSetLL( set<LL> setToPr )
{
    LL a, b, c, d, e;
    for ( auto it : setToPr )
    {
        cout << it << " ";
    }
    cout  << endl;
}


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
#define SIZE 200009

LL evAr[SIZE][9];
set<LL> vioSignSet;
LL n;
int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    LL a, b,c, d, e, f , g;
    cin >> n;
    LL curSpeed;
    FOR(a,1,1+n)
    {
        LL t, s;
        ILL( t );
        if (t == 1) // He changes speed
        {
            ILL( s );
            curSpeed = s;
        }
        else if ( t == 2 ) // He overtakes
        {

        }
        else if ( t == 3 ) // speed limit sign
        {
            ILL(s);
            if ( curSpeed > s )
            {
                vioSignSet.insert( a );
            }
        }
        else if ( t == 4 ) // overtake  allowed sign
        {

        }
        else if ( t == 5 ) // NO speed limit sign
        {

        }
        else if ( t == 6 ) // NO overtake allowed
        {

        }
        evAr[a][0] = t;
        evAr[a][1] = s;
    }


//    cout << "1 -- > n complete" << endl;
//    DBG( vioSignSet.size() );
//    printSetLL( vioSignSet );


    LL didOvertake = 0;
    LL maxSpeed = 0;
    ROF(a,n,0)
    {
        LL t, s;
        t = evAr[a][0];
        s = evAr[a][1];
//        ILL( t );
        if (t == 1) // He changes speed
        {
//            ILL( s );
            maxSpeed = max(maxSpeed, s);
        }
        else if ( t == 2 ) // He overtakes
        {
            didOvertake = 1;
        }
        else if ( t == 3 ) // speed limit sign
        {
//            ILL(s);
            if (s < maxSpeed)
            {
                vioSignSet.insert( a );
            }
            else if ( s >= maxSpeed )
            {
                maxSpeed = 0;
            }
        }
        else if ( t == 4 ) // overtake  allowed sign
        {
            didOvertake = 0;
        }
        else if ( t == 5 ) // NO speed limit sign
        {
            maxSpeed = 0;
        }
        else if ( t == 6 ) // NO overtake allowed
        {
            if ( didOvertake )
            {
                vioSignSet.insert( a );
            }
        }
        evAr[a][0] = t;
        evAr[a][1] = s;
    }


//    cout << "n -- > 1 complete" << endl;
//    DBG( vioSignSet.size() );
//    printSetLL( vioSignSet );



    LL ans = vioSignSet.size();
    cout << ans;

    return 0;
}
