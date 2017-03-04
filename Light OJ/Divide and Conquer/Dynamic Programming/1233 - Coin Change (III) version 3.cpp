#include <bits/stdc++.h>
using namespace std;
#define INF 20000
int needed[100009], possible[100009];
int n, m, A[109], C[109], T;
int i, j, k, x, y, z, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(possible, 0, sizeof(possible));
        cin >> n >> m;
        for (j = 1; j <= n; j++) cin >> A[j];
        for (j = 1; j <= n; j++) cin >> C[j];
        for (j = 1; j <= n; j++)
        {
            needed[0] = 0;
            for (k = 1; k <= m; k++)
            {
                if (possible[k]) needed[k] = 0;
                else needed[k] = INF;
            }
            for (k = 1; k <= m; k++)
            {
                if (k - A[j] >= 0 ) needed[k] = min( needed[k], needed[k-A[j] ]+1 );
                //if (needed[k] < INF) needed[k+A[i] ] = min( needed[k+A[j]], needed[k]+1 );
                if (needed[k] <= C[j]) possible[k] = 1;
            }
            //for (k = 0; k <= m; k++) cout << needed[k] << " ";
            //cout << endl;
        }
        ans = 0;
        for (j = 1; j <= m; j++) if (possible[j]) ans++;
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
