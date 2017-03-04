#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long a, b, c, d, e, f, grundyVal[SIZE], num, xorVal;
long long T, n;
long long grundyF(long long n)
{
    set<long long> prevGrund;
    long long a, b, c, d, e, f, g;
    if ( grundyVal[n] == -1 )
    {
        for (a = 1; a <= n/2; a++)
        {
            if ( a != n-a )
            {
                prevGrund.insert( grundyF(a) ^ grundyF(n-a) );
            }
        }
        for (a = 0; ; a++)
        {
            if ( prevGrund.find( a ) == prevGrund.end() )
            {
                grundyVal[n] = a;
                break;
            }
        }
    }
    return grundyVal[n];
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset( grundyVal, -1, sizeof(grundyVal) );
    grundyVal[0] = 0;
    grundyVal[1] = 0;
    grundyVal[2] = 0;
    for (a = 3; a <= 10000; a++)
    {
        grundyF(a);
        //cout << "a = " << a << "-> " << grundyVal[a] << endl;
    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        scanf("%lld", &n);
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &num);
            xorVal ^= grundyF(num);
        }
        if (xorVal) printf("Case %lld: Alice\n", a);
        else printf("Case %lld: Bob\n", a);
    }
    return 0;
}
