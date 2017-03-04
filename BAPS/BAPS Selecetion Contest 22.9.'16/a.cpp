#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, cal;
long long T, K, N;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%lld %lld", &K, &N);
        printf("Case %lld:\n", a);
        if ( K == 0 )
        {
            printf("%lld\n", 3*N/9);
            printf("%lld\n", 4*N/9);
            printf("%lld\n", 2*N/9);
        }
        else
        {
            cal = N/2;
            printf("%lld\n", cal*3);
            printf("%lld\n", cal*4);
            printf("%lld\n", cal*9);
        }
    }
    return 0;
}
