#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
#define MOD 1000003
bool mark[SIZE];
long long T, n, k, i, j, ans, x, y;
long long fact[SIZE];
int egcd(long long a, long long b, long long &x, long long &y)
{
    if (a==0)
    {
        x = 0;
        y = 1;
        return b;
    }
    long long d, x1, y1;
    d = egcd(b%a, a, x1, y1);
    x = y1 - x1 * (b/a);
    y = x1;
    return d;
}
int main()
{
    freopen("input.txt", "r", stdin);
    fact[0] = 1;
    for (i = 1; i < SIZE; i++) fact[i] = i;
    for (i = 1; i < SIZE; i++) fact[i] = ((fact[i]%MOD) * (fact[i-1]%MOD))%MOD;
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lld %lld", &n, &k);
        ans = fact[n];
        egcd(fact[k]%MOD, MOD, x, y);
        x = (x+MOD)%MOD;
        ans = ((ans%MOD)*(x%MOD))%MOD;
        egcd(fact[n-k]%MOD, MOD, x, y);
        x = (x+MOD)%MOD;
        ans = ((ans%MOD)*(x%MOD))%MOD;
        printf("Case %lld: %lld\n", i, ans);
    }
    return 0;
}
