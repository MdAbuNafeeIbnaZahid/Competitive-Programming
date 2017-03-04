#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long n, aAr[SIZE], ai, ans = 1;
long long b, c, d, e, f;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (b = 1; b <= n; b++)
    {
        scanf("%lld", &ai);
        if (ai == 0){}
        else if (ai%2==0) ans = !ans;
        printf("%lld\n", ans+1);
    }
    return  0;
}

