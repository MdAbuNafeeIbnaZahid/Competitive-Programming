#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, P[SIZE], W[SIZE], G, MW[109], N, ans;
long long ar[SIZE][39];
long long i, j, k,a, b, c;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ans = 0;
        memset(ar, 0, sizeof(ar));
        cin >> N;
        for (j = 1; j <= N; j++)
        {
            scanf("%lld %lld", &P[j], &W[j]);
        }
        cin >> G;
        for (j = 1; j <= G; j++)
        {
            scanf("%lld", &MW[j]);
        }
        for (k = 0; k < 39; k++)
        {
            ar[0][k] = 0;
        }
        for (j = 1; j <= N; j++)
        {
            for (k = 0; k < 39; k++)
            {
                if ( k-W[j] >= 0 )
                    ar[j][k] = max(ar[j-1][k], ar[j-1][ k-W[j] ] + P[j]);
                else
                    ar[j][k] = ar[j-1][k];
            }
        }
        ans = 0;
        for (k = 1; k <= G; k++) ans+= ar[N][ MW[k] ];
        cout << ans << endl;
    }
    return 0;
}
