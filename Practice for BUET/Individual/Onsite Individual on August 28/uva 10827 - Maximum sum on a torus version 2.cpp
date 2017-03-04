#include <bits/stdc++.h>
using namespace std;
#define SIZE 89
long long grid[SIZE][SIZE], contColSum[SIZE][SIZE][SIZE], workAr[SIZE], invertedAr[SIZE];
long long kadane[SIZE], kadane2[SIZE], maxSub;
long long N, ans, testCases, sum;
long long a, b, c, d, e, f, g, h, i;
long long fit(long long a)
{
    if ( (a+N)%N ) return (a+N)%N;
    return N;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        ans = 0;
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            for (c = 1; c <= N; c++)
            {
                scanf("%lld", &grid[b][c]);
            }
        }
        for (b = 1; b <= N; b++) // column
        {
            for (c = 1; c <= N; c++) // start row
            {
                contColSum[b][c][0] = 0;
                for (d = 1; d <= N; d++) // span
                {
                    contColSum[b][c][d] = contColSum[b][c][d-1] + grid[ fit(c+d-1) ][b];
                }
            }
        }
        for (b = 1; b <= N; b++) // start row
        {
            for (c = 1; c <= N; c++) // span
            {
                maxSub = 0;
                sum = 0;
                for (d = 1; d <= N; d++)
                {
                    workAr[d] = contColSum[d][b][c];
                    invertedAr[d] = -workAr[d];
                    sum += workAr[d];
                    kadane[d] = max(kadane[d-1] + invertedAr[d], invertedAr[d]);
                    maxSub = max(maxSub, kadane[d]);
                    kadane2[d] = max(kadane2[d-1]+workAr[d], workAr[d]);
                    ans = max(ans, kadane2[d]);
                }
                ans = max(ans, sum+maxSub);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

