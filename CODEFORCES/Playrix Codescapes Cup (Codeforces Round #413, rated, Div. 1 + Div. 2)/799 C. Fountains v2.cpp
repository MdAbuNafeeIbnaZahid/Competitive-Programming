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
#define SIZE 100009
long long n, c, d;
struct foun
{
    long long bi, pi;
    char typ;
    foun(){}
    foun(long long bi, long long pi, char typ)
    {
        this->bi = bi;
        this->pi = pi;
        this->typ = typ;
    }
    bool operator < (const foun B) const
    {
        return pi < B.pi;
    }
};
ostream &operator<<(ostream &stream, foun ob)
{
    stream << "bi = " << ob.bi << ", pi = " << ob.pi << ", typ = " << ob.typ << endl;
    return stream;
}
multiset<foun> coinFounSet, diaFounSet;
long long getMySum(long long a, long long b)
{
    if ( a <= 0 || b <= 0 )
    {
        return INT_MIN;
    }
    return a+b;
}
long long getTotBut(multiset<foun> mulFoun, long long maxCur)
{
    long long a, b, c, d, e, ret = 0, curUpto = 0;
    long long conMax[SIZE];
    memset(conMax, 0, sizeof(conMax));
    while( mulFoun.size() )
    {
        foun curFoun = *mulFoun.begin();
        mulFoun.erase( mulFoun.begin() );

//        cout << curFoun << endl;

        long long remCur = min(maxCur - curFoun.pi, curUpto);
        if (remCur > 0)
        {
            ret = max(ret, getMySum(curFoun.bi, conMax[remCur] ) );
        }
        conMax[ curFoun.pi ] = max(conMax[ curFoun.pi ], curFoun.bi);
        for (a = curUpto+1; a <= curFoun.pi; a++)
        {
            conMax[a] = max(conMax[a], conMax[a-1]);
        }
        curUpto = curFoun.pi;
//        cout << "ret = " << ret << endl;
    }
//    cout << "ret = " << ret << endl;
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long i, j, k, l, m;
    cin >> n >> c >> d;
    long long prev = 0, fromCoinOnly = 0, fromDiaOnly = 0, ans = 0, posAns = 0;
    long long fromCoin = 0, fromDia = 0;
    for (i = 1;  i <= n ; i++)
    {
        long long bi, pi;
        char typ;
        scanf("%lld %lld %c", &bi, &pi, &typ);
        if ( typ == 'C' )
        {
            if ( pi <= c )
            {
                fromCoin = max(fromCoin, bi);
            }
            coinFounSet.insert( foun(bi, pi, typ) );
        }
        else if ( typ == 'D' )
        {
            if ( pi <= d )
            {
                fromDia = max(fromDia, bi);
            }
            diaFounSet.insert( foun(bi, pi, typ) );
        }
    }

    ans = max(ans, getMySum(fromCoin, fromDia) );

//    cout << "checking ans from only coin" << endl;
    ans = max(ans, getTotBut(coinFounSet, c) );

//    cout << "checking ans from ony dia" << endl;
    ans = max(ans, getTotBut(diaFounSet, d) );

    cout << ans;
    return 0;
}
