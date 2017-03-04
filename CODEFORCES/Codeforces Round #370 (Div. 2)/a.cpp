#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, ar[SIZE], ans[SIZE];
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ar[a]);
    }
    for (a = 1; a <= n-1; a++)
    {
        ans[a] = ar[a] + ar[a+1];
    }
    ans[n] = ar[n];
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", ans[a]);
    }
    return 0;
}
