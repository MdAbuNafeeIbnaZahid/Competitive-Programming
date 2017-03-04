#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long N, input[SIZE][SIZE], sumArray[SIZE][SIZE], ans;
long long height, oneDArray[SIZE], tankSum, bucketSum;
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    ans = INT_MIN;
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
        for (height = 1; height <= N-a+1; height++)
        {
            for (b = 1; b <= N; b++)
            {
                oneDArray[b]
                = sumArray[b][a+height-1] - sumArray[b-1][a+height-1] - sumArray[b][a-1] + sumArray[b-1][a-1];
            }
            //tankSum = 0;
            bucketSum = INT_MIN;
            for (b = 1; b <= N; b++)
            {
                bucketSum = max(oneDArray[b], bucketSum+oneDArray[b]);
                ans = max(bucketSum, ans);
            }
            //ans = max(bucketSum, ans);
        }
    }
    cout << ans << endl;
}
