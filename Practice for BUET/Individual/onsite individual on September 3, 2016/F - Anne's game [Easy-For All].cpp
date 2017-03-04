#include <bits/stdc++.h>
using namespace std;
#define MOD  2000000011
long long N, n;
long long a, b, c, d, e, f, g, ans;
long long myPow(long long n)
{
    long long a, b, c, d, e, f, ret = 1;
    if (n==1) return 1;
    //if (n==2) return 1;
    for (a = 1; a <= n-2; a++)
    {
        ret = ((ret%MOD) * (n%MOD) )%MOD;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (a= 1; a <=N; a++)
    {
        scanf("%lld", &n);
        ans = myPow(n);
        cout << "Case #" << a << ": " << ans << endl;
    }
    return 0;
}
