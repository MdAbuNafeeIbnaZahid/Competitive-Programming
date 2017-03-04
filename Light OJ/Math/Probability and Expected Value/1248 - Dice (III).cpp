#include <bits/stdc++.h>
using namespace std;
long long T, n;
double ans;
long long a, b, c, d, e, f, g;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n;
        ans = 0;
        for (b = 1; b <= n; b++)
        {
            ans += (double)n/(n-b+1);
        }
        printf("Case %lld: %0.7lf\n", a, ans);
    }
    return 0;
}
