#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
int N, ar[SIZE];
int tankSum, bucketSum;
vector<int> tank, bucket;
int i, j, a, b, c;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        tankSum = bucketSum = 0;
        tank = vector<int>();
        bucket = vector<int>();
        cin >> N;
        if (N==0) return 0;
        for (i = 0; i < N; i++)
        {
            scanf("%d", &ar[i]);
        }
        bucketSum = tankSum = ar[0];
        for (i = 1; i < N; i++)
        {
            bucketSum = max( bucketSum+ar[i], ar[i] );
            tankSum = max(tankSum, bucketSum);
        }
        if ( tankSum <= 0 ) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n", tankSum);
    }
    return 0;
}
