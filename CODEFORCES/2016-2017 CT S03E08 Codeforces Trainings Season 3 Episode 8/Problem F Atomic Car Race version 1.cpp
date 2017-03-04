#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long n, aAr[SIZE];
double b, r, v, e, f;
long long i, j, k, x, y, z;
double timeAr[SIZE], velForOneK, dp[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> n;
        if (n==0) return 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%lld", &aAr[i]);
        }
        cin >> b;
        cin >> r >> v >> e >> f;
        timeAr[0] = 0;
        for (i = 1; i <= aAr[n]; i++)
        {
            if ( i-1 < r )
            {
                velForOneK = v-f*(r-i+1);
            }
            else
            {
                velForOneK = v - e*(i-1-r);
            }
            timeAr[i] = timeAr[i-1] + (1/velForOneK);
        }
        dp[0] = 0;
        for (i = 1; i <= n; i++)
        {
            dp[i] = timeAr[ aAr[i] ];
            for (j = i-1; j >= 1; j--)
            {
                dp[i] = min( dp[i], dp[j]+b+timeAr[ aAr[i]-aAr[j] ] );
            }
        }
        //cout << dp[n] << endl;
        printf("%0.6lf\n", dp[n]);
    }
    return 0;
}
