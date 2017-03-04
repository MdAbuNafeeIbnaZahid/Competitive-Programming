#include <bits/stdc++.h>
using namespace std;
#define SIZE 3009
double dp[SIZE][SIZE], x[SIZE], y[SIZE], ans;
long long n;
long long a, b, c, d, e, f, g, h;
double dist(long long i, long long j)
{
    double ret = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
    return ret;
}
double bitPathDist(long long i, long long j)
{
    long long a, b, c, d, e, f, g;
    if ( dp[i][j] == -1 )
    {
        if (j<i-1) dp[i][j] = bitPathDist(i-1, j) + dist(i-1, i);
        else if ( j==i-1 )
        {
            dp[i][j] = bitPathDist(i-1, 1) + dist(i, 1);
            for (a = 2; a <= i-2; a++)
            {
                dp[i][j] = min(dp[i][j], bitPathDist(i-1, a)+dist(i, a) );
            }
        }
    }
    return dp[i][j];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%lld", &n) > 0)
    {
        for (a = 1;  a <= n; a++)
        {
            scanf("%lf %lf", &x[a], &y[a]);
        }
        if (n<2)
        {
            printf("0.00\n");
            continue;
        }
        for (a = 0; a <= n+9; a++)
        {
            for (b = 0; b <= n+9; b++)
            {
                dp[a][b] = -1;
            }
        }
        dp[2][1] = dist(2, 1);
        for (a = 3; a <= n; a++)
        {
            for (b = 1; b < a; b++)
            {
                bitPathDist(a, b);
            }
        }
        ans = bitPathDist(n, 1) + dist(n,1);
        for (a = 2; a < n; a++)
        {
            ans = min(ans, bitPathDist(n, a) + dist(n, a) );
        }
        printf("%0.2lf\n", ans);
    }
    return 0;
}
