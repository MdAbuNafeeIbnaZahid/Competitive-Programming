#include <bits/stdc++.h>
using namespace std;
long long n, tot;
long long a, b, c, d, e, f, g, h;
double ans;
int main()
{
    cin >> n;
    for (a = 1; a <=n; a++)
    {
        scanf("%lld", &b);
        tot+=b;
    }
    ans = (double)tot/n;
    //cout << "ans = " << ans << endl;
    //cout << ans-(long long)ans << endl;
    if ( (ans-(long long)ans)  <= 0.5) cout << (long long)ans;
    else cout << ceil(ans);
    return 0;
}
