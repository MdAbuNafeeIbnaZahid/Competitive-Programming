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

/******   END OF HEADER *********/
#define SIZE 1000009
LL N;
LL sivAr[SIZE], euTotientAr[SIZE], gcdSumAr[SIZE], conGcdSumAr[SIZE];


LL gcd(LL a, LL b)
{
    if ( a > b )
    {
        swap(a, b);
    }
    if (a == 0)
    {
        return b;
    }
    return gcd(b%a, a);
}

LL bruteForce(LL num)
{
    LL ret = 0, a, b, c, d, e;
    for (a = 1; a < num; a++)
    {
        for (b = a+1; b <= num; b++)
        {
            ret += gcd(a, b);
        }
    }
    return ret;
}

void sivAndTot()
{
    LL a, b, c, d, e, f;
    for (a = 1; a < SIZE; a++)
    {
        sivAr[a] = a;
        euTotientAr[a] = a;
    }
    for (b = 2; b < SIZE; b++)
    {
        if ( sivAr[b] != b )
        {
            continue;
        }
        for (c = b; c < SIZE; c+= b)
        {
            sivAr[c] = b;
            euTotientAr[c] /= b;
            euTotientAr[c] *= (b-1);
        }
    }

//    for (a = 1; a <= 10; a++)
//    {
//        DBG( euTotientAr[a] );
//    }

    for (a = 1; a < SIZE; a++)
    {
        for (b = (a<<1LL); b < SIZE; b+=a)
        {
            gcdSumAr[b] += ( a * euTotientAr[ b/a ] );
        }
    }
    for (a = 1; a < SIZE; a++)
    {
        conGcdSumAr[a] = conGcdSumAr[a-1] + gcdSumAr[a];
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    sivAndTot();
    LL a,b, c, d, e;
    while(   1 )
    {
        scanf("%lld", &N);
        if (N==0)
        {
            return 0;
        }
        printf("%lld\n", conGcdSumAr[N]);
        continue;



        LL ans = 0;
        LL sqrtNum = sqrt(N+1);
        for (a = 1; a <= sqrtNum; a++ )
        {
            if ( N % a == 0 )
            {

            }
        }
    }
    return 0;
}


int cmain()
{
    while(1)
    {
        LL num;
        cin >> num;
        cout << bruteForce(num) << endl;
    }
}
