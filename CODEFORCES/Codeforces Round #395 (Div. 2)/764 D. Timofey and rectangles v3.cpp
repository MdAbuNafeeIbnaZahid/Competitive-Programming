#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f;
long long n, x11, x22, y11, y22;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    cout << "YES" << endl;
    for ( a =1 ; a <= n; a++ )
    {
        scanf("%lld %lld %lld %lld", &x11, &y11, &x22, &y22);
        x11 = abs(x11);
        y11 = abs(y11);
        long long col = 2*(x11%2) + (y11%2) + 1;
        printf("%lld\n", col);
    }
    return 0;
}
