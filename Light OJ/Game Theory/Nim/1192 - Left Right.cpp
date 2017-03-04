#include <bits/stdc++.h>
using namespace std;
long long T, k, s, e, a, b, c, d, xorVal;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        cin >> k;
        for (b = 1; b <= k; b++)
        {
            scanf("%lld %lld", &s, &e);
            xorVal ^= (e-s-1);
        }
        printf("Case %lld: ", a);
        if (xorVal == 0)
        {
            printf("Bob\n");
        }
        else printf("Alice\n");
    }
    return 0;
}
