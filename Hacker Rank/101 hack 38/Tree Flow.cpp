#include <bits/stdc++.h>
using namespace std;
#define SIZE 4009
long long n, a, b, c, dist[SIZE][SIZE], ans;
long long i, j, k, m;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
            if ( i==j ) dist[i][j] = 0;
        }
    }
    for (i = 1; i <= n-1; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] );
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        ans+=dist[1][i];
    }
    cout << ans ;
    return 0;
}
