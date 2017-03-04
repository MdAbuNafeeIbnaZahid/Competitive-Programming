#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
long long dis[SIZE][SIZE], busyness[SIZE];
long long T, n, m, source, destination, q, w, queryDest;
long long a, b, c, d, e, f;
long long k, i, j;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &busyness[b]);
        }
        for (b = 1; b <= n; b++)
        {
            for (c = 1; c <= n; c++)
            {
                if ( b==c ) dis[b][c] = 0;
                else dis[b][c] = INT_MAX;
            }
        }
        cin >> m;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &source, &destination);
            w = abs( busyness[source] - busyness[destination] );
            //w = busyness[source] - busyness[destination];
            dis[source][destination] = w*w*w;
        }
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if ( dis[i][k] + dis[k][j] < dis[i][j] )
                    {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        cout << "Case " << a << ":" << endl;
        cin >> q;
        for ( b = 1; b <= q; b++ )
        {
            scanf("%lld", &queryDest);
            if ( dis[1][queryDest] < 3 || dis[1][queryDest] >= INT_MAX/2 )
            {
                printf("?\n");
            }
            else printf("%lld\n", dis[1][queryDest]);
        }
        //cout << endl;
    }
    return 0;
}
