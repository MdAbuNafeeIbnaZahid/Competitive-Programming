#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i, target;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        scanf("%lld %lld %lld", &n, &m, &k);
        if (n+m+k==0) return 0;
        target = n/2 + 1;
        i = n-m-k;
        if ( target-m > i )
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", max(target-m, 0LL) );
        }
    }
    return 0;
}
