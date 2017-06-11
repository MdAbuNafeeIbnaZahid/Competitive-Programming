
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
/******   END OF HEADER *********/
#define SIZE 300009
#define UPTO 109
struct sov
{
    long long wi, ci, idx;
    double cperw;
    sov(){}
    sov(long long wi, long long ci, long long idx)
    {
        this->wi = wi;
        this->ci = ci;
        this->idx = idx;
        cperw = (1.0 * ci)/wi;
    }
    bool operator < (const sov B) const
    {
        if ( cperw == B.cperw )
        {
            if ( wi == B.wi )
            {
                return idx < B.idx;
            }
            return wi > B.wi;
        }
        return cperw < B.cperw;
    }
};
long long n, m;
vector< sov > vecSov;
long long rem, ans; // dp[SIZE][UPTO];
//long long getDp(long long row, long long col)
//{
//    if ( row < 0 || col < 0 )
//    {
//        return INT_MIN;
//    }
//    if ( row < 0 || row >= UPTO || col < 0 || col >= UPTO )
//    {
//        return 0;
//    }
//    return dp[row][col];
//}
//long long calcDp(long long rem)
//{
//    long long a, b, c, d, e, f;
//    for (a = 1; a <= vecSov.size(); a++)
//    {
//        for (b = 1; b <= rem; b++)
//        {
//            dp[a][b] = max(dp[a][b], getDp(a-1, b) );
//            dp[a][b] = max(dp[a][b], getDp(a, b-1) );
//            dp[a][b] = max(dp[a][b], getDp(a-1, b-vecSov[a-1].wi  ) + vecSov[a-1].ci );
//        }
//    }
//    return dp[ vecSov.size() ][ rem ];
//}
vector<long long> one, two, three, oneCop, twoCop;
long long dp[SIZE], threeConSum[SIZE];

void handle(long long ifOdd, vector<long long>oneVec, vector<long long> twoVec)
{
    long long a, b, c, d, e, weightUpto = 0, fromOne, fromTwo;
    if ( ifOdd )
    {
        if ( oneVec.size() )
        {
            dp[1] = oneVec[ oneVec.size()-1 ];
            oneVec.pop_back();
        }
        weightUpto = 1;
    }
    while( oneVec.size()>1 || twoVec.size() )
    {
        fromOne = fromTwo = 0;
        if ( oneVec.size()>1 )
        {
            fromOne = oneVec[ oneVec.size()-1 ] + oneVec[ oneVec.size()-2 ];
        }
        if ( twoVec.size() )
        {
            fromTwo = twoVec[ twoVec.size() - 1 ];
        }
        if ( fromTwo >= fromOne )
        {
            dp[ weightUpto + 2 ] = dp[ weightUpto ] + fromTwo;
            twoVec.pop_back();
        }
        else
        {
            dp[ weightUpto+2 ] = dp[ weightUpto ] + fromOne;
            oneVec.pop_back();
            oneVec.pop_back();
        }

        weightUpto+=2;
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> n >> m;
    rem = m;
    for (a = 1; a <= n; a++)
    {
        long long wi, ci;
        scanf("%lld %lld", &wi, &ci);
        if ( wi == 1 )
        {
            one.push_back( ci );
        }
        else if ( wi == 2 )
        {
            two.push_back( ci );
        }
        else if (wi == 3)
        {
            three.push_back( ci );
        }
//        vecSov.push_back( sov(wi, ci, a) );
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    sort(three.begin(), three.end());
    reverse(three.begin(), three.end());
    for (a = 1; a <= three.size(); a++)
    {
        threeConSum[a] = threeConSum[a-1] + three[ a-1 ];
    }

    handle(1, one, two);
    handle(0, one, two);


    for (a =1 ; a < SIZE; a++)
    {
        dp[a] = max(dp[a-1], dp[a]);
    }
    for (a = 0; a <= min((long long)three.size(), m/3); a++ )
    {
        long long posAns = 0;
        long long fromThree = threeConSum[a];
        posAns = fromThree + dp[ m - a * 3 ];
        ans = max(ans, posAns);
    }

    cout << ans;
    return 0;
//    oneCop = one;
//    twoCop = two;
//
//    long long fromOne, fromTwo;
//    // handle odd
//    if ( oneCop.size() )
//    {
//        dp[ 1 ] = oneCop[ oneCop.size() - 1 ];
//        oneCop.pop_back();
//    }
//    while( oneCop.size()>1 || twoCop.size() )
//    {
//
//    }
//
//
////    long long weightUpto = 0;
////    while( one.size()>=2 || two.size() )
////    {
////        long long fromOne = 0, fromTwo = 0;
////
////        if ( one.size() )
////        {
////            dp[weightUpto+1] = max(dp[weightUpto+1], dp[weightUpto] + one[ one.size() - 1 ] );
////        }
////
////
////        if ( one.size() > 1 )
////        {
////            fromOne = one[ one.size()-1 ] + one[ one.size() - 2 ];
////        }
////
////        if (two.size() )
////        {
////            fromTwo = two[ two.size() - 1 ];
////        }
////
////        if ( fromTwo >= fromOne )
////        {
////
////        }
////        else
////        {
////
////        }
////    }
////
//
//
//
//    sort( vecSov.begin(), vecSov.end() );
//    while( rem>100 && vecSov.size() )
//    {
//        sov curSov = vecSov[ vecSov.size()-1 ];
//        vecSov.pop_back();
//        ans += curSov.ci;
//        rem -= curSov.wi;
//    }
////    cout << "ans before dp = " << ans << endl;
//    long long addee = calcDp(rem);
////    cout << "addee = " << addee << endl;
//    ans += addee;
//    cout << ans;
//    return 0;
}
