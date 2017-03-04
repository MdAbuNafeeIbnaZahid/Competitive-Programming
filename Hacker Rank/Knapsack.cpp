#include <bits/stdc++.h>
using namespace std;
#define SIZE 2009
long long T, n, k, in[SIZE];
bool reachable[SIZE];
long long i, j, a, b, c, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(reachable, false, sizeof(reachable));
        reachable[0] = true;
        cin >> n >> k;
        for (j = 1; j <= n; j++)
        {
            scanf("%lld", &in[j]);
        }
        for (j = 1; j <= n; j++)
        {
            for (a = 0; a+in[j] <= k; a++)
            {
                if ( reachable[a] )  reachable[ a+in[j] ] = true;
            }
        }

        for (ans = k; !reachable[ans]; ans--) {};
        cout << ans << endl;
    }
    return 0;
}
