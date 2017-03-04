#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long T, N, Q, i, h, l, r, Har[SIZE], type, ans;
long long a,b, c, d, e, f, g;
long long segTreeInputAr[4*SIZE], minSegTreeAr[4*SIZE], maxSegTreeAr[4*SIZE];
void buildMinMaxSegTree(long long att, long long L, long long R)
{
    long long mid = (L+R)/2;
    minSegTreeAr[att] = INT_MAX;
    maxSegTreeAr[att] = INT_MIN;
    if (L == R)
    {
        minSegTreeAr[att] = segTreeInputAr[L];
        maxSegTreeAr[att] = segTreeInputAr[R];
        return;
    }
    buildMinMaxSegTree(att*2, L, mid);
    buildMinMaxSegTree(att*2+1, mid+1, R);
    minSegTreeAr[att] = min( minSegTreeAr[att*2], minSegTreeAr[att*2+1] );
    maxSegTreeAr[att] = max( maxSegTreeAr[att*2], maxSegTreeAr[att*2+1] );
}
void updateMinMaxSegTree(long long att, long long L, long long R, long long pos, long long u)
{
    long long mid = (L+R)/2;
    if (L == R)
    {
        minSegTreeAr[att] = u;
        maxSegTreeAr[att] = u;
        return;
    }
    if (pos <= mid)
    {
        updateMinMaxSegTree(att*2, L, mid, pos, u);
    }
    else
    {
        updateMinMaxSegTree(att*2+1, mid+1, R, pos, u);
    }
    minSegTreeAr[att] = min(minSegTreeAr[att*2], minSegTreeAr[att*2+1]);
    maxSegTreeAr[att] = max(maxSegTreeAr[att*2], maxSegTreeAr[att*2+1]);
}
void segTreeMinMaxQuery(long long att, long long L, long long R, long long l, long long r,
                        long long &minVal, long long &maxVal)
{
    long long mid = (L+R)/2, leftMinVal, rightMinVal, leftMaxVal, rightMaxVal;
    if (r < L || R < l)
    {
        minVal = INT_MAX;
        maxVal = INT_MIN;
        return;
    }
    if ( l <= L && R <= r )
    {
        minVal = minSegTreeAr[att];
        maxVal = maxSegTreeAr[att];
        return;
    }
    segTreeMinMaxQuery(att*2, L, mid, l, r, leftMinVal, leftMaxVal);
    segTreeMinMaxQuery(att*2+1, mid+1, R, l, r, rightMinVal, rightMaxVal);
    minVal = min(leftMinVal, rightMinVal);
    maxVal = max(leftMaxVal, rightMaxVal);
}
long long bondQuery(long long startIdx, long long endIdx)
{
    long long ret = 0, mid = (startIdx+endIdx)/2, leftMin, rightMax, dummy;
    if ( startIdx >= endIdx )
    {
        return 0;
    }
    ret = max(ret, bondQuery(startIdx, mid));
    ret = max(ret, bondQuery(mid+1, endIdx));
    segTreeMinMaxQuery(1, 1, N, startIdx, mid, leftMin, dummy);
    segTreeMinMaxQuery(1, 1, N, mid+1, endIdx, dummy, rightMax);
    ret = max(ret, rightMax-leftMin);
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> Q;
        for (b = 1; b <=  N; b++)
        {
            scanf("%lld", &Har[b]);
            segTreeInputAr[b] = Har[b];
        }
        buildMinMaxSegTree(1, 1, N);
        cout << "Case " << a << ":" << endl;
        for (b = 1; b <= Q; b++)
        {
            scanf("%lld", &type);
            if (type == 1)
            {
                scanf("%lld %lld", &i, &h);;
                updateMinMaxSegTree(1, 1, N, i, h);
            }
            else
            {
                scanf("%lld %lld", &l, &r);
                ans = bondQuery(l, r);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
