#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
int T, ar[SIZE], seg[5*SIZE], ans, N, q, I, J;
int i,j, k;
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
    seg[n] = min( seg[2*n+1], seg[2*n+2] );
    return;
}
int getMinimum(int *seg, int L, int R, int l, int r, int n)
{
    int x, y, mid = (L+R)/2;
    if (R<l || r<L) return INT_MAX;
    if (l<=L && R<=r) return seg[n];
    x = getMinimum(seg, L, mid, l, r, 2*n+1);
    y = getMinimum(seg, mid+1, R, l, r, 2*n+2);
    return min(x, y);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> N >> q;
        for (j = 0; j < N; j++)
        {
            scanf("%d", &ar[j]);
        }
        buildSeg(ar, seg, 0, N-1, 0);
        cout << "Case " << i << ":" << endl;
        for (j = 0; j < q; j++)
        {
            scanf("%d %d", &I, &J);
            printf("%d\n", getMinimum(seg, 0, N-1, I-1, J-1, 0));
        }
    }
    return 0;
}
