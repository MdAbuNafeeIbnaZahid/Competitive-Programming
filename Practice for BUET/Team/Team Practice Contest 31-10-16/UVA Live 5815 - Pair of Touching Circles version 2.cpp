#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, H, W;
long long preCalc[SIZE][SIZE], cumSum[SIZE][SIZE], ansAr[SIZE][SIZE];
long long a, b, c, d, e, f, g, x, y, ans, lowX, highX, lowY, highY, r;
long long difX, difY;
long long ifFullSq(long long n)
{
    long long a, b, c;
    a =  sqrt(n*1.0+0.5);
    return a*a==n;
}
long long findCumSum(long long row, long long col )
{
    if ( row < 0 || col < 0 )
    {
        return 0;
    }
    return cumSum[row][col];
}
int main()
{
    freopen("input.txt", "r", stdin);
    for (x = 0; x < SIZE; x++)
    {
        for (y = 0; y < SIZE; y++)
        {
            if ( ifFullSq(x*x+y*y) )
            {
                r = sqrt(x*x+y*y+0.5);
                for (a = 1; a < r; a++)
                {
                    lowX = min(-a, x-(r-a) );
                    lowY = min(-a, y-(r-a) );
                    highX = max(x+(r-a), a);
                    highY = max(y+(r-a), a);
                    difX = highX-lowX;
                    difY = highY-lowY;
                    if ( difX>=SIZE || difY>=SIZE ) continue;
                    if (x==0 || y==0)
                    {
                        preCalc[difX][difY]++;
                    }
                    else
                    {
                        preCalc[difX][difY] += 2;
                    }
                }
            }
        }
    }
    for (a = 1; a < SIZE; a++)
    {
        for (b = 1; b < SIZE; b++)
        {
            ansAr[a][b] = ansAr[a-1][b] + ansAr[a][b-1] - ansAr[a-1][b-1] + preCalc[a][b];
            ansAr[a][b] += ansAr[a-1][b];
            ansAr[a][b] += ansAr[a][b-1];
        }
    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        scanf("%lld %lld", &H, &W);
        for (b = 0; b <= W; b++)
        {
            for (c = 0; c <= H; c++)
            {
                ans += preCalc[b][c]*(W-b+1)*(H-c+1);
            }
        }
        //cout << ans << endl;
        printf("Case %lld: %lld\n", a, ans);
    }
    return 0;
}
