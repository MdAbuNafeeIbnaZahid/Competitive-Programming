

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
#define SIZE
LL x, y;
LL ans;


vector<LL> getAllDiv(LL num)
{
    LL a, b, c, d, e, f;
    vector<LL> ret;
    for(a = 2; a *a <= num; a++)
    {
        if ( num % a == 0 )
        {
            ret.push_back( a );
            ret.push_back( num/a );
        }
    }
    return ret;
}



LL gcd(LL u, LL v)
{
    LL a, b, c, d, e,f;
    if ( u > v )
    {
        swap(u, v);
    }
    if ( u == 0 )
    {
        return v;
    }
    return gcd(v%u, u);
}



LL bruteForce(LL u, LL v)
{
    if ( v == 0 )
    {
        return 0;
    }
    else
    {
        return 1 + bruteForce(u, v-gcd(u,v) );
    }
}


LL effSol(LL u, LL v)
{
//    LL g = gcd(u, v);
//    u /= g;
//    v /= g;


    LL ret = 0;
    while( u < v )
    {
//        DBG(u);
//        DBG(v);
//        DBG(ret);


    	if ( u == 1 )
    	{
    		ret += v;
//    		cout << ans;
    		return ret;
    	}
        vector<LL> vecDiv = getAllDiv( u );
//        printVecLL( vecDiv );
//        for (a = 2; a*a <= x; a++)
//        {
//            if ( x % a == 0 )
//            {
//                vecDiv.push_back( a );
//                vecDiv.push_back( x/a );
//            }
//        }
//        vecDiv.push_back( x );
        LL minRem = (v-u) % u;
        LL minDiv = u;
        for ( auto it : vecDiv )
        {
            if ( (v-u)%it < minRem )
            {
                minRem = (v-u) % it;
                minDiv = it;
            }
            else if ( (v-u) % it == minRem && it > minDiv )
            {
                minDiv = it;
            }
        }
        ret += minRem;
        v -= minRem;

        u /= minDiv;
        v /= minDiv;
    }
    if ( u == v )
    {
        ret++;
//        cout << ans;
        return ret;
    }
    while( 1 )
    {
    	//cout << x << ", " << y << endl;
    	if ( v == 0 )
        {
//            cout << ans ;
            return ret;
        }
        if ( u % v == 0 )
        {
//            ans++;
            ret++;
//            cout << ans;
            return ret;
        }
        vector<LL> vecDiv = getAllDiv( u );
        LL minDiv = u;
        LL minRem = v;

        for ( auto it : vecDiv )
        {
            if ( v%it < minRem )
            {
                minRem = v%it;
                minDiv = it;
            }
            else if ( v%it == minRem && it > minDiv )
            {
                minDiv = it;
            }
        }

        ret += minRem;
        v -= minRem;

        u /= minDiv;
        v /= minDiv;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
//    cin >> x >> y;
//    ans = effSol(x, y);
//    cout << ans;
    FOR(a,1,100)
    {
        FOR(b,1,100)
        {
            if ( effSol(a,b) != bruteForce(a,b) )
            {
                DBG(a);
                DBG(b);
                DBG( effSol(a,b) );
                DBG( bruteForce(a,b) );
                return 0;
            }
        }
    }

    cin >> x >> y;
    ans = effSol(x, y);
    cout << ans;

//    effSol(6, 9);

    return 0;
}

