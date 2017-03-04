#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
int T, n, q, ar[SIZE], seg[4*SIZE], ans, i, v, j;
int a, b, c, d, e, f, order, temp;
void buildSeg(int *ar, int *seg, int L, int R, int n)
{
    int mid = (L+R)/2;
    if (L>=R)
    {
        seg[n] = ar[L];
        return;
    }
    buildSeg(ar, seg, L, mid, 2*n+1);
    buildSeg(ar, seg, mid+1, R, 2*n+2);
    seg[n] = seg[2*n+1] + seg[2*n+2];
}
void update(int *seg, int idx, int L, int R, int addVal, int n)
{
    int mid = (L+R)/2, x, y;
    if (idx < L || idx > R) return;
    if (L>=R)
    {
        seg[n] += addVal;
        return;
    }
    update(seg, idx, L, mid, addVal, 2*n+1);
    update(seg, idx, mid+1, R, addVal, 2*n+2);
    seg[n] = seg[2*n+1] + seg[2*n+2];
}
int getSum(int *seg, int s, int e, int L, int R, int n)
{
    int x, y, mid = (L+R)/2;
    if (e<L || R<s) return 0;
    if ( s<=L && R<=e ) return seg[n];
    x = getSum(seg, s, e, L, mid, 2*n+1);
    y = getSum(seg, s, e, mid+1, R, 2*n+2);
    return x+y;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n >> q;
        for (b = 0; b < n; b++)
        {
            scanf("%d", &ar[b]);
        }
        buildSeg(ar, seg, 0, n-1, 0);
        cout << "Case " << a << ":" << endl;
        for (b = 0; b < q; b++)
        {
            scanf("%d", &order);
            if (order == 1)
            {
                scanf("%d", &i);
                printf("%d\n", ar[i]);
                temp = ar[i];
                ar[i] = 0;
                update(seg, i, 0, n-1, -temp, 0);
            }
            else if (order == 2)
            {
                scanf("%d %d", &i, &v);
                ar[i] += v;
                update(seg, i, 0, n-1, v, 0);
            }
            else if (order == 3)
            {
                scanf("%d %d", &i, &j);
                temp = getSum(seg, i, j, 0, n-1, 0);
                printf("%d\n", temp);
            }
        }
    }
    return 0;
}
