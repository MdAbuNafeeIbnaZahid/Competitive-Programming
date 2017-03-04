#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, aArray[SIZE], taken[SIZE];
long long b, c, d, e, f, g, ans;
int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;
    for (b = 0; b < n; b++)
    {
        scanf("%lld", &aArray[b]);
    }
    sort(aArray, aArray+n);
    ans = 0;
    for (b = 0; b < n; b++)
    {
        if ( aArray[b] >= ans+1 )
        {
            ans++;
        }
    }
    cout << ans+1 << endl;
    return 0;
}
