#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, aAr[SIZE], temp;
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= n-1; b++)
        {
            if ( aAr[b] > aAr[b+1] )
            {
                temp = aAr[b];
                aAr[b] = aAr[b+1];
                aAr[b+1] = temp;
                printf("%lld %lld\n", b, b+1);
            }
        }
    }
    return 0;
}
