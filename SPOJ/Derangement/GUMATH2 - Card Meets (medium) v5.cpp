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
#define SIZE 100009
#define MOD 10000009


LL val[3*MOD];

void solv()
{
    LL a, b, c, d, e, f;
    val[0] = 1;
    val[1] = 0;
    val[2] = 1;
    FOR(a,3,2*MOD-1)
    {
        val[a] = ( val[a-1] + val[a-2] ) % MOD;
        val[a] = (val[a] * (a-1) ) % MOD;
    }
}

LL isPrime(LL num)
{
    LL a, b, c, d;
    FOR(a,2,sqrt(num+1))
    {
        if (num%a==0)
        {
            cout << a << endl;
            return 0;
        }
    }
    return 1;
}

LL T, N;
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e;

//    cout << isPrime(MOD) << endl;

    solv();
//    FOR(a,0,5)
//    {
//        FOR(b,0,2*MOD-1)
//        {
////            DBG(a*10+b);
////            DBG(val[a*10+b]%5);
//            cout << val[a*2*MOD+b] << " ";
//        }
//        cout << endl;
//    }



    cin >> T;
    FOR(a,1,T)
    {
        scanf("%lld", &N);
//        DBG(N);
//        N = N%(2*MOD);
        LL ans = (val[ (N-1+2*MOD) % (2*MOD) ] * ( N % MOD ) ) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}





