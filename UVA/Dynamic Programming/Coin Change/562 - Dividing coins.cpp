#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
bool mark[109][SIZE];
int m, n, mAr[109], ans, total, pick;
int i, j, k, a, b, c;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        memset(mark, false, sizeof(mark));
        total = 0;
        cin >> m;
        for (j = 1; j <= m; j++)
        {
            scanf("%d", &mAr[j]);
        }
        for (j = 1; j <= m; j++) total+=mAr[j];
        mark[0][0] = true;
        for ( j = 1; j <= m; j++)
        {
            for (k = 0; k <= total; k++)
            {
                mark[j][k] = mark[j-1][k];
                if ( k-mAr[j] >= 0 ) mark[j][k] |= mark[j-1][k-mAr[j] ];
            }
        }
        for (pick = total/2; pick >= 0 && !mark[m][pick]; pick--){}
//        cout << "total = " << total << endl;
//        cout << "pick = " << pick << endl;
        ans = total - 2*pick;
        cout << ans << endl;
    }
    return 0;
}
