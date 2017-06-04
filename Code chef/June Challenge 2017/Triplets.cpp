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
#define MOD 1000000007
long long T, p, q, r, ans;
long long aAr[SIZE], bAr[SIZE], cAr[SIZE];
long long aCumSum[SIZE], bCumSum[SIZE], cCumSum[SIZE];
long long aIdx, cIdx;
long long getIdx(long long *ar, long long sIdx, long long eIdx, long long val)
{
    long long midIdx = (sIdx + eIdx + 1)/2;
    if ( sIdx == eIdx )
    {
        return sIdx;
    }
    if ( *(ar+midIdx) > val )
    {
        return getIdx(ar, sIdx, midIdx-1, val);
    }
    else
    {
        return getIdx(ar, midIdx, eIdx, val);
    }
}
long long getVal( long long aIdx, long long cIdx, long long y )
{
    long long ret = ( ( (y%MOD * y%MOD)%MOD ) * (( aIdx * cIdx ) %MOD ) ) %MOD;
    long long pl = (((cIdx * aCumSum[aIdx] )%MOD + (aIdx * cCumSum[cIdx])%MOD )%MOD * y) %MOD;
    long long ml = (aCumSum[aIdx] * cCumSum[cIdx] )%MOD;
    ret = (ret + pl)%MOD;
    ret = (ret+ml)%MOD;
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> p >> q >> r;
        for (b = 1; b <= p; b++)
        {
            scanf("%lld", &aAr[b]);
        }
        for (b = 1; b <= q; b++)
        {
            scanf("%lld", &bAr[b]);
        }
        for (b = 1; b <= r; b++)
        {
            scanf("%lld", &cAr[b]);
        }
        sort(aAr+1, aAr+p+1);
        sort(bAr+1, bAr+1+q);
        sort(cAr+1, cAr+1+r);
        for (b = 1; b <= p; b++)
        {
            aCumSum[b] = (aCumSum[b-1]%MOD + aAr[b]%MOD )%MOD;
        }
        for (b = 1; b <= q; b++)
        {
            bCumSum[b] = (bCumSum[b-1]%MOD + bAr[b]%MOD )%MOD;
        }
        for (b = 1; b <= r; b++)
        {
            cCumSum[b] = (cCumSum[b-1]%MOD + cAr[b]%MOD )%MOD;
        }
        for ( b = 1; b <= q; b++ )
        {
            aIdx = getIdx(aAr, 0, p, bAr[b] );
            cIdx = getIdx(cAr, 0, r, bAr[b] );
            ans = (ans + getVal(aIdx, cIdx, bAr[b]) )%MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
