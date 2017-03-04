#include <bits/stdc++.h>
using namespace std;
long long bitCount(long long num)
{
    num++;
    long long a, b, c, d, e, f, g, ret = 0, div = 2, rem;
    for (a = 0; a <= 40; a++)
    {
        ret += (num/div) * (div/2);
        rem = num%div;
        ret += max( (num%div) - (div/2), 0LL );
        div *= 2;
    }
    return ret;
}
long long a, b, c, d, e, f, kase, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        kase++;
        scanf("%lld %lld", &a, &b);
        if (a+b==0)
        {
            return 0;
        }
        ans = bitCount(b) - bitCount(a-1);
        printf("Case %lld: %lld\n", kase, ans);
    }
    return 0;
}
