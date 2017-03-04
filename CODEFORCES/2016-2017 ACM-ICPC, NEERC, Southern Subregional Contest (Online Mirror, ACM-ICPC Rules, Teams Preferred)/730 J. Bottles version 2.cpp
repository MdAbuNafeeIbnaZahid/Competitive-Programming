#include <bits/stdc++.h>
using namespace std;
#define SIZE 102
#define myInf 999999
#define myMinInf (-999999)
int n, aAr[SIZE], bAr[SIZE], k, t;
int a, b, c, d, e, f, g, h;
int dpAr[SIZE][SIZE][SIZE*SIZE];
// dp states are serially    index upto which I have calculated, number of bottles, total volume
// value of dp is the maximum( sum of ai of taken bottles )
// I have tried to maximize sum of ai
int totalLiq, maxA;
int main()
{
    memset(dpAr, -1, sizeof(dpAr) );
    // base case
    dpAr[0][0][0] = 0;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        totalLiq += aAr[a];
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &bAr[a]);
    }
    for (a = 0; a < n; a++)
    {
        for (b = 0; b <= n; b++)
        {
            for (c = 0; c < SIZE*SIZE; c++)
            {
                dpAr[a+1][b][c] = max(dpAr[a][b][c], dpAr[a+1][b][c]);
            }
        }

        for (b = 0; b < n; b++)
        {
            for (c = 0; c < SIZE*SIZE; c++)
            {
                if ( dpAr[a][b][c] == -1  || c+bAr[a+1] >= SIZE*SIZE )
                {
                    continue;
                }
                dpAr[a+1][ b+1 ][ c+bAr[a+1] ]
                = max(dpAr[a+1][ b+1 ][ c+bAr[a+1] ], dpAr[a][b][c]+aAr[a+1]);
            }
        }

    }
    for (b = 1; b <= n; b++)
    {
        for (c = totalLiq; c < SIZE*SIZE; c++)
        {
            maxA = max(maxA, dpAr[n][b][c]);
        }
        if (maxA>0)
        {
            k = b;
            break;
        }
    }
    t = totalLiq - maxA;
    cout << k << " " << t << endl;
    return 0;
}
