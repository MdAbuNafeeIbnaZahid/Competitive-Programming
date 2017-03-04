#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n, a;
vector<int> x;
int b, c, d, e, f, g, h, ans = INT_MAX, xi, len;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> a;
    for (b = 1; b <= n; b++)
    {
        scanf("%lld", &xi);
        x.push_back(xi);
    }
    sort(x.begin(), x.end());
    len = x.size();
    if (n <= 1)
    {
        cout << 0;
        return 0;
    }
    ans = min(ans, abs(x[n-2]-x[0]) + min( abs(a-x[0]), abs(a-x[n-2]) ) );
    ans = min(ans, abs(x[n-1]-x[1]) + min( abs(a-x[1]), abs(a-x[n-1]) ) );
    cout << ans;
    return 0;
}
