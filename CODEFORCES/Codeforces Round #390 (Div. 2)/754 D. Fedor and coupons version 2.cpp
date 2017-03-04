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
#define SIZE 1000009
long long n, k, li, ri;
struct strip
{
    long long si, ei, len, idx;
    strip(){}
    strip(long long si, long long ei, long long idx)
    {
        this->si = si;
        this->ei = ei;
        this->idx = idx;
        len = ei-si+1;
    }
    long long getLen()
    {
        return ei-si+1;
    }
    bool operator < (strip B) const
    {
        if ( si == B.si )
        {
            if ( ei == B.ei )
            {
                return idx < B.idx;
            }
            return ei > B.ei;
        }
        return si < B.si;
    }
};
vector<strip> vecStrip;
long long a, b, c, d, e, f;
long long minVal[4*SIZE];
long long ans, ansStart, maxStart = INT_MAX, minEnd = INT_MIN;
void build(long long att, long long L, long long R)
{
    minVal[att] = INT_MAX;
    if (L == R)
    {
        minVal[att] = vecStrip[L].ei;
        return;
    }
    long long mid = (L+R)/2;
    build(att*2, L, mid);
    build(att*2+1, mid+1, R);
    minVal[att] = min(minVal[att*2], minVal[att*2+1]);
}

long long query(long long att, long long L, long long R, long long l, long long r)
{
    if ( r<L || R<l ) return INT_MAX;
    if ( l<=L && R <= r ) return minVal[att];
    long long mid = (L+R)/2;
    long long x = query(att*2, L, mid, l, r);
    long long y = query(att*2+1, mid+1, R, l, r);
    return min(x,y);
}
multiset<long long> endMulSet;
vector<long long> ansVec;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a=1; a <= n; a++)
    {
        scanf("%lld %lld", &li, &ri);
        vecStrip.push_back( strip(li, ri, a) );
    }
    sort(vecStrip.begin(), vecStrip.end());
//    for (a = 0; a < n; a++)
//    {
//        cout << vecStrip[a].si << " " << vecStrip[a].ei << " " << vecStrip[a].idx << endl ;
//    }
    build(1, 0, n-1);
    for (a = 0; a < vecStrip.size(); a++)
    {
        endMulSet.insert( vecStrip[a].ei );
        while( endMulSet.size() > k /* && *endMulSet.begin() < vecStrip[a].si */ )
        {
            endMulSet.erase( endMulSet.begin() );
        }
        if (  endMulSet.size()>=k && (*endMulSet.begin() - vecStrip[a].si) > (minEnd-maxStart) )
        {
            maxStart = vecStrip[a].si;
            minEnd = *endMulSet.begin();
        }
    }
    ans = minEnd - maxStart + 1;
//    cout << " ans =  " << ans << endl;
//    cout << "maxStart = "  << maxStart << endl;
//    cout << "minEnd = "  << minEnd << endl;
    if ( ans > 0 )
    {
        cout << ans << endl;
        for (a = 0; a < n; a++)
        {
            if ( maxStart >= vecStrip[a].si && vecStrip[a].ei >= minEnd )
            {
                ansVec.push_back( vecStrip[a].idx ) ;
            }
        }
//        cout << " ansVec.size() = " << ansVec.size() << endl;
        for (  a = 0; a < k; a++ )
        {
            printf("%lld ", ansVec[a]);
        }
    }
    else
    {
        cout << 0 << endl;
        for (a = 0; a <= 0+k-1; a++)
        {
            printf("%lld ", vecStrip[a].idx);
        }
    }
    return 0;
}

