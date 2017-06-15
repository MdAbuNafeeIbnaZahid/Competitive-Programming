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



#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MK              make_pair

#define dbg(x) cout<<#x<<" : "<<x<<endl

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
#define SIZE 1000009
#define MOD 1000000007
LL n, aAr[SIZE], freqAr[SIZE], ans;
LL sivAr[SIZE], mobiusAr[SIZE], mulCnt[SIZE], pow2[SIZE], fx[SIZE];
vector<LL> primeVec[SIZE];

LL nc3(LL n)
{
    return (n*(n-1)*(n-2))/6;
}

void siv(LL *primeFacAr)
{
    LL a, b, c, d, e, f;
    for ( a= 1; a < SIZE; a++)
    {
        primeFacAr[a] = a;
    }
    for (a = 2; a < SIZE; a+=2)
    {
        primeFacAr[a] = 2;
    }
    for (a = 3; a*a < SIZE; a++)
    {
        if ( primeFacAr[a] != a )
        {
            continue;
        }
        for (b = a*a; b < SIZE; b += (a<<1))
        {
            primeFacAr[b] = a;
        }
    }
}
vector<LL> getPrimeFactors(LL num)
{
    vector<LL> ret;
    LL a, b, c, d, e, f, curNum = num;
    while( curNum > 1 )
    {
        LL p = sivAr[ curNum ];
        ret.push_back( p );
        while( curNum % p == 0 )
        {
            curNum /= p;
        }
    }
    return ret;
}

LL getMobVal(LL num, vector<LL> primVec)
{
    LL a, b, c, d, e, ret, copNum = num;
    if ( num == 1 )
    {
        ret = 1;
    }
    else if ( primVec.size() & 1 )
    {
        ret = -1;
    }
    else
    {
        ret = 1;
    }

    for (a = 0; a < primVec.size(); a++)
    {
        copNum /= primVec[a];
    }
    if ( copNum > 1 )
    {
        ret = 0;
    }
    return ret;
}


void makePow2()
{
    LL a, b, c, d;
    pow2[0] = 1;
    for (a = 1; a < SIZE; a++)
    {
        pow2[a] = (pow2[a-1] << 1LL) % MOD;
    }
}



int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    siv(sivAr);
    makePow2();
    for (a = 1; a < SIZE; a++)
    {
        primeVec[a] = getPrimeFactors(a);
        if ( a < 10 )
        {
//            printVecLL( primeVec[a] );
        }
        mobiusAr[a] = getMobVal(a, primeVec[a]);
    }


//    for (a = 1; a < 100; a++)
//    {
//        cout << "a = " << a << ", mobiusAr[a] = " << mobiusAr[a] << endl;;
//
//    }



    for (a= 1;  a < 10; a++)
    {
//        cout << "a = " << a << endl;
//        cout << "sivAr[a] = " << sivAr[a] << endl;
//        printVecLL( primeVec[a] );
//        cout << endl;
    }

    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        freqAr[ aAr[a] ]++;
    }
    for (a = 1; a <SIZE; a++)
    {
//        cout << "a = " << a << endl;
        for (b = a; b < SIZE; b+=a)
        {
            mulCnt[a] += freqAr[ b ];
        }
//        cout << "mulCnt[a] = " << mulCnt[a] << endl;
        fx[ a ] = nc3( mulCnt[a] );
//        cout << "fx[a] = " << fx[a] << endl;
//        cout << "mobiusAr[a] = " << mobiusAr[a] << endl;

        if ( fx[a] == 0 || mobiusAr[a] == 0 )
        {
            continue;
        }
//        cout << "a = " << a << endl;
//        cout << "mulCnt[a] = " << mulCnt[a] << endl;
//        cout << "fx[a] = " << fx[a] << endl;
//        cout << "mobiusAr[a] = " << mobiusAr[a] << endl;

        ans = ans + fx[a] * mobiusAr[a];
    }
    cout << ans ;
    return 0;
}

