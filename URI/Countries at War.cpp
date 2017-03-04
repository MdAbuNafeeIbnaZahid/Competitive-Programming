#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long N, E, dis[SIZE][SIZE], X, Y, H, O, D;
long long a, b, c, d, e, f;
long long k, i, j;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> N >> E;
        if (N+E==0) break;
        for (a = 1; a <= N; a++)
        {
            for (b = 1; b <= N; b++)
            {
                dis[a][b] = INT_MAX;
                if (a==b) dis[a][b] = 0;
            }
        }
        for (a = 1; a <= E; a++)
        {
            scanf("%lld %lld %lld", &X, &Y, &H);
            dis[X][Y] = H;
        }
        for (a = 1; a <= N; a++)
        {
            for (b = 1; b <= N; b++)
            {
                if ( dis[a][b]<INT_MAX && dis[b][a] < INT_MAX )
                {
                    dis[a][b] = dis[b][a] = 0;
                }
            }
        }
        for (k = 1; k <= N; k++)
        {
            for (i = 1; i <= N; i++)
            {
                for (j = 1; j <= N; j++)
                {
                    if ( dis[i][j] > dis[i][k] + dis[k][j] )
                        dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
        cin >> k;
        for (a = 1; a <= k; a++)
        {
            scanf("%lld %lld", &O, &D);
            if ( dis[O][D] >= INT_MAX )
            {
                printf("Nao e possivel entregar a carta\n");
            }
            else printf("%lld\n", dis[O][D]);
        }
        printf("\n");
    }
    return 0;
}
