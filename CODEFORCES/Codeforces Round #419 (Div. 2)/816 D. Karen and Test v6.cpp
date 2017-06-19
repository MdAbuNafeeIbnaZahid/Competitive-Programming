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
#define SIZE
#define MOD 1000000007

map<PairLL, LL> bigModMap;

bool isSame(map<LL, LL> m1, map<LL, LL> m2)
{
    map<LL, LL>::iterator mapIt;
    LL a, b, c, d, e;
    for (mapIt = m1.begin(); mapIt != m1.end(); mapIt++ )
    {
        if ( m1[ mapIt->first ] != m2[ mapIt->first ] )
        {
            return 0;
        }
    }
    for ( mapIt = m2.begin(); mapIt != m2.end(); mapIt++ )
    {
        if ( m1[ mapIt->first ] != m2[ mapIt->first ] )
        {
            return 0;
        }
    }
    return 1;
}

LL bigMod(LL base, LL p)
{
    LL a, b, c, d, e;
    if ( bigModMap.find( MP(base, p) ) == bigModMap.end() )
    {
        LL ret;
        if ( p == 0 )
        {
            ret = 1;
        }
        else
        {
            LL x = bigMod(base, p/2);
            x = (x*x) % MOD;
            if ( p & 1 )
            {
                x = (x*base) % MOD;
            }
            ret = x;
        }
        bigModMap[ MP(base, p) ] = ret % MOD;
    }
    return bigModMap[ MP(base, p) ];
}

LL inv(LL b)
{
    LL ret = bigMod(b, MOD-2) % MOD;
    return ret;
}

vector< map<LL, LL> > vec;

map<LL, LL> addSubMap( map<LL, LL> m1, map<LL, LL> m2, bool isPlus )
{
//    cout << "in addSubMap" << endl;
//    DBG(isPlus);
    map<LL, LL> ret;
    LL si = -1, a, b, c, d, e;
    if ( isPlus )
    {
        si *= -1;
    }
    map< LL, LL >::iterator mapIt;
    for (mapIt = m1.begin(); mapIt != m1.end(); mapIt++)
    {
        ret[ mapIt->first ] += mapIt->second;
    }
    for (mapIt = m2.begin(); mapIt != m2.end(); mapIt++)
    {
        ret[ mapIt->first ] += ( si * mapIt->second );
    }
    return ret;
}

vector< map<LL, LL> > oneStep( vector< map<LL, LL> > giVec, LL isPlus )
{
//    cout << "in oneStep " << endl;
    LL a, b, c, d, e;
    vector< map<LL, LL> > ret;
    for (a = 0; a < giVec.size()-1; a++)
    {
//        DBG(a);
        map<LL, LL> newMap = addSubMap(giVec[a], giVec[a+1], isPlus);
//        cout << "newMap generated" << endl;
        ret.push_back( newMap );
        isPlus ^= 1;
    }
    return ret;
}

vector< map<LL, LL> > genVec( LL num )
{
    vector< map<LL, LL> > ret;
    LL a, b, c, d, e;
    for ( a = 1; a <= num; a++)
    {
        map<LL, LL> newMap;
        newMap[a] = 1;
        ret.push_back( newMap );
    }
    return ret;
}

map<LL, LL> bruteSolvAndPrint(LL num)
{
//    cout << "in bruteSolvAndPrint" << endl;
    LL a, b, c, d, e, isPlus = 1;
    vector< map<LL, LL> > vecMap = genVec(num);
    while( vecMap.size() > 1 )
    {
//        DBG(vecMap.size());
        vecMap = oneStep( vecMap, isPlus );
        isPlus ^= (vecMap.size() & 1);
    }
    printMapLLLL( vecMap[0] );
    return vecMap[0];
}

map<LL, LL> zeroTwo(LL num)
{
//    cout << "inZeroTwo" << endl;
    map<LL, LL> ret;
    LL a, b, c, d, e, f;
    ret[1] = 1;
    ret[2] = 1;
    for (a = 3; a <= num/2; a+=2)
    {
//        DBG(a);
        ret[ a ] = ( ret[a-1] * ( num - a+1 ) ) % MOD;
//        DBG( ret[a] );
        ret[a] = (ret[a] * inv( a-1 ) ) % MOD;
//        DBG( ret[a] );
        ret[a+1] = ret[a];
//        DBG( ret[a+1] );
    }
    FOR(a,num/2+1, num)
    {
        ret[a] = ret[ num - a+1 ];
    }
    if (num%4== 0)
    {
        FOR(a,1,num)
        {
            if ( (a&1) == 0 )
            {
                ret[a] *= -1;
            }
        }
    }
    return ret;
}


map<LL, LL> one(LL num)
{
    map<LL, LL> ret;
    LL a, b, c, d, e;
    ret[1] = 1;
    for (a = 3; a <= (num+1)/2; a+=2)
    {
        ret[a] = ( ret[a-2] * ( num -a+2 ) ) % MOD;
        ret[a] = ( ret[a] * inv( a-1 ) ) % MOD;
    }
    FOR(a,num/2+2,num)
    {
        ret[a] = ret[num-a+1];
    }
    return ret;
}

map<LL, LL> three(LL num)
{
    map<LL, LL> ret;
    LL a, b, c, d, e;
    ret[1] = 1;
    ret[2] = 2;
    for (a = 3; a<= (num+1)/2; a++)
    {
        if (a&1)
        {
            ret[a] = (ret[a-1] * (num-2*a+1) ) % MOD;
            ret[a] = (ret[a] * inv(2*a-2) ) % MOD;
        }
        else
        {
            ret[a] = (ret[a-1] * 2 ) % MOD;
            ret[a] = (ret[a] * (num-a+1) ) % MOD;
            ret[a] = ( ret[a] * inv(num-2*a+3) ) % MOD;
        }
    }
    FOR(a,num/2+2,num)
    {
        ret[a] = ret[num-a+1];
        if (a&1)
        {
            ret[a] *= -1;
        }
    }
    return ret;
}

map<LL, LL> getRightMap(LL num)
{
    if ( num % 4 == 1 )
    {
        return one(num);
    }
    else if ( num % 4 == 3 )
    {
        return three(num);
    }
    else
    {
        return zeroTwo(num);
    }
}

//LL getCalc()

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL n, ans = 0;
    cin >> n;
    vector<LL> inVec(1,1);
    map<LL,LL> smartMap = getRightMap(n);
    LL a, b, c, d, e, f;
    FOR(a,1,n)
    {
        LL ai;
        scanf("%lld", &ai);
        LL addee = ( smartMap[a] * ai ) % MOD;
        ans = (ans + addee) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans ;
    return 0;


    FOR(a,1,100)
    {
        DBG(a);
        cout << "brute derivation" << endl;
        map<LL, LL> bruteMap = bruteSolvAndPrint(a);
        cout << "smart derivation" << endl;

        printMapLLLL(smartMap);
        if ( ! isSame(bruteMap, smartMap) )
        {
            cout << "maps differ" << endl;
            return 0;
        }
        cout << endl << endl << endl;
    }
    return 0;
}





