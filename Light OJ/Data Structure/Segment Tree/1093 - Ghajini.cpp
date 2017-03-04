#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
int T, n, d, ar[SIZE], maximum[4*SIZE], minimum[4*SIZE], ans, dif;
int i, j, k, m;
void buildMaxSeg(int *ar, int *maximum, int L, int R, int n)
{
    int mid = (L+R)/2;
    if (L>=R)
    {
        maximum[n] = ar[L];
        return;
    }
    buildMaxSeg(ar, maximum, L, mid, 2*n+1);
    buildMaxSeg(ar, maximum, mid+1, R, 2*n+2);
    maximum[n] = max(maximum[2*n+1], maximum[2*n+2]);
}
void buildMinSeg(int *ar, int *minimum, int L, int R, int n)
{
    int mid = (L+R)/2;
    if (L>=R)
    {
        minimum[n] = ar[L];
        return;
    }
    buildMinSeg(ar, minimum, L, mid, 2*n+1);
    buildMinSeg(ar, minimum, mid+1, R, 2*n+2);
    minimum[n] = min(minimum[2*n+1], minimum[2*n+2]);
}
int getMax(int *maximum, int l, int r, int L, int R, int n)
{
    int x, y, mid = (L+R)/2;
    if (r<L || R<l) return INT_MIN;
    if (l<=L && R<=r) return maximum[n];
    x = getMax(maximum, l, r, L, mid, 2*n+1);
    y = getMax(maximum, l, r, mid+1, R, 2*n+2);
    return max(x, y);
}
int getMin(int *minimum, int l, int r, int L, int R, int n)
{
    int x, y, mid = (L+R)/2;
    if (r<L || R<l) return INT_MAX;
    if (l<=L && R<=r) return minimum[n];
    x = getMin(minimum, l, r, L, mid, 2*n+1);
    y = getMin(minimum, l, r, mid+1, R, 2*n+2);
    return min(x, y);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> n >> d;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &ar[j]);
        }
        buildMaxSeg(ar, maximum, 0, n-1, 0);
        buildMinSeg(ar, minimum, 0, n-1, 0);
        ans = 0;
        for (k = 0; k < n-d+1; k++)
        {
            dif = getMax(maximum, k, k+d-1, 0, n-1, 0) - getMin(minimum, k, k+d-1, 0, n-1, 0);
            ans = max(ans, dif);
        }
        if (k == 0)
        {
            dif = getMax(maximum, 0, n-1, 0, n-1, 0) - getMin(minimum, 0, n-1, 0, n-1, 0);
            ans = max(ans, dif);
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
