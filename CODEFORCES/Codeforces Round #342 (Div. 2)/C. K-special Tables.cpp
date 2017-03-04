#include <bits/stdc++.h>
using namespace std;

#define SIZE 505

int n, k, ans = 0, i, j, a, b, ar[SIZE][SIZE], c, d, f, e;

int main()
{
    cin >> n >> k;

    a = (n*n) - (n-k);
    for (i = 1; i <= n; i++)
    {
        ans += a;
        a -= (n-k+1);
    }

    c = 0;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b < k; b++)
        {
            ar[a][b] = ++c;
        }
    }

    for (a = 1; a <= n; a++)
    {
        for (b = k; b <= n; b++)
        {
            ar[a][b] = ++c;
        }
    }

    cout << ans << "\n";


    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= n; b++)
        {
            printf("%d ", ar[a][b]);
        }
        printf("\n");
    }




    return 0;
}
