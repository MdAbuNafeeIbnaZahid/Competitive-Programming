#include <bits/stdc++.h>
using namespace std;
#define SIZE 59
long long w, d, wAr[SIZE], dAr[SIZE];
long long a, b, c,  e, f, g, h, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        ans = 0;
        memset(wAr, 0, sizeof(wAr));
        memset(dAr, 0, sizeof(dAr));
        cin >> w >> d;
        if (w+d==0) return 0;
        for (a = 1; a <= w; a++)
        {
            scanf("%lld", &h);
            wAr[h]++;
        }
        for (a = 1; a <= d; a++)
        {
            scanf("%lld", &h);
            dAr[h]++;
        }
        for (a = 0; a < SIZE; a++)
        {
            ans += a*max( wAr[a], dAr[a] );
        }
        cout << ans << endl;
    }
    return 0;
}
