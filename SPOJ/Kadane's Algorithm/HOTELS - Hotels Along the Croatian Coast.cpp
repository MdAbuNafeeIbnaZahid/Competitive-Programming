#include <bits/stdc++.h>
using namespace std;
#define SIZE 300009
long long N, M, ar[SIZE], i, j, k, start, finish, ans, cur = 0;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    ar[0] = 0;
    for (i = 1; i <= N; i++)
    {
        scanf("%lld", &ar[i]);
    }
    for (i = 1; i <= N; i++)
    {
        ar[i] += ar[i-1];
    }
    start = 0;
    ans = 0;
    for (i = 1; i <= N; i++)
    {
        cur = ar[i] - ar[start];
        while(cur > M)
        {
            start++;
            cur = ar[i] - ar[start];
        }
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
