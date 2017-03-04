#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, aArray[SIZE], valueArray[SIZE], dp[SIZE];
long long a, b, c;
long long dpF(long long n)
{
    if (n <= 0) return 0;
    if ( dp[n] != -1 )
    {
        return dp[n];
    }
    return max( dpF(n-1), dpF(n-2)+valueArray[n] );
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aArray[a]);
        valueArray[ aArray[a] ] += aArray[a];
    }
    memset(dp, -1, sizeof(dp));
    for (a = 0; a < SIZE; a++)
    {
        dp[a] = dpF(a);
    }
    cout << dpF(SIZE-1);
    return 0;
}
