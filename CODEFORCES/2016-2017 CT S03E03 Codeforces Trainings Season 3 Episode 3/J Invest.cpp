#include <bits/stdc++.h>
using namespace std;
long long M, P[19];
long long a, b, c, d, e, f, g, n, ans = 0, si, ei;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> M;
    //P[0] = -1;
    for (a = 1; a <= 12; a++)
    {
        cin >> P[a];
    }
    for (a = 1; a <= 12; a++)
    {
        for (b = a+1; b <= 12; b++)
        {
            n = M/P[a];
            //if ( P[b] > M ) continue;
            if ( n*(P[b]-P[a]) > ans )
            {
                ans = n*(P[b]-P[a]);
                si = a;
                ei = b;
            }
            else if ( n*(P[b]-P[a]) == ans && P[a] < P[si] )
            {
                ans = n*(P[b]-P[a]);
                si = a;
                ei = b;
            }
        }
    }
    if ( ans == 0 )
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << si << " " << ei << " " << ans;
    }
    return 0;
}
