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

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)

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


/******   END OF HEADER *********/
#define SIZE 5000009
#define MOD 1000000007

LL t, l, r, ans;
LL sivAr[SIZE], fAr[SIZE], powAr[SIZE];

void makeSivAr()
{
    LL a, b, c, d, e;
    FOR(a,1,SIZE-1)
    {
        sivAr[a] = a;
    }
    FOR(a,2,SIZE-1)
    {
        if ( sivAr[a] == a )
        {
            for (b = a; b <SIZE; b+=a)
            {
                sivAr[b] = a;
            }
        }
    }
}

void makeFar()
{
    LL a, b, c, d, e;
    fAr[1] = 0;
    FOR(a,2,SIZE-1)
    {
        if ( sivAr[a] == a )
        {
            fAr[a] = (a*(a-1)/2 )%MOD;
        }
        else
        {
            LL bigPrime = sivAr[a];
            fAr[a] = (bigPrime*fAr[a/bigPrime] + fAr[bigPrime] )%MOD;
        }
    }
}

void makePowAr(LL num)
{
    LL a, b, c, d, e;
    powAr[0] = 1;
    FOR(a,1,SIZE-1)
    {
        powAr[a] = (powAr[a-1]*num )%MOD;
    }
}

//LL getFval(LL num)
//{
//    LL a, b, c, d, e, ret;
//
//}

int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> t >> l >> r;
    LL a, b,c , d;
    makeSivAr();
    makePowAr(t);
    makeFar();
    FOR(a,l,r)
    {
        LL addee = (powAr[a-l]*fAr[a] )%MOD;
        ans = (ans+addee)%MOD;
    }
    cout << ans;
    return 0;
}
