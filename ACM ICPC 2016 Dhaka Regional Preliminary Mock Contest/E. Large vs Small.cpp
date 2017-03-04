#include <bits/stdc++.h>
using namespace std;
long long testCases, Y, Z;
double num, maxUpto, minUpto, ans;
long long a, b, c;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        scanf("%lf", &num);
        if (a == 1)
        {
            maxUpto = num;
            minUpto = num;
        }
        maxUpto = max(maxUpto, num);
        minUpto = min(minUpto, num);
        ans = maxUpto/minUpto;
        printf("Case %lld: %0.2lf\n", a, ans);
    }
    return 0;
}
