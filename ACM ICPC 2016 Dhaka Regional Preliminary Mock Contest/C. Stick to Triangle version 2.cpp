#include <bits/stdc++.h>
using namespace std;
long long T, N, X, Y, Z;
long long a,b,c, d, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> N;
        for (X = 1; X <= N; X++)
        {
            Y = X;
            Z = min(N - X - Y, N/2);
            Y = max(X, N-X-Z);
            if ( (X+Y+Z==N) && (X<=Y) && (Y<=Z) )
            {
                ans += ( max(Y,Z) - min(Y,Z) + 2 )/2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
