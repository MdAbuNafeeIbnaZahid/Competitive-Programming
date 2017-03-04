#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, c, tAr[SIZE], ans;
long long a, b, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> c;
    for (a = 1; a <= n;a++)
    {
        scanf("%lld", &tAr[a]);
    }
    ans = 1;
    for (a = n-1; a >= 1; a--)
    {
        if ( tAr[a+1]-tAr[a] > c ) break;
        else ans++;
    }
    cout << ans;
    return 0;
}
