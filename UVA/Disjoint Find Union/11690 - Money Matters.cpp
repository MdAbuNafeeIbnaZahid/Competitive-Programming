#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
int N, n, m, o, x, y;
int i, j, k, sum[SIZE], p[SIZE];
int getParent(int u)
{
    if (p[u] == u) return u;
    p[u] = getParent(p[u]);
    return p[u];
}
void makeUnion(int a, int b)
{
    if ( getParent(a) == getParent(b) ) return;
    sum[ getParent(b) ] += sum[getParent(a)];
    p[ getParent(a) ] = getParent(b);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    while(N--)
    {
        cin >> n >> m;
        for (i = 0; i < n; i++) p[i] = i;
        for (i = 0; i < n; i++)
        {
            cin >> sum[i];
        }
        for (i = 1; i <= m; i++)
        {
            cin >> x >> y;
            makeUnion(x, y);
        }
        for (i = 0; i < n; i++) if ( sum[ getParent(i) ]!=0 ) break;
        if ( i >= n ) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
        //if (N) cout << endl;
    }
    return 0;
}
