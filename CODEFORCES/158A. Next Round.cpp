#include <bits/stdc++.h>

int main()
{
    long long ar[200] = {0}, n, k, i, j,  ans = 0, pos = 1;

    scanf("%I64d %I64d", &n, &k);

    for (i = 1; i <= n; i++)
    {
        scanf("%I64d", &ar[i]);
    }

    for (i = 1; i <= k ; i++)
    {
//        if (ar[i] < ar[i-1])
//        {
//            pos++;
//        }
//
//        printf("\n i = %lld, pos = %lld\n", i, pos);

        if (ar[i] > 0)
        {
            ans++;
        }
    }

    for (; ar[i] == ar[i-1] && i <= n && ar[i] > 0; i++)
    {
        ans++;
    }



    printf("%I64d", ans);

    return 0;
}
