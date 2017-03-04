#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long n, k, ci[SIZE];
long long a, b, c, d, e, f, g, h, myLcm;
long long gcd(long long a, long long b)
{
    if ( a>b ) return gcd(b, a);
    if (a==0) return b;
    return gcd(b%a, a);
}
long long gcd2(long long a, long long b)
{
    long long minN, maxN, temp;
    minN = min(a, b);
    maxN = max(a, b);
    while(minN > 0)
    {
        temp = maxN%minN;
        maxN = minN;
        minN = temp;
    }
    return maxN;
}
long long lcm(long long a, long long b)
{
    return a*b/gcd2(a, b);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ci[a]);
    }
    myLcm = 1;
    //sort(ci+1, ci+n+1);
    for (a = 1; a <= n ; a++)
    {
        myLcm = gcd2( k, lcm(myLcm, ci[a]) );
    }
    //cout << "k = " << k << endl;
    if (myLcm == k  ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
