#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long N, input[SIZE][SIZE], sumArray[SIZE][SIZE], ans;
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &input[a][b]);
        }
    }
    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= N; b++)
        {
            sumArray[a][b] = sumArray[a-1][b] + sumArray[a][b-1] + input[a][b] - sumArray[a-1][b-1];
        }
    }

    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= N; b++)
        {
            for (c = a+1; c <= N; c++)
            {
                for (d = b+1; d <= N; d++)
                {
                    ans = max(ans, sumArray[c][d] - sumArray[a-1][d] - sumArray[c][b-1] + sumArray[a-1][b-1]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
