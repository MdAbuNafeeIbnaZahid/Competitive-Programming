#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
int ar[SIZE], tog[4*SIZE], T, n, q, ans, i, j;
char order;
int a, b, c, d, e, f, g;
string bin;
void setTog(int *tog, int n, int l, int r, int L, int R)
{
    int mid = (L+R)/2;
    if (R<l || r<L) return;
    if (l<=L && R<=r)
    {
        tog[n]++;
        return;
    }
    setTog(tog, 2*n+1, l, r, L, mid);
    setTog(tog, 2*n+2, l, r, mid+1, R);
}
int getTog(int *tog, int n, int l, int r, int L, int R)
{
    //cout << "L = " << L << ", R = " << R << endl;
    int w, x, y, mid = (L+R)/2;
    if (r<L || R<l) return 0;
    if ( L >= R ) return tog[n];
    if (L<=l && r<=R) w = tog[n];
    x = getTog(tog, 2*n+1, l, r, L, mid);
    y = getTog(tog, 2*n+2, l, r, mid+1, R);
    return w+x+y;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(tog, 0, sizeof(tog));
        cin >> bin;
        n = bin.size();
        cin >> q;
        cout << "Case " << a << ":" << endl;
        for (b = 0; b < q; b++)
        {
            getchar();
            scanf("%c", &order);
            //cout << "order = " << order << endl;
            if (order == 'I')
            {
                scanf("%d %d", &i, &j);
                setTog(tog, 0, i-1, j-1, 0, n-1);
            }
            else if (order == 'Q')
            {
                scanf("%d", &i);
                //cout << "i = " << i << ", " << getTog(tog, 0, i-1, i-1, 0, n-1) << endl;
                printf("%d\n", (bin[i-1]-'0') ^ (getTog(tog, 0, i-1, i-1, 0, n-1) % 2 )  );
            }
        }
    }
    return 0;
}
