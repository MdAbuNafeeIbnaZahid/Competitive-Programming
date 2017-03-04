#include <bits/stdc++.h>

int main()
{
    double n, m, a;

    long long ans;

    scanf("%lf %lf %lf", &n, &m, &a);

    ans = ceil(n/a) * ceil(m/a);

    printf("%lld", ans);

    return 0;
}
