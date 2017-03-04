#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long ar[SIZE], sum[4*SIZE], T, n, q, x, y, v, order, lazySum[4*SIZE];
long long a, b, c, d, e, f, i;
void update(long long *sum, long long l, long long r, long long L,
             long long R, long long n, long long v)
{
    if (lazySum[n] != 0)
    {
        sum[n] += lazySum[n] * (R-L+1);
        if (L<R)
        {
            lazySum[2*n+1] += lazySum[n];
            lazySum[2*n+2] += lazySum[n];
        }
        lazySum[n] = 0;
    }
    long long mid = (L+R)/2;
    if (r<L || R<l) return;
    //if ( L>=R )
    //{
        //sum[n] += v;
        //return;
    //}
    if ( l<=L && R<=r )
    {
        sum[n] += v*(R-L+1);
        if ( L < R )
        {
            lazySum[2*n+1] += v;
            lazySum[2*n+2] += v;
        }
        return;
    }
    update(sum, l, r, L, mid, 2*n+1, v);
    update(sum, l, r, mid+1, R, 2*n+2, v);
    sum[n] = sum[2*n+1] + sum[2*n+2];
}
long long getSum(long long *sum, long long l, long long r, long long L,
                 long long R, long long n)
{
    long long x, y, mid = (L+R)/2;
    if ( lazySum[n] != 0 )
    {
        sum[n] += (R-L+1) * lazySum[n];
        if (L<R)
        {
            lazySum[2*n+1] += lazySum[n];
            lazySum[2*n+2] += lazySum[n];
        }
        lazySum[n] = 0;
    }
    if (r<L || R<l) return 0;
    if ( l<=L && R<=r ) return sum[n];
    x = getSum(sum, l, r, L, mid, 2*n+1);
    y = getSum(sum, l, r, mid+1, R, 2*n+2);
    return x+y;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(sum, 0, sizeof(sum));
        memset(lazySum, 0, sizeof(lazySum));
        cin >> n >> q;
        cout << "Case " << i << ":" << endl;
        for (b = 1; b <= q; b++)
        {
            scanf("%lld", &order);
            if (order == 0)
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                update(sum, x, y, 0, n-1, 0, v);
                //cout << "updaated " << endl;
                //for (c = 0; c < 30; c++)
                //{
                    //cout << "c = " << c << ", sum[c] = " << sum[c] << endl;
                //}
            }
            else if (order == 1)
            {
                scanf("%lld %lld", &x, &y);
                printf("%lld\n", getSum(sum, x, y, 0, n-1, 0));
            }
        }
    }
    return 0;
}
