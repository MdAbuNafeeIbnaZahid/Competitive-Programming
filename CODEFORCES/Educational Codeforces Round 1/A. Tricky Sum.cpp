#include <bits/stdc++.h>
using namespace std;

long long i, j,k, m, n, t, ans, p;

int main()
{
    scanf("%I64d", &t);
    for (i = 1; i <= t; i++)
    {
        ans = p = 0;
        scanf("%I64d", &n);
        m = n;
        while(m)
        {
            m >>= 1;
            p++;
        }
        //p--;
        //printf("\n p = %I64d \n", p);
        ans = n*(n+1)/2 - 2 * ((1 << p)-1);
        printf("%I64d\n", ans);
    }


    return 0;
}
