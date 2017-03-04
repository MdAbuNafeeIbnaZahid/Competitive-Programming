#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, n, xArray[SIZE], totMin, numerator, denominator;
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        totMin = 0;
        numerator = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &xArray[b]);
        }
        for (b = 1; b <= n; b++)
        {
            if ( xArray[b] < 0 ) totMin++;
            numerator += abs(xArray[b]);
        }
        denominator = n - totMin;
        for (b = 2; b <= min(denominator, numerator); b++)
        {
            while ( denominator%b==0 && numerator%b==0 )
            {
                denominator /= b;
                numerator /= b;
            }
        }
        cout << "Case " << a << ": ";
        if (denominator ==  0) cout << "inf" << endl;
        else cout << numerator << "/" << denominator << endl;
    }
    return 0;
}
