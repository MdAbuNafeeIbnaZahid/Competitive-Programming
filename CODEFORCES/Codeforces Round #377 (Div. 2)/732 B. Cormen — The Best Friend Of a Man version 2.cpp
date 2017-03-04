#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long n, k;
long long aAr[SIZE], bAr[SIZE];
long long a,b, c, d, e, f, g, h, leftIdx, rightIdx, needToAdd, ans;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    bAr[0] = k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        bAr[a] = aAr[a];
    }
    bAr[n+1] = k;

    for (a = 1; a < n; a++)
    {
        if ( bAr[a]+bAr[a+1] < k )
        {
            needToAdd = k - bAr[a] - bAr[a+1];
            ans += needToAdd;
            bAr[a+1] += needToAdd;
        }
    }

    cout << ans << endl;
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", bAr[a]);
    }
    return 0;
}
