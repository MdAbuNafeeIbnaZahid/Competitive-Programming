#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long grid[SIZE][SIZE], cumSumRow[SIZE][SIZE], cumSumCol[SIZE][SIZE];
long long n, m, ans;
long long a, b, c, d, e, f, g;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            scanf("%lld", &grid[a][b]);
            cumSumRow[a][b] = cumSumRow[a][b-1] + grid[a][b];
            cumSumCol[a][b] = cumSumCol[a-1][b] + grid[a][b];
        }
    }
//    cout << "cumSumRow" << endl;
//    for (a = 1; a <= n; a++)
//    {
//        for (b = 1; b <= m; b++)
//        {
//            cout << cumSumRow[a][b] << " ";
//        }
//        cout << endl;
//    }
//    cout << "cumSumCol" << endl;
//    for (a = 1; a <= n; a++)
//    {
//        for (b = 1; b <= m; b++)
//        {
//            cout << cumSumCol[a][b] << " ";
//        }
//        cout << endl;
//    }
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            if ( grid[a][b] )
            {
                continue;
            }
//            cout << "a = " << a << ", b = " << b << endl;
//            cout << "ans = " << ans << endl;
            ans += (cumSumRow[a][b]>0);
//            cout << "ans = " << ans << endl;
            ans += (cumSumCol[a][b]>0);
//            cout << "ans = " << ans << endl;
            ans += ( (cumSumRow[a][m]-cumSumRow[a][b])>0);
//            cout << "ans = " << ans << endl;
            ans += ( (cumSumCol[n][b]-cumSumCol[a][b])>0);
//            cout << "ans = " << ans << endl;
            //cout << "ans = " << ans << endl;
        }
    }
    cout << ans ;
    return 0;
}
