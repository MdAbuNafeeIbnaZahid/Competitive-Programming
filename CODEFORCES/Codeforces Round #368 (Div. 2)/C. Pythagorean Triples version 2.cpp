#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, ans1, ans2, n;
int main()
{
    cin >> n;
    if (n%2)
    {
        ans1 = n*n/2;
        ans2 = n*n/2+1;
    }
    else
    {
        ans1 = (n/2)*(n/2)-1;
        ans2 = (n/2)*(n/2)+1;
    }
    if (ans1<=0 || ans2<=0) cout << -1;
    else cout << ans1 << " " << ans2;
    return 0;
}
